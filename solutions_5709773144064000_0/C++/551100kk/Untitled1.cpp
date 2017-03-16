#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> ans;
int s1[4][4],s2[4][4];
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,x,y,C=0;
    double a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf",&a,&b,&c);
        double tmp=0,val=2,ans=c/2;
        for(i=0;i<200000;i++){
            tmp+=a/val;
            val+=b;
            if(tmp+c/val<ans)
                ans=tmp+c/val;
        }
        printf("Case #%d: %.7lf\n",++C,ans);
    }
}
