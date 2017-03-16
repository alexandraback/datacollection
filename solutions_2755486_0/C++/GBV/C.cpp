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

struct attack
{
    int time;
    int fr, to;
    int strength;
};
attack ma(int t, int w, int e, int s)
{
    attack m;
    m.time = t; m.fr = w; m.to = e; m.strength = s;
    return m;
}

const int MAXN = 100007, OFF = 50000;
int H[MAXN];

bool cmp(attack a, attack b)
{
    return (a.time < b.time);
}

vector<attack> A;

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, k, di, ni, wi, ei, si, ddi, dpi, dsi, N;
    A.clear();
    cin >> N;
    for(i = 0; i < N; ++i)
    {
        cin >> di >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;
        for(j = 0; j < ni; ++j)
        {
            A.pb(ma(di, wi, ei, si));
            di += ddi;
            wi += dpi;
            ei += dpi;
            si += dsi;
        }
    }
    sort(A.begin(), A.end(), cmp);
    //cout << A.size() << '\n';
    int ans = 0;
    for(i = 0; i < MAXN; ++i) H[i] = 0;
    int maxatt = 0;
    vector<pii> toset;
    for(i = 0; i < A.size(); ++i)
    {
        //cout << A[i].time << ' ' << A[i].fr << ' ' << A[i].to << ' ' << A[i].strength << '\n';
        bool ok = false;
        for(j = 2 * A[i].fr; j <= 2 * A[i].to; ++j)
        {
            if(H[j + OFF] < A[i].strength)
            {
                //cout << j << " " << H[j + OFF] << '\n';
                ok = true;
                break;
            }
        }
        if(ok) ++ans;
        if(i < A.size() - 1 && A[i].time != A[i + 1].time)
        {
            maxatt = max(maxatt, A[i].strength);
            toset.pb(mp(A[i].fr, A[i].to));
            //cout << "maxatt = " << maxatt << '\n';
            for(k = 0; k < toset.size(); ++k)
            {
                for(j = 2 * toset[k].x; j <= 2 * toset[k].y; ++j) H[j + OFF] = maxatt;
            }
            maxatt = 0;
            toset.clear();
        }
        else
        {
            maxatt = max(maxatt, A[i].strength);
            toset.pb(mp(A[i].fr, A[i].to));
        }
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
