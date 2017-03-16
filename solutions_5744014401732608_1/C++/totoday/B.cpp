#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
#define mem(name,value) memset(name,value,sizeof(name))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100100,inf=0x3f3f3f3f;
ll n,m;
bool b[100];

int main()
{
    freopen("B-large.in","r",stdin);
freopen("out.txt","w",stdout);

    int T,cas=1;
    cin>>T;
    while(T--){
        printf("Case #%d: ",cas++);
        cin>>n>>m;
        ll t;
        if(n==1) t=1;
        else t=(1LL<<(n-2));

        if(t<m) cout<<"IMPOSSIBLE"<<endl;
        else{
            cout<<"POSSIBLE"<<endl;
            if(t==m){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++)
                        if(i<j) printf("1");
                       else printf("0");
                    cout<<endl;
                }
            }else{
                mem(b,0);
                int pos=2;
                while(m){
                    if(m&1) b[pos]=1;
                    m>>=1;
                    pos++;
                }
                for(int i=1;i<n;i++){
                    for(int j=1;j<n;j++)
                       if(i<j) printf("1");
                       else printf("0");
                    if(b[i]) cout<<"1"<<endl;
                    else cout<<"0"<<endl;
                }
                for(int i=0;i<n;i++) cout<<"0";
                cout<<endl;
            }
        }

    }

}







