#include<stdio.h>
#include<string.h>
#include<stdlib.h>



char C[20], J[20];
int l;
int check(int n, char *s){
    for(int i=l-1;i>=0;i--){
        if(s[i] == '?'){
            n /= 10;
            continue;
        }
        int now = n % 10;
        if(s[i] - '0' != now){
            return -1;
        }
        n /= 10;
    }
    return 0;
}
int abs(int b){
    return b > 0 ? b : -b;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca= 1;ca <=T;ca++){

        scanf("%s %s", C, J);

        l = strlen(C);
        int up = 1;
        int minDif = 2147483647;
        int ansc;
        int ansj;
        for(int i=0;i<l;i++)up *= 10;
        for(int c=0;c<up;c++){
            if(check(c, C) == -1)continue;
            for(int j=0;j<up;j++){
                if(check(j, J) == -1)continue;

                if(minDif <= abs(c - j)) continue;

                minDif = abs(c - j);
                ansc = c;
                ansj = j;

            }
        }

        printf("Case #%d: %0*d %0*d\n", ca, l, ansc, l, ansj);
    }
    return 0;
}
