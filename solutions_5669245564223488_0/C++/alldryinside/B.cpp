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

int N;
string s[110];

void small()
{
    int i, j, perm[12];
    for(i = 0; i < N; ++i) perm[i] = i;
    string u;
    int lo[26], t;
    bool ok;
    int ways = 0;
    do
    {
        u = "";
        for(i = 0; i < N; ++i) u += s[perm[i]];
        for(i = 0; i < 26; ++i) lo[i] = -1;
        ok = true;
        for(i = 0; i < u.length(); ++i)
        {
            t = u[i] - 'a';
            if(lo[t] == -1) lo[t] = i;
            else
            {
                if(lo[t] != i - 1)
                {
                    ok = false;
                    break;
                }
                lo[t] = i;
            }
        }
        if(ok) ++ways;
    } while(next_permutation(perm, perm + N));
    cout << ways << '\n';
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> s[i];
    small();
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
