#include<algorithm>
#include<cstdio>
using namespace std;
int T,n,g,s[100001],ct1,ct2;
long long a,b,ans,x[100001],y[100001],now;
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int r =1;r<=T;r++){
        ans = 0;g = 0;ct1 = 0;ct2 = 0;
        scanf("%lld %lld %d",&a,&b,&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&x[i]),y[i] = 0;
        s[++ct1] = n-1;ct2 = ct1-1;
        for(int i=n-2;i>=0;i--){
            while(ct2 < ct1 && (long long)(s[ct2+1]-i)*b > a) ct2++;
            while(ct1 > ct2 && x[s[ct1]] < x[i]) ct1--;
            if(ct1 == ct2)
                y[i] = 0;
            else
                y[i] = s[ct1]-i;
            s[++ct1] = i;
        }
        now = a;
        for(int i=0;i<n;i++){
            if(y[i] == 0)
                ans += now*x[i],now = 0;
            else{
                if(now > a-y[i]*b){
                    ans += (now-(a-y[i]*b))*x[i];
                    now = a-y[i]*b;
                }
            }
            now = min(a,now+b);
        }
        printf("Case #%d: %lld\n",r,ans);
    }
    return 0;
}
//
