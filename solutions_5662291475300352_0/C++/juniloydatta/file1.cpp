#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 10000000

using namespace std;
double d[5];
int h[5];
double m[5];
int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    int t;
    cin>>t;
    for(int kase=1;kase<=t;kase++){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>d[i]>>h[i]>>m[i];
            sum+=h[i];
        }
        if(sum==1) cout<<"Case #"<<kase<<": 0"<<endl;
        else if(n==2){
            if(d[1]<d[0]){
                swap(d[0],d[1]);
                swap(h[0],h[1]);
                swap(m[0],m[1]);
            }
            double f0=360.0/(m[0]*60.0);
            double f1=360.0/(m[1]*60.0);
            double req0=(360.0-d[0])/f0;
            double req1=(360.0+(360.0-d[1]))/f1;
            if(req0<req1) cout<<"Case #"<<kase<<": 0"<<endl;
            else cout<<"Case #"<<kase<<": 1"<<endl;
        }
        else if(n==1){
            double req0=(360.0-d[0])/((m[0]+1)*60);
            double dis=(req0*m[0])/60.0;
            if(dis>=360.0-d[0]) cout<<"Case #"<<kase<<": 1"<<endl;
            else cout<<"Case #"<<kase<<": 0"<<endl;
        }
    }
    return 0;
}
