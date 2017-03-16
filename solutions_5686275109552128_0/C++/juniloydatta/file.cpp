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
priority_queue<int>PQ;
int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    int test;
    cin>>test;
    for(int kase=1;kase<=test;kase++){
        while(!PQ.empty()) PQ.pop();
        int d,res=10000000;
        cin>>d;
        for(int i=0;i<d;i++){
            int p;
            cin>>p;
            PQ.push(p);
        }
        int day=0;
        while(!PQ.empty()){
            int top=PQ.top();
            res=min(res,top+day);
            if(top==1) break;
            PQ.pop();
            PQ.push(top/2);
            PQ.push(top-(top/2));
            day++;
            if(day>res) break;
        }
        cout<<"Case #"<<kase<<": "<<res<<endl;
    }
    return 0;
}
