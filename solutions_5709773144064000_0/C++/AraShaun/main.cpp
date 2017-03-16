#include <cstdio>

using namespace std;

int main()
{
    int t;
    FILE *input = fopen("B-small.txt", "r");
    FILE *output = fopen("out.txt", "w");
    fscanf(input, "%d", &t);
    for(int q = 0; q < t; q++)
    {
        double c, f, x;
        fscanf(input, "%lf %lf %lf", &c, &f, &x);
        double cps = 2;
        double time = 0;
        while(true)
        {
            if( ((x/(cps+f))+c/cps) < x/cps )
            {
                time += c/cps;
                cps += f;
            }
            else
            {
                time += x/cps;
                break;
            }
        }
        fprintf(output, "Case #%d: %f\n", q+1, time);
    }
    return 0;
}
