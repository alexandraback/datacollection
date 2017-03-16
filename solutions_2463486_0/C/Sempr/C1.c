#include <stdio.h>
#include <math.h>
#include <string.h>

int ok(int x){
    int r;
    int i,j;
    double fr;
    char s[30];
    fr = (sqrt(x)+0.5);
    r = (int)fr;
    if (r*r!=x) return 0;
    sprintf(s,"%d",x); for (i=0,j=strlen(s)-1;i<j;i++,j--) if (s[i]!=s[j]) return 0;
    sprintf(s,"%d",r); for (i=0,j=strlen(s)-1;i<j;i++,j--) if (s[i]!=s[j]) return 0;
    return 1;
}

int sol(){
    int i,A,B,c;
    scanf("%d %d", &A, &B);
    c = 0;
    for (i=A;i<=B;i++){
        if (ok(i)) c++;
    }
    return c;
}

int main(){
    int cas, T;
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++)
        printf("Case #%d: %d\n", cas, sol());
    return 0;
}

