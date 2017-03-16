#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define lgmax 2500
char reprez[20][20]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[lgmax],c;
int t, ls, nr['Z'+5], num[20];

void scade(int x){
    int lg = strlen(reprez[x]);
    for (int j=0;j<lg;j++)
        nr[reprez[x][j]]-=num[x];
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    for (int ii=1;ii<=t;ii++){
        scanf("%s",s);
        for (c='A';c<='Z';c++)
            nr[c]=0;
        ls=strlen(s);
        for (int i=0;i<ls;i++)
            nr[s[i]]++;
        num[0]=nr['Z']; scade(0);
        num[2]=nr['W']; scade(2);
        num[6]=nr['X']; scade(6);
        num[4]=nr['U']; scade(4);
        num[5]=nr['F']; scade(5);
        num[3]=nr['R']; scade(3);
        num[1]=nr['O']; scade(1);
        num[7]=nr['S']; scade(7);
        num[8]=nr['G']; scade(8);
        num[9]=nr['E']; scade(9);
        printf("Case #%d: ",ii);
        for (int i=0;i<=9;i++)
            for (int j=0;j<num[i];j++)
                printf("%d",i);
        printf("\n");
    }
    return 0;
}
