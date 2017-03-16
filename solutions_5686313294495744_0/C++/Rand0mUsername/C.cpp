// RandomUsername (Nikola Jovanovic)
// GCJ 2016 1B
// C

#include <bits/stdc++.h>
#define DBG false
#define debug(x) if(DBG) printf("(ln %d) %s = %d\n", __LINE__, #x, x);
#define lld long long
#define ff(i,a,b) for(int i=a; i<=b; i++)
#define fb(i,a,b) for(int i=a; i>=b; i--)
#define par pair<int, int>
#define fi first
#define se second
#define mid (l+r)/2
#define INF 1000000000
#define MAXLEN 25
#define MAXN 1000

using namespace std;

struct title
{
    string f;
    string s;
};
title a[MAXN];

int n, ret;
int t;

void solve()
{
    unordered_set<string> F;
    unordered_set<string> S;
    ret = 0;
    int MASKS = (1 << n);
    ff(MASK, 0, MASKS - 1)
    {
        // try this mask, set nodes are original
        F.clear();
        S.clear();
        ff(bit, 0, n-1)
        {
            if( (MASK & (1<<bit)) != 0 )
            {
                // bit set, original!
                F.insert(a[bit].f);
                S.insert(a[bit].s);
            }
        }
        bool possible = true;
        // check if possible with fakes
        ff(bit, 0, n-1)
        {
            if( (MASK & (1<<bit)) == 0 )
            {
                //cout<<"try "<<MASK<<" "<<bit<<" "<<endl;
                // bit not set, fake!
                if(F.find(a[bit].f) == F.end())
                {
                    possible = false;
                    break;
                }
                if(S.find(a[bit].s) == S.end())
                {
                    possible = false;
                    break;
                }
            }
        }
        //cout<<"FAIL"<<endl;
        if(possible)
        {
            //cout<<"possible "<<MASK<<endl;
            int curr = n - __builtin_popcount(MASK);
            ret = max(ret, curr);
            //cout<<"!!!"<<curr<<" "<<ret<<endl;
        }
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    scanf("%d", &t);
    ff(tt, 1, t)
    {
        scanf("%d", &n);
        ff(i, 0, n-1)
        {
            cin >> a[i].f;
            cin >> a[i].s;
        }
        solve();
        printf("Case #%d: %d\n", tt, ret);
    }
    return 0;
}