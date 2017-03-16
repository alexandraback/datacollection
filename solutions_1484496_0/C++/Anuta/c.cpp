#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>                                                                               

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;

int z[2000010];
int v[2000010];

int a[100];
int n = 20;
int p[200] ;

int T;
int vv;

int m1, m2;


bool f(int st, int m, int s)
{
    if (st == n)
    {
        if (v[s] == vv)
        {
            m1 = z[s];
            m2 = m; 
            return true;
        }
        v[s] = vv;
        z[s] = m;
        return false;
    }
    if (f(st + 1, (m << 1), s) ) return true;
    if (f(st + 1, (m << 1) + 1, s + a[st])) return true;
    
    return false;    
}

int main()
{
  scanf("%d", &T);
  for (int t = 0; t < T; ++t)
  {
    vv = t + 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("Case #%d:\n", t + 1);
    if ( f (0, 0, 0) )
    {
        for (int i = n-1; i >= 0; --i)
        {
            if (m1 & 1)
                printf("%d ", a[i]);
            m1 >>= 1;
        }
        printf("\n");

        for (int i = n-1; i >= 0; --i)
        {
            if (m2 & 1)
                printf("%d ", a[i]);
            m2 >>= 1;
        }
        printf("\n");
    }
    else
    {
        printf("Impossible\n");
    }
    
  }
  return 0;
}
