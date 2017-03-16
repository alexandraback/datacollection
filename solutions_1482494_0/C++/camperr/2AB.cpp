#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt{
    int no,ra,va;
    bool operator<(const pt &ot)const{
        return va<ot.va;
    }
} p[3007];
int st[1007];
int n;
int sa[1007][2];

int main(){
    //freopen("in.txt","r",stdin);
    freopen("B-small-attempt2.in","r",stdin);
   freopen("out.txt","w",stdout);
    int i,j,k,t;
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%d",&n);
        memset(st,0,sizeof(st));
        for(i=0,k=0;i<n;i++) {
            scanf("%d %d",sa[i],sa[i]+1);
            p[k].no=i;
            p[k].ra=0;
            p[k++].va=sa[i][0];
            p[k].no=i;
            p[k].ra=1;
            p[k++].va=sa[i][1];
        }
        sort(p,p+k);
        //printf("%d\n",k);
        int x=0,ans=0,star=0,d;
        i=0;
        bool yes=true;
        while(true){
            while(x<k && p[x].va<=star) {
                if(p[x].ra==1){
                    //printf("%d\n",x);
                    if(st[p[x].no]==0) star+=2;
                    else if(st[p[x].no]==1) star+=1;
                    st[p[x].no]=2;
                    ans++;
                }
                x++;
            }
            if(x>=k) break;
            while(star<p[x].va){
                while(i<k && (st[p[i].no]!=0 || p[i].ra==1)) i++;
                if(i>=k || p[i].va>star) {
                    yes=false;
                    break;
                }
                st[p[i].no]=1;
                star++;
                ans++;
                i++;
            }
            if(!yes) break;
        }
        printf("Case #%d: ",j);
        if(!yes) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
}

