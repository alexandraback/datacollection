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
int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    int test;
    cin>>test;
    for(int kase=1;kase<=test;kase++){
        int k;
        string s;
        cin>>k>>s;
        int sum=0,res=0;
        for(int i=0;i<k+1;i++){
            if(sum<i){
                res+=i-sum;
                sum=i;
            }
            sum+=(s[i]-'0');
        }
        cout<<"Case #"<<kase<<": "<<res<<endl;
    }
    return 0;
}
