#include<bits/stdc++.h>
using namespace std;
int a[100];
typedef long long ll;
bool can[100];
int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    memset(a,0,sizeof a);
    int t;
    int c,d,v;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>c>>d>>v;
        memset(a,0,sizeof a);
        for(int i=0;i<d;i++){
            int tmp;
            cin>>tmp;
            a[tmp] = true;;
        }
        int ans = 0;
        for(int i=1;i<=v;i++){
            if(a[i])
                continue;
            memset(can,0,sizeof can);
            can[0] = true;
            for(int j=1;j<i;j++){
                if(a[j]){
                    for(int k=i;k>=0;k--){
                        if(can[k]){
                            can[k+j] = true;
                        }
                    }
                }
            }
            if(!can[i]){
                ++ans;
                a[i] = true;
                //cout<<"***"<<i<<endl;
            }
        }


        cout<<"Case #"<<cs<<": "<<ans<<endl;

    }
}
