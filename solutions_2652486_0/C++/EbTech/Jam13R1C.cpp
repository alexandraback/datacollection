#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ll> pt;

int T, R, N, M, K, fact[13];
map<string,ld> prior;
map<pair<string,ll>,ld> joint;

void dfsPrior(string cur, int next = 2)
{
    if (cur.length() < N)
    {
        for (int i = next; i <= M; ++i)
            dfsPrior(cur + char('0'+i), i);
    }
    else
    {
        int c[9];
        memset(c, 0, sizeof c);
        for (int i = 0; i < cur.length(); ++i)
            ++c[cur[i]-'0'];
        ld w = 1;
        for (int i = 2; i <= M; ++i)
            w /= fact[c[i]];
        prior[cur] = w;
        ll p[1<<12];
        joint[make_pair(cur, p[0] = 1)] += 1;
        for (int i = 1; i < 1<<N; i <<= 1)
        for (int j = 0; j < i; ++j)
        {
            joint[make_pair(cur, p[i|j] = (cur[i]-'0')*p[j])] += 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    fact[0] = 1;
    for (int i = 1; i < 13; ++i)
        fact[i] = i*fact[i-1];
    cin >> T >> R >> N >> M >> K;
    dfsPrior("");
    cout << "Case #1:" << endl;
    while (R--)
    {
        map<string,ld> post = prior;
        for (int i = 0; i < K; ++i)
        {
            ll prod;
            cin >> prod;
            for (map<string,ld>::iterator itr = post.begin(); itr != post.end(); )
            {
                map<pair<string,ll>,ld>::iterator itr2 = joint.find(make_pair(itr->first, prod));
                if (itr2 == joint.end())
                {
                    ++itr;
                    //post.erase(itr++);
                }
                else
                    itr->second *= itr2->second, ++itr;
            }
        }
        map<string,ld>::iterator best = post.begin();
        for (map<string,ld>::iterator itr = post.begin(); itr != post.end(); ++itr)
        {
            //cout << itr->first << ' ' << itr->second << endl;
            if (best->second < itr->second)
                best = itr;
        }
        cout << best->first << endl;
    }
}
