// karanaggarwal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define mod 1000000007

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

bool fre[100][26];
bool frem[100][26];
int W[100][2];
bool E[100][100];
int  visit[100];
int n;
LL F[101];
int valid(string &A)
{
    int n = A.size();
    int fre[26]={};
    fre[A[0]-'a']=1;
    for(int i=1; i<n;i++)
        if(A[i]!=A[i-1])
        {   
            if(fre[A[i]-'a'])
                return 0;
            fre[A[i]-'a']=1;
        }   
    return 1;
}

void dfs(int x, int c)
{
    if(visit[x])return;
    visit[x]=c;
    repi(i,n)
    {
        if(E[x][i])
            dfs(i,c);
    }
}

VI G[100]; VI RG[100];
VI tord;
void dfs2(int x)
{
    if(visit[x])return;
    visit[x]=1;
    TR(G[x],i)
        dfs2(*i);
    tord.PB(x);
}
void dfs3(int x)
{
    if(visit[x])return;
    visit[x]=1;
    TR(RG[x],i)
        dfs3(*i);
}

bool tsort()
{
    tord.clear();
    SET(visit,0);
    for(int i=0;i<n;i++)
        dfs2(i);
    reverse(tord.begin(),tord.end());
    SET(visit,0);
    TR(tord,i)
    {
        if(visit[*i])return false;
        dfs3(*i);
    }
    return true;
}

int main()
{
    F[0]=1;
    for(int i=1;i<=100;i++)F[i] = (F[i-1]*i)%mod;
    int t; si(t); int T=t; while(t--)
    {
        cout<<"Case #"<<T-t<<": ";
        SET(fre,0);
        SET(frem,0);
        cin>>n; 
        string A;
        int invalid=0;
        repi(i,n) 
        {
            cin>>A;
            if(valid(A)==0)
                invalid=1;
            int l = SZ(A);
            repi(j,l)
            {
                if(A[j]!=A[0] && A[j]!=A[l-1])
                    frem[i][A[j]-'a']=1;
                fre[i][A[j]-'a']=1;
            }
            W[i][0] = A[0]-'a';
            W[i][1] = A[l-1]-'a';
        }
        if(invalid){cout<<0<<endl; continue;}

        repi(i,n)
            repi(j,26)
            {
                if(frem[i][j])
                    for(int k=0;k<n;k++)
                    {
                        if(k!=i && fre[k][j])
                            invalid=1;
                    }
            }
        if(invalid){cout<<0<<endl; continue;}
        

        // C[i][0] , 0 means as start 1 means as middle, 2 measn as end for ith char
        int C[26][3]={};
        repi(i,n)
        {
            if(W[i][0]==W[i][1])
            {
                C[W[i][0]][1]++;
                continue;
            }
            C[W[i][0]][0]++;
            C[W[i][1]][2]++;
        }
        //______________________________________________________________

        // check for no char more than 1 end or start
        repi(i,26)if(C[i][0]>1 || C[i][2]>1)invalid=1;
        if(invalid){cout<<0<<endl; continue;}
        //____________________________________________________________

        //ans = ans * x!
        LL ans = 1;
        repi(i,26)ans = (ans * F[C[i][1]])%mod;
        //______________________________________________--
//        cout<<ans<<" "; 
        // index of start and end of ith char
//        int I[26][2]; SET(I,-1);
//        repi(i,n)
//        {
//            if(W[i][0]==W[i][1])
//                continue;
////            I[W[i][0]][0]=i;
//            I[W[i][1]][1]=i;
//        }
        

        // make graph to find number of component
        SET(E,0); 
        
//        cout<<"Words"<<endl;
//        repi(i,n) cout<<W[i][0]<<" "<<W[i][1]<<endl;
        repi(i,n){G[i].clear(); RG[i].clear(); tord.clear();}
        repi(i,n)
            repi(j,n)
            {
                if(i==j)continue;
                
                if(W[i][0]==W[j][1] || W[j][0]==W[i][1])
                {
                    E[i][j]=1;
                    E[j][i]=1;
                }
                if(W[i][0]==W[i][1] || W[j][0]==W[j][1])continue;
                if(W[i][1]==W[j][0])
                {
                    G[i].PB(j);
                    RG[j].PB(i);
                }
                if(W[j][1]==W[i][0])
                {
                    RG[i].PB(j);
                    G[j].PB(i);
                }
            }  // set edges

        // find nc
        SET(visit,0);
        int nc=0;
        repi(i,n)
        {
            if(visit[i])continue;
            nc++;
            dfs(i,nc);
        }

        if(tsort()==false)invalid=1;
        if(invalid){cout<<0<<endl; continue;}

        ans = (ans * F[nc])%mod;

        cout<<ans<<endl;
    }

    return 0;
}
