#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define MX 1007
int n,a,b;
//double pb[MX];
typedef struct{
    int a;
    int b;
    int dn;
    int bug;
}pr;
pr pra[MX];pr prt;
bool myf2(pr x,pr y){
    //if(x.dn==2 && y.dn==2) return false;
    //if(y.dn==2) return false;
    //if(x.dn==2) return true;
    return x.b>y.b;
}
bool myf(pr x,pr y){
    //if(x.dn==2 && y.dn==2) return false;
    //if(y.dn==2) return false;
    //if(x.dn==2) return true;
    if(x.a==y.a){
        return (x.b>y.b);
    }
    return x.a<y.a;
}
void _deb(){
    for(int i=0;i<n;i++) cout<<pra[i].bug<<" ";
    cout<<endl;
}
int main()
{
    freopen("b3.in","r",stdin);
    freopen("b3.out","w",stdout);

int gt;
cin>>gt;
for(int run=1;run<=gt;run++){
    cin>>n;
    for(int i=0;i<n;i++){
       // cin>>prt.a>>prt.b;
       // prt.dn=0;
        cin>>pra[i].a>>pra[i].b;
        pra[i].dn=0;
        pra[i].bug=i;
    }

    int cur=0;int di;int ret=0;

  while(1){
    sort(pra,pra+n,myf2);
    //_deb();
    for(di=0;di<n;di++) if(pra[di].b<=cur && pra[di].dn!=2){
        if(pra[di].dn==0) cur+=2;
        else cur+=1;
        pra[di].dn=2;
        pra[di].a=-1;
        pra[di].b=-1;
        ret++;
        //cout<<pra[di].bug<<"one"<<cur<<"\n";
        break;
    }
    if(di!=n) continue;

    sort(pra,pra+n,myf);
    //_deb();
    for(di=0;di<n;di++) if(pra[di].a<=cur && pra[di].dn==0){
        cur+=1;
        pra[di].dn=1;
        ret++;
        //cout<<pra[di].bug<<"two"<<cur<<"\n";
        break;
    }
    if(di==n) break;
  }
    bool fl=0;
    for(int i=0;i<n;i++) if(pra[i].dn!=2) fl=1;

    if(fl) printf("Case #%d: Too Bad\n",run);
    else printf("Case #%d: %d\n",run,ret);
}
    return 0;
}
// END CUT HERE
