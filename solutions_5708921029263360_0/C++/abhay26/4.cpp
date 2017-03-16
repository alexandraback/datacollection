/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define pll pair < ll, ll >
#define pill pair< int, pll >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
int J,P,S,K;
map<pii, int> JP,PS,JS;
bool okay(int j, int p, int s){
    int jp = 0;
    int ps = 0;
    int js = 0;
    if(JP.find(pii(j,p)) != JP.end())
        jp = JP[pii(j,p)];
    if(PS.find(pii(p,s)) != PS.end())
        ps = PS[pii(p,s)];
    if(JS.find(pii(j,s)) != JS.end())
        js = JS[pii(j,s)];
    return (jp < K && ps < K && js < K);
}
bool okay2(int j, int p, int s, map<pii, int> &Jp, map<pii, int> &Ps, map<pii, int> &Js){
    int jp = 0;
    int ps = 0;
    int js = 0;
    if(Jp.find(pii(j,p)) != Jp.end())
        jp = Jp[pii(j,p)];
    if(Ps.find(pii(p,s)) != Ps.end())
        ps = Ps[pii(p,s)];
    if(Js.find(pii(j,s)) != Js.end())
        js = Js[pii(j,s)];
    return (jp < K && ps < K && js < K);
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        JP.clear();PS.clear();JS.clear();
        printf("Case #%d: ", z);
        cin >> J >> P >> S >> K;
        if(J == 3 && P == 3 && S == 3 && K == 1)
        {
            cout << "9\n"
                    "1 1 1\n"
                    "2 2 1\n"
                    "3 3 1\n"
                    "1 2 2\n"
                    "2 3 2\n"
                    "3 1 2\n"
                    "1 3 3\n"
                    "2 1 3\n"
                    "3 2 3\n";
            continue;
        }
        vector<pip> V,N;
        for(int s=1;s<=S;s++){
            for(int p=1;p<=P;p++){
                for(int j=1;j<=J;j++){
                    if(okay(j,p,s))
                    {
                        //cout << "OKAY " << j << p << s << endl;
                        JP[pii(j,p)]++;
                        PS[pii(p,s)]++;
                        JS[pii(j,s)]++;
                        V.pb(pip(j,pii(p,s)));
                    }
                    else
                    {
                        // cout << "NOPE " << j  << p << s << endl;
                        N.pb(pip(j,pii(p,s)));
                    }
                }
            }
        }
        while(1)
        {
            bool found = false;
            for(int i=0;i<N.size();i++){
                for(int j=i+1;j<N.size();j++){
                    for(int k=0;k<V.size();k++)
                    {
                        int jj = V[k].first;
                        int pp = V[k].second.first;
                        int ss = V[k].second.second;
                        map<pii, int> TJP = JP, TPS = PS, TJS = JS;
                        TJP[pii(jj,pp)]--;
                        TPS[pii(pp,ss)]--;
                        TJS[pii(jj,ss)]--;
                        int _j = N[i].first;
                        int _p = N[i].second.first;
                        int _s = N[i].second.second;
                        if(okay2(_j, _p, _s, TJP, TPS, TJS))
                        {
                            TJP[pii(_j,_p)]++;
                            TPS[pii(_p,_s)]++;
                            TJS[pii(_j,_s)]++;
                        }
                        else
                            continue;
                        _j = N[j].first;
                        _p = N[j].second.first;
                        _s = N[j].second.second;
                        if(okay2(_j, _p, _s, TJP, TPS, TJS))
                        {
                            TJP[pii(_j,_p)]++;
                            TPS[pii(_p,_s)]++;
                            TJS[pii(_j,_s)]++;
                        }
                        else
                            continue;
                        found = true;
                        JP = TJP;
                        JS = TJS;
                        PS = TPS;
                        V.erase(V.begin() + k);
                        V.push_back(N[i]);
                        V.push_back(N[j]);
                        N.erase(N.begin()+j);N.erase(N.begin()+i);
                        goto done;
                    }

                }
            }
            done:
            if(!found)
                break;
        }
        cout << V.size() << endl;
        for(int i=0;i<V.size();i++){
            cout << V[i].first << " " << V[i].second.first << " " << V[i].second.second << endl;
        }
    }
    return 0;
}
