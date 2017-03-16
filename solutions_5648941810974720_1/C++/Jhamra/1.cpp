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

char S[3000],N[][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int A[3000],B[400];
multiset<int> Set;

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        gets(S+1);
        int n=strlen(S+1);

        for(int i=1;i<=n;i++)B[(int)S[i]]++;

        while(B[(int)'U'])
        {
            B[(int)'F']--;
            B[(int)'O']--;
            B[(int)'U']--;
            B[(int)'R']--;
            Set.insert(4);
        }

        while(B[(int)'F'])
        {
            B[(int)'F']--;
            B[(int)'I']--;
            B[(int)'V']--;
            B[(int)'E']--;
            Set.insert(5);
        }

        while(B[(int)'G'])
        {
            B[(int)'E']--;
            B[(int)'I']--;
            B[(int)'G']--;
            B[(int)'H']--;
            B[(int)'T']--;
            Set.insert(8);
        }

        while(B[(int)'X'])
        {
            B[(int)'S']--;
            B[(int)'I']--;
            B[(int)'X']--;
            Set.insert(6);
        }

        while(B[(int)'W'])
        {
            B[(int)'T']--;
            B[(int)'W']--;
            B[(int)'O']--;
            Set.insert(2);
        }

        while(B[(int)'S'])
        {
            B[(int)'S']--;
            B[(int)'E']--;
            B[(int)'V']--;
            B[(int)'E']--;
            B[(int)'N']--;
            Set.insert(7);
        }

        while(B[(int)'I'])
        {
            B[(int)'N']--;
            B[(int)'I']--;
            B[(int)'N']--;
            B[(int)'E']--;
            Set.insert(9);
        }

        while(B[(int)'Z'])
        {
            B[(int)'Z']--;
            B[(int)'E']--;
            B[(int)'R']--;
            B[(int)'O']--;
            Set.insert(0);
        }

        while(B[(int)'N'])
        {
            B[(int)'O']--;
            B[(int)'N']--;
            B[(int)'E']--;
            Set.insert(1);
        }

        while(B[(int)'R'])
        {
            B[(int)'T']--;
            B[(int)'H']--;
            B[(int)'R']--;
            B[(int)'E']--;
            B[(int)'E']--;
            Set.insert(3);
        }

        printf("Case #%d: ",cases);
        multiset<int>::iterator it;

        for(it=Set.begin();it!=Set.end();it++)
        {
            printf("%d",*it);
        }
        puts("");
        Set.clear();
    }
}
