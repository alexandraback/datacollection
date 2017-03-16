#include<bits/stdc++.h>
#define ll long long

using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int A[6][6];
char S[700006];
int F[700006],B[700006];
vector<int> V[6];

int main()
{
    freopen ("C-small-attempt1.in","r",stdin);
    freopen ("C-small-attempt1.out","w",stdout);

    A[1][1]=1;A[1][2]=2;A[1][3]=3;A[1][4]=4;
    A[2][1]=2;A[2][2]=-1;A[2][3]=4;A[2][4]=-3;
    A[3][1]=3;A[3][2]=-4;A[3][3]=-1;A[3][4]=2;
    A[4][1]=4;A[4][2]=3;A[4][3]=-2;A[4][4]=-1;

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        ll len=getnum(),rrep=getnum(),rep=rrep%4,flag=0;
        if(rrep>=4)rep+=4;
        gets(S+1);
        for(int i=1;i<=rep-1;i++)
        {
            for(int j=1;j<=len;j++)S[i*len+j]=S[j];
        }

        F[0]=1;
        for(int i=1;i<=len*rep;i++)
        {
            int x=S[i]-'i'+2;
            int y=abs(F[i-1]),sign=1;
            if(F[i-1]<0)sign=-1;
            F[i]=sign*A[y][x];
        }

        B[rep*len+1]=1;
        for(int i=len*rep;i>=1;i--)
        {
            int x=S[i]-'i'+2;
            int y=abs(B[i+1]),sign=1;
            if(B[i+1]<0)sign=-1;
            B[i]=sign*A[x][y];
        }

        int ff=0;

        for(int i=1;i<=len*rep;i++)
        {
            if(F[i]==2&&B[i+1]==2)ff=1;
            if(F[i]==4&&B[i+1]==4&&ff==1)flag=1;
        }
        printf("Case #%d: ",cases);
        if(flag)puts("YES");
        else puts("NO");
    }
}
