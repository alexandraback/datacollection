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
const int maxn=11,inf=0x3f3f3f3f;

int a,b,c,k;

void solve(int a,int b,int c)
{
    cout<<a*b*c<<endl;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                    printf("%d %d %d\n",i,j,k);
            }
        }
}

void solve2(int a)
{
    cout<<a<<endl;
    for(int i=1;i<=a;i++) printf("%d %d %d\n",i,i,i);
}

int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=1;
    cin>>T;
    while(T--){
        printf("Case #%d: ",cas++);
        cin>>a>>b>>c>>k;
        //cout<<" "<<a<<" "<<b<<" "<<c<<" "<<k<<endl;
        if(k>=c) solve(a,b,c);
        else if(k>=b) solve(a,b,k);
        else if(k>=a) {
            if(b>=a*k*k){
                cout<<b<<endl;
                for(int i=1;i<=b;i++) cout<<1<<" "<<b<<" "<<b<<endl;
            }
            else solve(a,k,k);
        }else {
            if(a>=k*k*k) solve2(a);
            else solve(k,k,k);
        }
    }


}









