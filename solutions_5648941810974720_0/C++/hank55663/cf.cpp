#include <bits/stdc++.h>
#define MAX 300
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        char c[2005];
        scanf("%s",c);
        int num[26];
        memset(num,0,sizeof(num));
        for(int i=0;c[i]!=0;i++)
            num[c[i]-'A']++;
        int ans[9];
        memset(ans,0,sizeof(ans));
        ans[0]=num[25];
        num['R'-'A']-=num[25];
        num['O'-'A']-=num[25];
        ans[2]=num['W'-'A'];
        num['O'-'A']-=num['W'-'A'];
        ans[6]=num['X'-'A'];
        num['S'-'A']-=num['X'-'A'];
        num['I'-'A']-=num['X'-'A'];
        ans[8]=num['G'-'A'];
        num['H'-'A']-=num['G'-'A'];
        num['I'-'A']-=num['G'-'A'];
        ans[3]=num['H'-'A'];
        num['R'-'A']-=num['H'-'A'];
        ans[4]=num['R'-'A'];
        num['F'-'A']-=num['R'-'A'];
        num['O'-'A']-=num['R'-'A'];
        ans[1]=num['O'-'A'];
        ans[7]=num['S'-'A'];
        ans[5]=num['F'-'A'];
        num['I'-'A']-=ans[5];
        ans[9]=num['I'-'A'];
        printf("Case #%d: ",t);
        for(int i=0;i<=9;i++)
            while(ans[i]--)
            printf("%d",i);
        printf("\n");


    }
    return 0;
}
/*
0 Z   ero    eorz
2 W
6 X
8 G
3 H
4 R
1 o
7 s
5 f
9 i
*/
