#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,map[110][110];
int h,l[110];
int cc(long long x){
    h=0;
    while(x>0){
    h++;
        l[h]=x%10;
        x=x/10;          
    }
    for(int i=1;i<=h/2;i++)
    if(l[i]!=l[h-i+1])return 1;
    return 0;
    } 
int can(long long x){
    if(cc(x))return 0;
    if(cc(x*x))return 0;
    return 1;
}
long long d[1000];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int q=0;
    for(long long i=1;i<=10000000;i++)
    if(can(i)){q++;
    d[q]=i*i;
  //  printf("%lld %lld\n",i,i*i);
    }
    //else if(!cc(i))printf("%lld\n",i);
  //  printf("%d\n",q);
    
    int w;
    long long a,b;
    scanf("%d",&w);
    for(int t=1;t<=w;t++){
            scanf("%lld%lld",&a,&b);
            int e=0;
            for(int i=1;i<=q;i++)
            if(d[i]>=a&&d[i]<=b)e++;
            printf("Case #%d: %d\n",t,e);
            }
    }
