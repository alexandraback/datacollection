#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[250];
int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("test.txt","w",stdout);
    int t;
    int n;
    cin >> t;
    for (int tcase = 1; tcase <= t; tcase++)
    {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            sum += num[i];
        }
        //sort(num, num+n);
        double temp = (sum * 2) / (double)n;
        int count = n;
        int total = sum;
        for (int i = n - 1; i > 0; i--)
        {
            if (temp < num[i])
            {
                total-=num[i];
                --count;
            }
        }
        double temp2 = (total + sum) / (double)count;
        printf("Case #%d: ", tcase);
        if (num[0] > temp) printf("0");
        else printf("%lf", (temp2 - num[0]) / sum * 100);
        for (int i = 1; i < n; i++)
        {
            if (num[i] > temp) printf(" 0");
            else printf(" %lf", (temp2 - num[i]) / sum * 100);
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}
