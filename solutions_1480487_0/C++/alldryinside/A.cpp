#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

const int maxn = 256;
int N, s[maxn], total;
void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, k;
    cin >> N;
    total = 0;
    for(i = 0; i < N; ++i)
    {
        cin >> s[i];
        total += s[i];
    }
    double lb, rb, med;
    double crscore;
    for(i = 0; i < N; ++i)
    {
        lb = 0.0; rb = 1.0;
        double crvotes, xx;
        for(j = 0; j < 500; ++j)
        {
            med = (lb + rb) / 2.0;
            crscore = s[i] + med * total;
            crvotes = med;
            for(k = 0; k < N; ++k)
            {
                if(k == i) continue;
                xx = (crscore - s[k]) / (double) total;
                if(xx >= 0) crvotes += xx;
                if(crvotes > 1.0) break;
            }
            if(crvotes > 1.0) rb = med;
            else lb = med;
        }
        printf("%.8lf", 100.0 * lb);
        if(i == N - 1) printf("\n");
        else printf(" ");
    }
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
