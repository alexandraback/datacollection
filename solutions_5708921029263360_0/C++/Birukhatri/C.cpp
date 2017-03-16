#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define CHR getchar()
#define NL printf("\n")
#include<bits/stdc++.h>
#define ULL unsigned LL
#define LL long long int
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define F(i,a,b) for(int i=a;i<b; i++)
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define cp printf("***** here here here here *****\n");
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

using namespace std;

///         0123456789
#define MX  400007
#define MOD 1000000007
#define INF 2000000000
#define EPS 1e-9


struct z {
    int u,v,w;
    z(){}
    z(int a,int b,int c) {
        u=a,v=b,w=c;
    }
};

z ar[MX];

int Ln;

int vs1[12][12];
int vs2[12][12];
int vs3[12][12];

int ISOK(int id,int k) {
    int a,b,c;
    a=ar[id].u;
    b=ar[id].v;
    c=ar[id].w;

    if(vs1[a][b]==k) return 0;
    if(vs2[b][c]==k) return 0;
    if(vs3[a][c]==k) return 0;

    vs1[a][b]++;
    vs2[b][c]++;
    vs3[a][c]++;
    return 1;
}



int main()
{
    freopen("A.in","r",stdin),freopen("A1.out","w",stdout);

    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        Ln=0;



        for(int i=1;i<=a;i++) {
            for(int j=1;j<=b;j++) {
                for(int k=1;k<=c;k++) {
                    ar[Ln++]=z(i,j,k);
                }
            }
        }

        vector<z> ans1;
        int mx=0;

        for(int ii=0;ii<=10000;ii++) {
            random_shuffle(ar,ar+Ln);
            vector<z> ans;
            MEM(vs1,0);
            MEM(vs2,0);
            MEM(vs3,0);
            for(int i=0;i<Ln;i++) {
                if(ISOK(i,d)) {
                    ans.PB( ar[i] );
                }
            }

            if(ans.sz>mx) {
                mx=ans.sz;
                ans1=ans;
            }
        }



        cout<< "Case #"<<cs<< ": "<<ans1.sz<<endl;

        for(int i=0;i<ans1.sz;i++) {
            cout<<ans1[i].u<< " "<<ans1[i].v<< " "<<ans1[i].w<<endl;
        }
    }

    return 0;
}
///============= Thank You ===================///
