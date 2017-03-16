#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define eps (1e-9)
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>
#define xx first
#define yy second
#define equal(a,b) (ABS(a-b)<eps)
using namespace std;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }

/////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    int t;
    freopen("rec.in", "r", stdin);
    freopen("rec.out", "w", stdout);
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int a, b, ret = 0;
        map< Pair, bool >m;
        scanf("%d%d", &a, &b);
        for(int j=a; j<=b; j++){
                string s = tostring(j);
                int l = s.length()-1;
                int k = 1;
                while(k<=l){
                    string r = "";
                    for(int u=k; u<=l; u++)
                        r += s[u];
                    for(int u=0; u<k; u++)
                       r += s[u];
                    int ne = toint(r);
                    if(ne>=a&&ne<=b&&ne!=j){
                        if(ne<j)m[ mp(ne, j) ]=1;
                        else m[ mp(j, ne) ] = 1;
                                            //ret++;
                    }
                    k++;
                }
        }
        printf("Case #%d: %d\n", i, m.size());
    }
return 0;
}
