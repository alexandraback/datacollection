#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    double c, f, x;
    int i;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%lf %lf %lf\n", &c, &f, &x);
        double gen = 2.0;
        double spent = 0;
        double best = x / gen;

        while (true)
        {
            spent += c / gen;
            gen += f;
            double cand = spent + x / gen;
            if (cand < best)
            {
                best = cand;
                continue;
            }
            break;
        }

        printf("Case #%d: %.7lf\n", t + 1, best);
    }
    return 0;
}
