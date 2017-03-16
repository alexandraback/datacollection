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

void solve_case(int case_id)
{
    cout << "Case #" << case_id << ": ";
    int i, cr, smax, standing = 0;
    int ans = 0;
    string s;
    cin >> smax >> s;
    for(i = 0; i <= smax; ++i) {
        int cr = s[i] - '0';
        if(cr == 0) {
            continue;
        }
        if(standing < i) {
            ans += (i - standing);
            standing = i + cr;
        } else {
            standing += cr;
        }
    }
    cout << ans << '\n';
}

int main()
{
    int i, t;
    cin >> t;
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
