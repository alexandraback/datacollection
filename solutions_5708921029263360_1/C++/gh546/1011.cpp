#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=11;
struct PP{
    int j,p,s;
    PP(int j=-1,int p=-1,int s=-1):j(j),p(p),s(s){}
}pp[N*N*N];
int num[3][N][N];
int n,j,p,s,k;
int ans[N*N*N],n2;

int main(){
#ifdef gh546
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
#endif // gh546
    int T;scanf("%d",&T);
    int cas=1;
    while(T--){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        n=0;
        for(int i1=0;i1<j;i1++){
            for(int p1=0;p1<p;p1++){
                for(int s1=0;s1<s;s1++){
                    pp[n++]=PP(i1,p1,s1);
                }
            }
        }
        //printf("%d\n",n);
        memset(num,0,sizeof(num));
        n2=0;
        for(int i=0;i<n;i++){
            int x=num[0][pp[i].j][pp[i].p]+1;
            int y=num[1][pp[i].j][pp[i].s]+1;
            int z=num[2][pp[i].p][pp[i].s]+1;
            if(x>k||y>k||z>k)continue;
            else {
                num[0][pp[i].j][pp[i].p]++;
                num[1][pp[i].j][pp[i].s]++;
                num[2][pp[i].p][pp[i].s]++;
                ans[n2++]=i;
            }
        }
        printf("Case #%d: %d\n",cas++,n2);
        for(int i=0;i<n2;i++){
            printf("%d %d %d\n",pp[ans[i]].j+1,pp[ans[i]].p+1,pp[ans[i]].s+1);
        }
    }
    return 0;
}
