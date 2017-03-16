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

string A;
int n;
vector<int> pos, lens;

bool vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    cin >> A >> n;
    pos.clear(); lens.clear();
    int i, j = 0, L = A.length();
    for(i = 0; i < L; ++i)
    {
        if(!vowel(A[i])) ++j;
        else
        {
            if(j >= n)
            {
                pos.pb(i - j);
                lens.pb(j);
            }
            j = 0;
        }
    }
    if(j >= n)
    {
        pos.pb(L - j);
        lens.pb(j);
    }
    ll ans = 0, ans2 = 0;
    vector<int>::iterator it;
    int l;
    for(i = 0; i < L; ++i)
    {
        it = upper_bound(pos.begin(), pos.end(), i);
        j = (int) (it - pos.begin());
        if(j > 0 && pos[j - 1] <= i)
        {
            l = pos[j - 1] + lens[j - 1] - i;
            if(l >= n)
            {
                ans += (ll) (L - (i + n) + 1);
                //cout << "for " << i << " from " << i + n << '\n';
                continue;
            }
        }
        if(it != pos.end())
        {
            ans += (ll) (L - (pos[j] + lens[j]) + 1);
            //cout << "for " << i << " from " << pos[j] + lens[j] << '\n';
        }
    }
    string cr;
    int u = 0;
    for(i = 0; i < L; ++i)
    {
        for(j = 1; j <= L - i; ++j)
        {
            cr = A.substr(i, j);
            bool ok = false;
            u = 0;
            for(l = 0; l < j; ++l)
            {
                if(!vowel(cr[l])) ++u;
                else u = 0;
                if(u >= n)
                {
                    ok = true;
                    break;
                }
            }
            if(ok || u >= n) {++ans2; /*cout << cr << '\n';*/}
        }
    }
    cout << ans2 << '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
