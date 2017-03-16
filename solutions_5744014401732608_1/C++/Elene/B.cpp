#include <bits/stdc++.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F first
#define S second
#define pp pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define INF 2000000
#define P 1000000007
#define E 10000000
#define vec vector<vector<ll> >
using namespace std;
const int N=100005;

int T,B;
ll M,dp[60];
int f[50][50];


int main()
{   freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);



    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        cin>>B>>M;

        for(int i=0;i<B;i++)
            for(int j=0;j<B;j++)f[i][j]=0;
        for(int i=0;i<B;i++)dp[i]=0;

        cout<<"Case #"<<t<<": ";

        if(M>(1ll<<(B-2))){cout<<"IMPOSSIBLE"<<endl;continue;}
        cout<<"POSSIBLE"<<endl;

        for(int i=0;i<B-1;i++)
            for(int j=i+1;j<B-1;j++)
            f[i][j]=1;


        dp[0]=1;
        for(int i=1;i<B-1;i++)
            for(int j=0;j<i;j++)dp[i]+=dp[j];

        for(int j=B-2;j>=0;j--)
        if(M>=dp[j]){
            f[j][B-1]=1;
            M-=dp[j];
        }

        for(int i=0;i<B;i++){
            for(int j=0;j<B;j++)
                cout<<f[i][j];
            cout<<endl;
        }
    }

    return 0;
}
