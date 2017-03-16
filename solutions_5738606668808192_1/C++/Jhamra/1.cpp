#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
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

int A[50],ans=0;
char S[50];

void dfs(int pos,int cnt)
{
    if(ans>=500)return;

    A[pos]=1;

    if(cnt==4)
    {
        int odd=0,even=0;
        for(int i=0;i<=31;i++)
        {
            if(i%2&&A[i])odd++;
            if(i%2==0&&A[i])even++;
        }
        if(odd==even)
        {
            ans++;
            for(int i=0;i<=31;i++)putchar('0'+A[i]);
            puts(S+1);
        }
        A[pos]=0;

        return;
    }

    for(int i=pos+1;i<=30;i++)dfs(i,cnt+1);

    A[pos]=0;
}

int main()
{
    //freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    strcpy(S+1," 3 2 3 2 7 2 3 2 3");

    A[0]=1;
    A[31]=1;

    printf("Case #1:\n");

    for(int i=1;i<=30;i++)
    {
        dfs(i,1);
    }
}
