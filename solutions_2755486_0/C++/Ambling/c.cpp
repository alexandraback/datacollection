#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long lint;

class tribe{
public:
    int d, n, w, e, s, dd, dp, ds;
    tribe(int d, int n, int w, int e, int s, int dd, int dp, int ds)
    :d(d), n(n), w(w), e(e), s(s), dd(dd), dp(dp), ds(ds)
    {}
};

class attack{
public:
    int d, w, e, s;
    attack(int d, int w, int e, int s)
    :d(d), w(w), e(e), s(s)
    {}
};

bool cmp(const attack &a, const attack &b)
{
    return a.d < b.d;
}

bool check(const std::vector<attack> & att, int begin, int now, int w, int e, int s, int d)
{
    if(w >= e){
        return false;
    }
    for (int i = begin; i < now; ++i)
    {
        if (att[i].d<d && att[i].s >= s && att[i].e >= w && att[i].w <= e)
        {
            if(att[i].w >= w && att[i].e <= e)
            {
                return check(att, i+1, now, w, att[i].w, s, d) 
                        || check(att, i+1, now, att[i].e, e, s, d);
            }
            else if (att[i].w >= w)
            {
                return check(att, i+1, now, w, att[i].w, s, d);
            }
            else if (att[i].e <= e)
            {
                return check(att, i+1, now, att[i].e, e, s, d);
            } else {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // freopen("c2.in", "r", stdin);
    // freopen("c2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);

        int N;
        cin>>N;

        std::vector<tribe> tribes;
        std::vector<attack> attacks;
        for (int i = 0; i < N; ++i)
        {
            int d, n, w, e, s, dd, dp, ds;
            cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
            tribes.push_back(tribe(d, n, w ,e ,s ,dd ,dp, ds));

            int day = d;
            int west = w;
            int east = e;
            int stren = s;
            for (int j = 0; j < n; ++j)
            {
                attacks.push_back(attack(day, west, east, stren));
                day += dd;
                west += dp;
                east += dp;
                stren += ds;
            }
        }

        sort(attacks.begin(), attacks.end(), cmp);

        int cnt = 0;
        for (int i = 0; i < attacks.size(); ++i)
        {
            // cout<<attacks[i].d<<" "<<attacks[i].w<<" "<<attacks[i].e<<" "<<attacks[i].s<<endl;
            if (check(attacks, 0, i, attacks[i].w, attacks[i].e, attacks[i].s, attacks[i].d))
            {
                cnt++;
                // cout<<"succ"<<endl;
            } else {
                // cout<<"fail"<<endl;
            }
        }
        cout<<cnt;

        printf("\n");
    }
    
    return 0;
}
