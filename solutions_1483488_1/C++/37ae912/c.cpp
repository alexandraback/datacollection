
#include <cstdio>
#include <algorithm>
using namespace std;


int d[1000];

int main()
{
    int T,cs=0;
    scanf("%d",&T);
    while(cs++<T){
        int a,b;
        scanf("%d%d",&a,&b);

        int base=1;

        while(base<=a) base*=10;
        base/=10;

        int ans=0;

        for(int i=a;i<=b;++i){
            int j = i;
            
            while(1){
                j = j/10 + base*(j%10);
                if(j>=a && j<=b && j>i){
                    ans++;
                }
                if(i==j)break;
            }
            /*
            sort(d,d+temp);
            for(int j=0;j<temp;++j){
                if(d[j]==d[j+1])printf("i=%d, %d\n",i,d[j]);
            }*/

        }

        printf("Case #%d: %d\n",cs,ans);

    }


    return 0;
}
