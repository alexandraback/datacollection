#include<bits/stdc++.h>

#define mod 1000000007
#define INF 1000000009
#define MX 1000001

#define pb push_back
#define mp make_pair
#define ll long long
#define gc getchar
#define vi vector<int>
#define rep(i, n) for(int i=0; i<n; i++)

int n, cm=INF, jm=INF, cur=INF;
using namespace std;

void solve(char x[], char y[], int j)
{
    if(j>n) return;
    int i;
    for(i=0; i<n; i++) if(x[i]=='?' || y[i]=='?') break;
    if(i==n)
    {
        int ans1=0, ans2=0;
        for(int i=0; i<n; i++)
        {
            ans1=ans1*10+x[i]-'0';
            ans2=ans2*10+y[i]-'0';
        }
        //printf("%d %d\n", ans1, ans2);
        int d=abs(ans1-ans2);
        if(cur>d) { cur=d; cm=ans1; jm=ans2; }
        else if(cur==d)
        {
            if(cm>ans1) {cm=ans1; jm=ans2;}
            else if(cm==ans1 && jm>ans2) {jm=ans2;}
        }
        //printf("%d %d %d\n", cur, cm, jm);
        return;
    }
    if(j==n) return;
    int f=0, g=0;
    for(int i=0; i<10; i++)
    {
        for(int k=0; k<10; k++)
        {
            if(x[j]=='?') { x[j]=i+'0'; f=1; }
            if(y[j]=='?') { y[j]=k+'0'; g=1; }
            solve(x, y, j+1);
            if(f) { x[j]='?'; f=0; }
            if(g) { y[j]='?'; g=0; }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("J:\\Downloads\\B-small-attempt1.in","r",stdin);
    //freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int t, i, j, k, q;
    char x[19], y[19];
    scanf("%d", &t);
    rep(q, t)
    {
        printf("Case #%d: ", q+1);
        scanf("%s%s", x, y);
        for(n=0; x[n]; n++);
        solve(x, y, 0);
        printf("%0*d %0*d\n", n, cm, n, jm);
        cur=cm=jm=INF;
    }
    return 0;
}
