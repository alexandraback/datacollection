#define Long long long
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
inline Long min(Long a,Long b){return a<b?a:b;}
inline Long max(Long a,Long b){return a>b?a:b;}
inline Long abs(Long a){return a<0?-a:a;}
struct node{
    Long num;
    int type;
    void input(){scanf("%I64d%d",&num,&type);}
}a[5],b[105];
Long extra[4]={0,0,0,0};
Long taken[4]={0,0,0,0};
int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int t,n,m,i,j,k;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        Long maxi=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i) a[i].input();
        for(i=1;i<=m;++i) b[i].input();
        printf("Case #%d: ",cc);
        if(n==3){
            taken[1]=extra[1]=0;
            for(i=0;i<=m;++i){
                if(taken[1]==a[1].num) break;
                if(i>0&&b[i].type==a[1].type){
                    if(taken[1]+b[i].num>a[1].num) extra[1]=taken[1]+b[i].num-a[1].num,taken[1]=a[1].num;
                    else taken[1]+=b[i].num;
                }
                taken[2]=extra[2]=0;
                for(j=i;j<=m;++j){
                    if(taken[2]==a[2].num) break;
                    if(j>0&&b[j].type==a[2].type){
                        if(i==j){
                            if(taken[2]+extra[1]>a[2].num) extra[2]=taken[2]+extra[1]-a[2].num,taken[2]=a[2].num;
                            else taken[2]+=extra[1];
                        }else{
                            if(taken[2]+b[j].num>a[2].num) extra[2]=taken[2]+b[j].num-a[2].num,taken[2]=a[2].num;
                            else taken[2]+=b[j].num;
                        }
                    }
                    taken[3]=extra[3]=0;
                    if(j==i&&j>0){
                        if(b[j].type!=a[2].type){
                            if(taken[3]+extra[1]>a[3].num) extra[3]=taken[3]+extra[1]-a[3].num,taken[3]=a[3].num;
                            else taken[3]+=extra[1];
                        }else{
                            if(taken[3]+extra[2]>a[3].num) extra[3]=taken[3]+extra[2]-a[3].num,taken[3]=a[3].num;
                            else taken[3]+=extra[2];
                        }
                    }else if(j>0){
                         if(taken[3]+extra[2]>a[3].num) extra[3]=taken[3]+extra[2]-a[3].num,taken[3]=a[3].num;
                        else taken[3]+=extra[2];
                    }
                    for(k=j+1;k<=m;++k){
                        if(taken[3]==a[3].num) break;
                        if(b[k].type==a[3].type){
                            if(taken[3]+b[k].num>a[3].num) extra[3]=taken[3]+b[k].num-a[3].num,taken[3]=a[3].num;
                            else taken[3]+=b[k].num;
                        }
                    }
                    maxi=max(maxi,taken[1]+taken[2]+taken[3]);
                }
            }
            printf("%I64d\n",maxi);
        }else if(n==2){
            taken[1]=extra[1]=0;
            for(i=0;i<=m;++i){
                if(taken[1]==a[1].num) break;
                if(i>0&&b[i].type==a[1].type){
                    if(taken[1]+b[i].num>a[1].num) extra[1]=taken[1]+b[i].num-a[1].num,taken[1]=a[1].num;
                    else taken[1]+=b[i].num;
                }
                taken[2]=extra[2]=0;
                if(b[i].type==a[2].type){
                    if(taken[2]+extra[1]>a[2].num) extra[2]=taken[2]+extra[1]-a[2].num,taken[2]=a[2].num;
                    else taken[2]+=extra[1];
                }
                for(j=i+1;j<=m;++j){
                    if(taken[2]==a[2].num) break;
                    if(b[j].type==a[2].type){
                        if(taken[2]+b[j].num>a[2].num) extra[2]=taken[2]+b[2].num-a[2].num,taken[2]=a[2].num;
                        else taken[2]+=b[j].num;
                    }
                }
                maxi=max(maxi,taken[1]+taken[2]);
            }
            printf("%I64d\n",maxi);
        }else{
            taken[1]=extra[1]=0;
            for(i=0;i<=m;++i){
                if(taken[1]==a[1].num) break;
                if(i>0&&b[i].type==a[1].type){
                    if(taken[1]+b[i].num>a[1].num) extra[1]=taken[1]+b[i].num-a[1].num,taken[1]=a[1].num;
                    else taken[1]+=b[i].num;
                }
            }
            maxi=max(maxi,taken[1]);
            printf("%I64d\n",maxi);
        }
    }
    return 0;
}
