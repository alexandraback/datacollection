#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 10010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int pp[9][9] = {{0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8},
    {0, 2, 5, 4, 7, 6, 1, 8, 3},
    {0, 3, 8, 5, 2, 7, 4, 1, 6},
    {0, 4, 3, 6, 5, 8, 7, 2, 1},
    {0, 5, 6, 7, 8, 1, 2, 3, 4},
    {0, 6, 1, 8, 3, 2, 5, 4, 7},
    {0, 7, 4, 1, 6, 3, 8, 5, 2},
    {0, 8, 7, 2, 1, 4, 3, 6, 5}
};
LL L, X;
int a[NUM], suffix[NUM], prefix[NUM];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int i, j;
    int T, cas = 1;
    scanf("%d", &T);
    char buffer[NUM];
    int all, powl[4];
    while(T--)
    {
        scanf("%lld%lld", &L, &X);
        scanf("%s", buffer);
        for(i = 0; i < L; i++)
        {
            if(buffer[i] == 'i')
                a[i] = 2;
            else if(buffer[i] == 'j')
                a[i] = 3;
            else
                a[i] = 4;
        }
        prefix[0] = a[0];
        for(i = 1; i < L; i++)
			prefix[i] = pp[prefix[i - 1]][a[i]];
        suffix[L - 1] = a[L - 1];
        for(i = L - 2; i >= 0; i--)
            suffix[i] = pp[a[i]][suffix[i + 1]];
        all = prefix[L - 1];
        powl[0] = 1;
        for(i = 1; i < 4; i++)
			powl[i] = pp[powl[i - 1]][all];
        bool yes = (powl[X%4] == 5);
//        cout << powl[0] << ' ' << powl[1] << ' ' << powl[2] << ' ' << powl[3] << endl;
//        cout << X%4 << ' '<< all << ' ' << powl[X%4] << endl;
//        cout << yes << endl;
        if(yes)
        {
            int n1 = 5, l1 = L, n2 = 5, l2 = 0;
            for(i = 0; i < L; i++)
            {
            	//cout << prefix[i] << ' ';
                if(prefix[i] == 2)
                {
                    n1 = 0, l1 = i;
                    break;
                }
                else if(n1 > 1 && pp[powl[1]][prefix[i]] == 2)
                {
                    n1 = 1, l1 = i;
                }
                else if(n1 > 2 && pp[powl[2]][prefix[i]] == 2)
                {
                    n1 = 2, l1 = i;
                }
                else if(n1 > 3 && pp[powl[3]][prefix[i]] == 2)
                {
                    n1 = 3, l1 = i;
                }
            }
            for(i = L - 1; i >= 0; i--)
            {
                if(suffix[i] == 4)
                {
                    n2 = 0, l2 = i;
                    break;
                }
                else if(n2 > 1 && pp[suffix[i]][powl[1]] == 4)
                {
                    n2 = 1, l2 = i;
                }
                else if(n2 > 2 && pp[suffix[i]][powl[2]] == 4)
                {
                    n2 = 2, l2 = i;
                }
                else if(n2 > 3 && pp[suffix[i]][powl[3]] == 4)
                {
                    n2 = 3, l2 = i;
                }
            }
            if(n1 == 5 || n2 == 5 || (n1 + n2 + 1 > X) || (n1 + n2 + 1 == X && l1 >= l2))
            {
                yes = false;
                //cout << cas << endl;
            }
            //cout << n1 << ' ' << l1 << ' ' << n2 << ' ' << l2 << endl;
        }
        printf("Case #%d: ", cas++);
        if(yes)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
