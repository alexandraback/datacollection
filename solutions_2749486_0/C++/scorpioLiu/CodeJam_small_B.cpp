#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

//BEGINTEMPLATE_BY_SCORPIOLIU
const double PI  = acos(-1.0);
const double EPS = 1e-11;
const double INF  = 1E200;

typedef long long int64;
typedef unsigned long long uint64;

typedef pair<int,int> ipair;
#define MP(X,Y) make_pair(X,Y)
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

#define REP(i,a) for(int i=0;i<int(a);++i)
#define REP2(i,n,m) for(int i=n;i<(int)(m);++i)
#define FORE(it,a) for (typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define ALL(a) (a).begin(),(a).end()
//ENDEMPLATE_BY_SCORPIOLIU

#define SMALL
//#define LARGE

int main()
{
#ifdef SMALL
    //ifstream fin("B-small-practice.in");ofstream fout("B-small-practice.out");
    //ifstream fin("B-small-attempt0.in");ofstream fout("B-small-attempt0.out");
    freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
#endif
#ifdef LARGE
    //ifstream fin("B-large-practice.in");ofstream fout("B-large-practice.out");
    //ifstream fin("B-large.in");ofstream fout("B-large.out");
    freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
#endif
    int Z;
    cin>>Z;
    REP(z,Z)
    {

        cout<<"Case #"<<z+1<<": ";
        //////////////////////////////////////
        int x, y;
        cin>>x>>y;
        string res = "";
        int sx = 0, sy = 0;
        int step  = 1;
        while (sx != x) {
            if (sx < x) {
                if (sx + step <= x) {
                    sx += step;
                    res += "E";
                } else {
                    sx -= step;
                    res += "W";
                }
            } else {
                if (sx - step >= x) {
                    sx -= step;
                    res += "W";
                } else {
                    sx += step;
                    res += "E";
                }
            }
            step += 1;
        }
        while (sy != y) {
            if (sy < y) {
                if (sy + step <= y) {
                    sy += step;
                    res += "N";
                } else {
                    sy -= step;
                    res += "S";
                }
            } else {
                if (sy - step >= y) {
                    sy -= step;
                    res += "S";
                } else {
                    sy += step;
                    res += "N";
                }
            }
            step += 1;
        }
        cout<<res;
        //////////////////////////////////////
        cout<<endl;
    }
    return 0;
}
