#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
struct T
{
    int x,y,z;
    T() {}
    T(int _x,int _y,int _z) {x=_x; y=_y; z=_z;}
    bool operator <(const T &o) const {return x<o.x;}
} l[10005];
int t,e,r,n; long long ans; set<T> s;
set<T>::iterator begin,end;
int get(int x,int &req)
{
    T y(x,0,0); s.insert(y); int tr;
    set<T>::iterator it=s.find(y),iti,itd;
    iti=itd=it; --itd; ++iti;
    /*
    if(iti!=end&&itd!=begin) {printf("1\n"); tr=min(e,min(e,r*(x-itd->x))+r*(iti->x-x)-iti->y);}
    else if(iti==end&&itd==begin) {printf("2\n"); tr=e;}
    else if(iti==end) {printf("3\n"); tr=min(e,(x-itd->x)*r);}
    else if(itd==begin) tr=min(e,e+(iti->x-x)*r-iti->y);
    */
    req=min(e,itd->z+(x-itd->x)*r);
    tr=min(req,req+(iti->x-x)*r-iti->y);
    //tr=min(e,min(e,r*(x-itd->x)+itd->z)+r*(iti->x-x)-iti->y);
    //req=tr+min(e,max(0,iti->y-(iti->x-x)*r+tr));
    s.erase(y); return tr;
}
int main()
{
    freopen("in2","r",stdin);
    freopen("out2","w",stdout);
    scanf("%d",&t);
    for(int I=1;I<=t;++I)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;++i) {scanf("%d",&l[i].x); l[i].y=i;}
        sort(l,l+n); s.clear(); ans=0;
        s.insert(T(-1,0,e)); begin=s.find(T(-1,0,e));
        s.insert(T(n,0,0)); end=s.find(T(n,0,0));
        for(int i=n-1;i>=0;--i)
        {
            int x,y; x=get(l[i].y,y);
            ans+=(long long)x*(long long)l[i].x;
            //printf("%d %d %d %d\n",l[i].y,x,y,y-x);
            s.insert(T(l[i].y,y,y-x));
        }
        printf("Case #%d: %lld\n",I,ans);
    }
    return 0;
}
