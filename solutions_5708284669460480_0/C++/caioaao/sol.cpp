#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

string targ, keyb;
int sLen;

// int maxOverlap()
// {
//     bool ok;
//     for(size_t i = 1; i < targ.sz(); ++i)
//     {
//         ok = true;
//         for(size_t j = 0, k = i; k < targ.sz(); ++k, ++j)
//         {
//             if(targ[k] != targ[j])
//             {
//                 ok = false;
//                 break;
//             }
//         }
// 
//         if(ok) return targ.sz() - i;
//     }
//     return 0;
// }
// 
// int minBananasWc()
// {
//     int left = sLen - targ.sz();
//     return left / (targ.sz() - maxOverlap()) + 1;
// }

string str;
L nCombs;
L nBananas;
L maxB;

L countTargs()
{
    int ret = 0;
    bool ok;
    for(int i = 0; i < sLen; ++i)
    {
        ok = true;
        for(int j = 0, k = i; j < (int)targ.sz(); ++j, ++k)
        {
            if(k >= sLen || targ[j] != str[k])
            {
                ok = false;
                break;
            }
        }
        if(ok) ++ret;
    }
    return ret;
}

void bt(int id)
{
    if(id < sLen)
    {
        for(int i = 0; i < (int)keyb.sz(); ++i)
        {
            str[id] = keyb[i];
            bt(id+1);
        }
    }
    else
    {
        L cnt = countTargs();
        maxB = max(maxB, cnt);
        ++nCombs;
        nBananas += cnt;
    }
}




void solve()
{
    int kLen, lLen;
    cin >> kLen >> lLen >> sLen;
    cin >> keyb;
    cin >> targ;
    nCombs = 0;
    nBananas = 0;
    maxB = 0;
    bt(0);
    double ans = (nCombs * maxB - nBananas) / (double)nCombs;
    cout << fixed << setprecision(10) << ans << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}
