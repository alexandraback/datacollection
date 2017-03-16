#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    cout.sync_with_stdio(0);
    int t; cin>>t;
    for(int test=1;test<=t;test++){
        int n; cin>>n;
        vector<pii>v(n);
        map<string,int>t1,t2;
        vector<int>ile1(n+1),ile2(n+1);
        int nr1=1,nr2=1;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            if(t1[str]==0)t1[str]=nr1++;
            v[i].f=t1[str];
            cin>>str;
            if(t2[str]==0)t2[str]=nr2++;
            v[i].s=t2[str];
            ile1[ v[i].f ]++;
            ile2[ v[i].s ]++;
        }
        int odp=0;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>il1=ile1,il2=ile2;
            bool ok=true;
            for(int i=0;i<n;i++)
                if( (1<<i) & mask){
                    if(il1[ v[i].f ]>1 && il2[ v[i].s ]>1){
                        il1[ v[i].f ]--;
                        il2[ v[i].s ]--;
                    }
                    else ok=false;
                }
            if(ok)odp=max(odp,__builtin_popcount(mask));
            //if(ok)cout<<mask<<"\n";
        }
        cout<<"Case #"<<test<<": "<<odp<<"\n";
    }
    return 0;
}
