#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Ford(i, a, b) for(int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

#define gcj(ans) {cout << "Case #" << (test) << ": " << (ans) << endl;}

vector< pair<int, int> > v;
bool done1[1111], done2[1111];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    int TEST; scanf("%d", &TEST);
    
    for(int test = 1; test <= TEST; test++)
    {
        int level; cin >> level;
        
        v.clear();
        Rep(i, level) 
        {
            int a, b; cin >> a >> b;
            v.pb(MP(a, b));
        }
        
        memset(done1, 0, sizeof done1);
        memset(done2, 0, sizeof done2);
        int num = 0;
        int res = 0;
        for(int i = 0; i < 3000; i++)
        {
            bool can = false;
            for(int k = 0; k < level; k++)
                if(!done2[k] && num >= v[k].se)
                {
                    done2[k] = true;
                    can = true;
                    if(done1[k]) num++;
                    else num += 2;
                    res++;
                }
            if(!can)
            {
                int diff = -1, j = -1;
                for(int k = 0; k < level; k++)
                    if(!done1[k] && !done2[k] && num >= v[k].fi)
                    {
                        if(v[k].se - v[k].fi > diff)
                        {
                            diff = v[k].se - v[k].fi;
                            j = k;
                        }
                    }
                if(j == -1) break;
                
                //cout << "test " << j << endl;
                done1[j] = true;
                num++;
                res++;
            }
        }        
        bool ok = true;
        for(int i = 0; i < level; i++) if(!done2[i]) ok = false;
        if(!ok) gcj("Too Bad")
        else gcj(res)
    }
}
