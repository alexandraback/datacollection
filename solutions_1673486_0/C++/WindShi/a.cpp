#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int test,A,B;
double win[100001];

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&test);
    for (int uu=1;uu<=test;uu++)
    {
        scanf("%d%d",&A,&B);
        for (int i=1;i<=A;i++) scanf("%lf",&win[i]);
        double ans=B+1,allwin=1;
        win[0]=1;
        for (int i=0;i<=A;i++)
        {
            allwin*=win[i];
            if ( allwin*(B-i+A-i)+(1.0-allwin)*(B-i+1+B+A-i) < ans) ans=allwin*(B-i+A-i)+(1.0-allwin)*(B-i+1+B+A-i);
        }
        printf("Case #%d: %.8lf\n",uu,ans+1);
    }
}    
