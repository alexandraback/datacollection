#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node{
    node(){}
    node(int p1,int p2){f=p1,s=p2;}
    int f,s;
}arr[1005];
bool operator<(const node& a,const node& b){
    if(a.s==b.s) return a.f<b.f;
    return a.s<b.s;
}
int a[2005],cum[2005];
inline int min(int a,int b){return a<b?a:b;}
int main(){
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        int n,i;
        memset(a,0,sizeof a);
        memset(cum,0,sizeof cum);
        bool stat=true;
        int level=0,need,have=0,temp,used=0;
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d%d",&arr[i].f,&arr[i].s);
            ++a[arr[i].f];
        }
        cum[0]=a[0];
        for(i=1;i<=2001;++i) cum[i]=cum[i-1]+a[i];
        sort(arr,arr+n);
        for(i=0;i<n;++i){
            need=arr[i].s;
            if(have>=need){
                have+=2;
                ++level;
            }else{
                int tot=0;
                while(have<need){
                    temp=cum[have]-tot;
					if(temp<=0) break;
                    tot+=temp;
                    have+=temp;
                }
                if(have>=need){
					tot-=(have-need);
					have=need;
                    if(arr[i].s-1>=0&&cum[arr[i].s-1]-used<=tot) have+=1;
                    else have+=2;
                    level+=1+tot;
                    used+=tot;
                }else{
                    stat=false;
                    goto hell;
                }
            }
        }
        hell:
        if(stat==false) printf("Case #%d: Too Bad\n",cc);
        else printf("Case #%d: %d\n",cc,level);
    }
    return 0;
}
