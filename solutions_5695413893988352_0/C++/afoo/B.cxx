#include <stdio.h>
#include <string.h>
#include <cstdlib>

//#define abs(i,j) (i>j? (i-j) : (j-i))
int abs(int i, int j) {
    return i>j? i-j:j-i;
}
int mark_c, mark_j;
void count(char *C, char *J, int idx_c, int idx_j, char *ans_c, char *ans_j, int &diff){
//    if (idx_c == strlen(C) && idx_j == strlen(J)) {
    if ( mark_c ==0 && mark_j ==0 ) {
        int new_c = atoi(C);
        int new_j = atoi(J);
        //printf("C [%s] [%d], J[%s] [%d]\n", C,new_c, J, new_j);
        if (diff == -1 || abs(new_c, new_j) < diff ) {
            strcpy(ans_c, C);
            strcpy(ans_j, J);
            diff = abs(new_c-new_j);
        }
        return ;
    }
//    if (idx_c == strlen(C)) {
    if (mark_c==0) {
        for (int i=idx_j;i<strlen(J);i++) {
            if (J[i] == '?') {
                mark_j--;
                for (int j=0;j<10;j++) {
                    J[i] = j+'0';
                    count(C,J,idx_c, i+1, ans_c, ans_j, diff);
                }
                J[i] = '?';
                mark_j++; 
                if (diff==0)
                    return;
            }
        }
        return ;
    }
    for (int i=idx_c;i<strlen(C);i++) {
        if (C[i] == '?') {
            mark_c--;
            for (int j=0;j<10;j++) {
                C[i] = j+'0';
                count(C,J,i+1, idx_j, ans_c, ans_j, diff);
            }
            C[i] = '?'; 
            mark_c++;
            if (diff==0)
                return;
        }
    }
}
int main()
{
    int T;
    char S[2010];
    char C[300];
    char J[300];
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%s %s", C, J);
        //printf("C[%s], J[%s]\n", C,J);
        char  ans_c[50], ans_j[50];
        int diff = -1;
        mark_c =0, mark_j=0;
        for (int i=0;i<strlen(C);i++)
            if (C[i]=='?')
                mark_c ++;
        for (int i=0;i<strlen(J);i++)
            if (J[i]=='?')
                mark_j ++;

        count(C,J,0,0,ans_c, ans_j, diff);
        printf("%s %s\n", ans_c, ans_j);
    }
    return 0;
}


