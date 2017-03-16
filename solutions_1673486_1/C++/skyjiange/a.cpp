#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#define mod 1000000007
using namespace std;
int n,m,a,b;
double p[100009];
string s;
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out1","w",stdout);
    int T,cas=0;
    cin>>T;
    while(T--){
        cin>>a>>b;        
        for(int i=1;i<=a;i++) cin>>p[i];
        double ans=min(b+2,a+b+1);
        double t=1.0;
        for(int i=1;i<=a;i++){
            t*=p[i];
            ans=min(ans,(b+a-2*i+1)+(1-t)*(b+1));
        }
        printf("Case #%d: %.12lf\n",++cas,ans);
        //cout<<"Case #"<<++cas<<": "<<ans<<endl;
    }
    //fclose(stdout);
    return 0;
}
