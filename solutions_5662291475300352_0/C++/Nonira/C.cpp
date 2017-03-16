#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

pair<long long,long long> a;
vector<pair<long long,long long> > v;

long long k[500500],mx,m[500500],q,i,j,t,n,st,x,y,z,c1,c2,c3,x1,x2;

int main(){
    scanf("%lld",&q);
    for(t=1;t<=q;t++){
        scanf("%lld",&n);
        st=0;
        for(i=1;i<=n;i++){
            scanf("%lld %lld %lld",&x,&y,&z);
            for(j=0;j<y;j++){
                k[st]=360-x;
                m[st]=z+j;
                a.first=k[st]*m[st];
                a.second=st;
                v.push_back(a);
                st++;
            }
        }
        sort(v.begin(),v.end());
        c1=0;
        c2=st-2;
        mx=st;
        while(c1<=c2){
            c3=(c1+c2)/2;
            x1=st-1-c3;
            x2=x1-1;
            for(i=0;i<c3;i++)x1+=(v[c3].first-v[i].first)/(360*m[v[i].second]);
            for(i=0;i<c3+1;i++)x2+=(v[c3+1].first-v[i].first)/(360*m[v[i].second]);
            if(mx>x1)mx=x1;
            if(mx>x2)mx=x2;
            if(x1>x2)c1=c3+1;
            else c2=c3-1;
        }
        printf("Case #%lld: %lld\n",t,mx);
        v.clear();
    }
}
