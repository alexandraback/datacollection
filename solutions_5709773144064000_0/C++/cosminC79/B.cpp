#include <cstdio>
#include <algorithm>
#define LIM 10000000
using namespace std;
int tests;
double c, f, x;

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    
    scanf("%d", &tests);
    for (int test_no = 1; test_no <= tests; test_no++)
    {
        scanf("%lf%lf%lf", &c, &f, &x);
        double res = x / 2, so_far = 0, curr = 2;
        for (int i = 1; i <= LIM && so_far < res; i++)
        {
            so_far += c / curr; curr += f;
            res = min(res, so_far + x / curr);
        }
        
        printf("Case #%d: ", test_no);
        printf("%.10lf\n", res);
    }
    return 0;
}
