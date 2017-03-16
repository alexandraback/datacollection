#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

double doit(vector <double> num, double d)
{
    if (num.size() == 1)
    {
        return num[0] + d;
    }
    while (d > .0)
    {
        int i;
        for (i = 1; i < num.size(); ++i)
        {
            if (num[i] != num[0])
            {
                break;
            }
        }
        if (i == num.size())
        {
            num[0] += d / num.size();
            break;
        }
        double temp = (num[0] * i + d);
        if (temp / i >= num[i])
        {
            d -= (num[i] - num[0]) * i;
            for (int j = 0; j < i; ++j)
            {
                num[j] = num[i];
            }
        }
        else
        {
            num[0] = temp / i;
            break;
        }
    }
    return num[0];
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int case_all, case_count = 1;
    scanf("%d\n", &case_all);
    for (case_count = 1; case_count <= case_all; case_count += 1)
    {
        printf("Case #%d:", case_count);
        int n, sm = 0;
        scanf("%d", &n);
        vector <int> num(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &num[i]);
            sm += num[i];
        }
        for (int i = 0; i < n; ++i)
        {
            double h = 100.0, l = .0;
            while (h - l > 1e-7)
            {
                double m = l + (h - l) / 2;
                vector <double> num2;
                for (int j = 0; j < n; ++j)
                {
                    if (j != i)
                    {
                        num2.push_back(num[j]);
                    }
                }
                sort(num2.begin(), num2.end());
                double temp = doit(num2, (100.0 - m) * sm / 100.0);
                if (temp >= m * sm / 100 + num[i])
                {
                    l = m;
                }
                else
                {
                    h = m;
                }
            }
            printf(" %lf", l + (h - l) / 2);
        }
        printf("\n");
    }
    return 0;
}
