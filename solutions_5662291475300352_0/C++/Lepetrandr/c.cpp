#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}


double eps = 1e-13;

void init()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
}

int sol(){	
    int n, D, h, f;
    struct Hiker { double x; double v;};
    vector<Hiker> hs;
    cin >> n;
    FOR(i,0,n-1) {
        cin >> D >> h >> f;
        FOR(j,0,h-1) {
            hs.push_back({D / 360., (f + j)});
        }
    }
    ass(hs.size() <= 2);
    
    int c = hs.size();
    
    if (c < 2) return 0;
    
    
    
    
    vector<vector<double>> ts;
    FOR(i,0,1) {
        ts.push_back(vector<double>(c));
        FOR(j,0,c-1) {
            ts[i][j] = (i + 1. - hs[j].x) * hs[j].v;
        }
    }
    
    if (ts[1][0] > ts[0][1] + eps && ts[1][1] > ts[0][0] + eps) {
        return 0;
    }
    return 1;
}
int main()
{
    int T;
	init();
    cin >> T;
    FOR(t,1,T) {
        cout << "Case #" << t << ": " << sol() << endl;
    }
	return 0;
}