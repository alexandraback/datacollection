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

int A, B, K;

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    cin >> A >> B >> K;
    int i, j, ans = 0;
    for(i = 0; i < A; ++i)
        for(j = 0; j < B; ++j)
        {
            if((i & j) < K) ++ans;
        }
    cout << ans << '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
