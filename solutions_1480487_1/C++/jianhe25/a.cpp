#include <stdio.h>
#include <algorithm>
using namespace std;

const int V = 210;
double s[V];


bool small[V];
int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%lf",&s[i]);
        
        double total = 0.0, sum;
        for (int i=0;i<n;i++) total += s[i];
        
        double avg = 1e100;
        while (1)
        {
            for (int i=0;i<n;i++) small[i] = false;
            
            sum = total;
            int num = 0;
            for (int i=0;i<n;i++)
            if (s[i] < avg)
            {
                sum += s[i];
                small[i] = true;
                num++;
            }
            avg = sum / num;
            
            bool repeat = false;
            for (int i=0;i<n;i++)
            if (small[i] && s[i] > avg)
            {
                repeat = true;
                break;
            }
            if (!repeat) break;
        }
        printf("Case #%d:",cas);
        for (int i=0;i<n;i++)
        {
            printf(" %.6f", max(0.0, (avg-s[i]) * 100.0 / total));
        }
        puts("");
    }
}
