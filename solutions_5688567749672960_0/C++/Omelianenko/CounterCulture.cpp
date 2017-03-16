 #include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define y0 hi1
#define y1 hi2
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(a) (a)*(a)
#define ld long double
#define all(a) (a).begin(), (a).end()

using namespace std;

const int N=10000005;
const int inf=2000000000;

int d[N], a[N];

int f(int x)
{
    int r=0;
    while(x>0)
    {
        r=r*10+x%10;
        x/=10;
    }
    return r;
}

void add(int x, int y, int &r, int n)
{
    if(y>=d[x])return;
    if(x>n)return;
    r++;
    a[r]=x;
    d[x]=y;
}

main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    for(int num=1; num<=T; num++)
    {
        cout<<"Case #"<<num<<": ";
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
            d[i]=inf;
        int l=0;
        int r=1;
        while(l<r)
        {
            l++;
            int v=a[l];
            int dist=d[v];
            int t1=f(v);
            add(t1, dist+1, r, n);
            int t2=v+1;
            add(t2, dist+1, r, n);
        }
        cout<<d[n]<<"\n";
        /*
        int ans=0, x=0;
        while(x!=n)
        {
            ans++;
            int y=f(x);
            cout<<x<<" "<<y<<endl;
            if(y>x)x=y; else x++;
        }
        cout<<ans<<"\n";
        */
    }
}
