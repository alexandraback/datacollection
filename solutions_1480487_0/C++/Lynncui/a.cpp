#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void run()
{
    int a[300];
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
        
    double ava = 0.0;
    double sum = 0.0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    
    ava = sum / (double)k * 2;
    
    int nk = 0;
    double nsum = 0.0;
    double nava = 0.0;
    //printf("ava %lf\n", ava);
    for (int i = 0; i < k; i++)
    {
        if (a[i] < ava) 
        {
            nsum += a[i];
            nk++;
        }
    }
    nsum += sum;
    //printf("nsum %lf nk %d\n", nsum, nk);
    if (nk > 0)
    {
        nava = nsum / (double)nk;
    }
    
    //printf("%lf\n", nava);
    
    for (int i = 0; i < k; i++)
    {
        double ans = 0.0;
        if (a[i] < ava)
        {
            ans = (nava - a[i]) / sum * 100;
        }
        printf("%lf ",  ans);
        if (i == k - 1)
        {
            printf("\n");
        }
    }
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    int N = 0;
    scanf("%d", &N);
    getchar();
    for (int k = 1; k <= N; k++)
    {
        printf("Case #%d: ", k);
        run();
    }
    return 0;
}
