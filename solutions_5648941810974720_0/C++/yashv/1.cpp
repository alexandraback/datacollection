#include<bits/stdc++.h>

#define mod 1000000007
#define inf 1000000009
#define MX 1000001

#define pb push_back
#define mp make_pair
#define ll long long
#define gc getchar
#define vi vector<int>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;
int v(char c)
{
    return int(c-'a');
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\yashvir\\Downloads\\A-large.in","r",stdin);
    freopen("J:\\Downloads\\A-small-attempt0.in","r",stdin);
    //freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int t, i, j, k, n, b[26]={0}, q;
    int m[10]={0};
    char s[2001];
    scanf("%d", &t);
    rep(q, t)
    {
        printf("Case #%d: ", q+1);
        scanf("%s", s);
        for(i=0; s[i]; i++) b[s[i]-'A']++;
        if(b[25]>0)
        {
            b[v('e')]-=b[25];
            b[v('r')]-=b[25];
            b[v('o')]-=b[25];
            m[0]+=b[25];
        }
        if(b[v('w')]>0)
        {
            b[v('t')]-=b[v('w')];
            b[v('o')]-=b[v('w')];
            m[2]+=b[v('w')];
        }
        if(b[v('x')]>0)
        {
            b[v('s')]-=b[v('x')];
            b[v('i')]-=b[v('x')];
            m[6]+=b[v('x')];
        }
        if(b[v('g')]>0)
        {
            b[v('e')]-=b[v('g')];
            b[v('i')]-=b[v('g')];
            b[v('h')]-=b[v('g')];
            b[v('t')]-=b[v('g')];
            m[8]+=b[v('g')];
        }
        if(b[v('t')]>0)
        {
            b[v('r')]-=b[v('t')];
            b[v('e')]-=2*b[v('t')];
            b[v('h')]-=b[v('t')];
            m[3]+=b[v('t')];
        }
        if(b[v('s')]>0)
        {
            b[v('e')]-=2*b[v('s')];
            b[v('v')]-=b[v('s')];
            b[v('n')]-=b[v('s')];
            m[7]+=b[v('s')];
        }
        if(b[v('r')]>0)
        {
            b[v('f')]-=b[v('r')];
            b[v('o')]-=b[v('r')];
            b[v('u')]-=b[v('r')];
            m[4]+=b[v('r')];
        }
        if(b[v('f')]>0)
        {
            b[v('i')]-=b[v('f')];
            b[v('v')]-=b[v('f')];
            b[v('e')]-=b[v('f')];
            m[5]+=b[v('f')];
        }
        if(b[v('o')]>0)
        {
            b[v('n')]-=b[v('o')];
            b[v('e')]-=b[v('o')];
            m[1]+=b[v('o')];
        }
        if(b[v('i')]>0)
        {
            b[v('n')]-=2*b[v('i')];
            b[v('e')]-=b[v('i')];
            m[9]+=b[v('i')];
        }
        //printf("hello\n");
        for(i=0; i<10; i++)
        {
            for(j=0; j<m[i]; j++) printf("%d", i);
            m[i]=0;
        }
        for(i=0; i<26; i++) b[i]=0;
        printf("\n");

    }
    return 0;
}
