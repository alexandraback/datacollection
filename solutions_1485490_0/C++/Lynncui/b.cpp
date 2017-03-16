#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

long long ac[110], bc[110];
long long a[110], b[110];

long long tmpbc[110];

int n, m;

void cp()
{
    for (int i = 0; i < m; i++)
    {
        tmpbc[i] = bc[i];
    }
}

long long cal(int b1, int e1, int ai)
{
    long long sum = 0;
    for (int i = b1; i <= e1; i++)
    {
        if (b[i] == a[ai])
        {
            if (sum + tmpbc[i] > ac[ai])
            {
                long long dex = sum + tmpbc[i] - ac[ai];
                sum = ac[ai];
                tmpbc[i] = dex;
            }
            else
            {
                sum += tmpbc[i];
                tmpbc[i] = 0;
            }
            
        } 
    }
    return sum;
}

long long solve()
{
    if (n == 1)
    {
        return cal(0, m - 1, 0);
    }
    else if (n == 2)
    {
        long long maxsum = 0;
        for (int i = 0; i < m; i++)
        {
            cp();
            long long sum = cal(0, i, 0) + cal(i, m - 1, 1);
            if (sum > maxsum)maxsum = sum;
        }
    }
    else
    {
        long long maxsum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                cp();
                long long sum = cal(0, i, 0) + cal(i, j, 1) + cal(j, m - 1, 2);
                if (sum > maxsum)
                {
                    maxsum = sum;
                }
            }
        }
        return maxsum;
    }
    
    return 0;
}

void run()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ac[i] >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> bc[i] >> b[i];
    }
    
    cout << solve() << endl;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);
    
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
