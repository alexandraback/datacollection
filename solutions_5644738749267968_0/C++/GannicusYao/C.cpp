#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1010 ;

int _;
int n;
vector< pair<double,int> > v;
double a[MAXN],b[MAXN];
int x[MAXN],y[MAXN],z[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&_);
    int cas=0;
    while (_--){
        v.clear() ;
        scanf("%d",&n) ;
        for (int i=1;i<=n;i++) scanf("%lf",&a[i]),v.push_back(make_pair(a[i],i));
        for (int i=1;i<=n;i++) scanf("%lf",&b[i]),v.push_back(make_pair(b[i],i+n));
        sort(v.begin(),v.end());
        for (int i=0;i<v.size();i++){
            int te=v[i].second;
            if (te>n) y[te-n]=i;
            else x[te]=i;
        }
        sort(x+1,x+1+n);
        sort(y+1,y+1+n);
        int st=1;
        int ans2=0,ans1=0;
        /*for (int i=1;i<=n;i++) cout<<x[i]<<" ";
        cout<<endl;
        for (int i=1;i<=n;i++) cout<<y[i]<<" ";
        cout<<endl;*/
        for (int i=1;i<=n;i++) z[i]=y[i];
        int te;
        st=1;
        for (int i=1;i<=n;i++){
            te=-1;
            for (int j=n;j>=1;j--)
                if (z[j]>x[i]) te=j;
            if (te!=-1){
                z[te]=-1;
            }else{
                while (z[st]==-1) st++;
                z[st]=-1;
                ans2++;
            }
        }
        int ed=n; st=1;
        for (int i=1;i<=n;i++){
            if (x[i]>y[st]){
                ans1++;
                st++;
            }else{
                if (x[i]>y[ed])
                    ans1++;
                ed--;
            }
        }
        printf("Case #%d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}
