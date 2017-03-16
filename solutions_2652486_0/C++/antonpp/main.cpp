#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int r, n, m, k;
std::default_random_engine generator;
vector<int> prod[200], my_prod;
vector<int> a;

bool guess(int x)
{
    std::uniform_int_distribution<int> distribution(2,m);
    a.assign(n, 0);
    for (int i = 0; i < n; ++i)
        a[i] = (distribution(generator));
    
    std::uniform_int_distribution<int> szd(0,n);
    std::uniform_int_distribution<int> ind(0,n - 1);
    my_prod.assign(k, 1);
    for (int i = 0 ; i < k; ++i)
    {
        int sz = szd(generator);
        for (int j = 0; j < sz; ++j)
            my_prod[i] *= a[ind(generator)];
    }
    sort(my_prod.begin(), my_prod.end());
    return my_prod == prod[x];
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
        scanf("%i", &t);
    for (int p = 1; p <= t; ++p)
    {
        scanf("%i%i%i%i", &r, &n, &m, &k);
        printf("Case #1:\n");
        for (int i = 0; i < r; ++i)
        {
            prod[i].assign(k, 0);
            for (int j = 0; j < k; ++j)
                scanf("%i", &prod[i][j]);
            sort(prod[i].begin(), prod[i].end());
        }
        for (int i = 0; i < r; ++i)
        {
            int k = 0;
            while (!guess(i) && ++k < 1e5);
            for (int j = 0; j < n; ++j)
                printf("%i", a[j]);
            printf("\n");
        }
    }


    return 0;
}