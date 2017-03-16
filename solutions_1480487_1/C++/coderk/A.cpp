// code jam round 1b
// problem a

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 210;

double judge[MAXN], precentage[MAXN], x;
bool exceed[MAXN];
int n;

int main()
{
    int testcase;
    FILE *fin = fopen("a.in", "r");
    FILE *fout = fopen("a.out", "w");
    fscanf(fin, "%d", &testcase);
    for (int test = 1; test <= testcase; test++)
    {
        fscanf(fin, "%d", &n);
        x = 0;
        for (int i = 1; i <= n; i++)
        {
            fscanf(fin, "%lf", &(judge[i]));
            x += judge[i];
        }
        fprintf(fout, "Case #%d:", test);
        double req = (x * 2) / double(n), res, sum = 2 * x, account = n;
        for (int i = 1; i <= n; i++)
            if (judge[i] >= req)
                sum -= judge[i], exceed[i] = true, account--;
            else
                exceed[i] = false;
        req = sum / account;
        for (int i = 1; i <= n; i++)
            if (exceed[i])
                fprintf(fout, " 0");
            else
            {
                res = (req - judge[i]) / x;
                fprintf(fout, " %.6lf", res * 100);
            }
        fprintf(fout, "\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
