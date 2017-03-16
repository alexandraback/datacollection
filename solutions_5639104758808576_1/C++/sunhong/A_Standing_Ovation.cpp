#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A_output_large.txt","w",stdout);
    int T,N;
    char s[1100];
    scanf("%d",&T);
    for (int index=1;index<=T;index++)
    {
        scanf("%d%s",&N,s);
        int result = 0;
        int sum = 0;
        for (int i=0;i<=N;i++)
        {
            //printf("sum=%d\n",sum);
            if (s[i]>'0' && sum<i)
            {
                int delta=i-sum;
                result+=delta;
                sum+=delta;
            }
            sum+=(int)(s[i]-'0');
        }
        printf("Case #%d: %d\n",index,result);
    }
    return 0;
}
