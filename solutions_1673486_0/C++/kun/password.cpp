#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int rr,a,b;
double p[100001],f[100001],ans;
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("test.txt","w",stdout);
    scanf("%d",&rr); 
    for(int rg=0;rg<rr;rg++){
        scanf("%d%d",&a,&b);     
        for(int i=0;i<a;i++) scanf("%lf",&p[i]);
        ans = (double)(b)+2.0;
        f[0] = p[0];
        for(int i=1;i<a;i++) f[i] = p[i]*f[i-1];
        for(int i=a-1;i>=0;i--){
                //printf("%lf --> ",f[i]);
            //printf("%d %lf\n",i,f[i]*(double)(a-i-1+b-i)+(1.00-f[i])*(double)(a-i-1+b-i+b+1));
            ans = min(ans,f[i]*(double)(a-i-1+b-i)+(1.00-f[i])*(double)(a-i-1+b-i+b+1));       
        }
        printf("Case #%d: %lf\n",rg+1,ans);
    }
    //system("pause");
    return 0;
}
