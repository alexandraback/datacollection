#include <cmath>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define sz(X) ((int)X.size())
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define fr(i,a,b) for(int i=a; i<=b; i++)
#define it(it) __typeof((it)->begin())
#define foreach(v) for(IT(v) it=(v)->begin(); it!=(v)->end(); it++)
#define all(x) (x).begin(),x.end()
#define pb(x) push_back(x)
#define VI vector<int> 
#define VVI vector<vector<int> >
#define VS vector<string>
typedef long long ll;

double noerror(const vector<double> &vec, int x)
{
    /*
    rep(i,vec.size()-x) {
        ret *= vec[i];
    }
    */
    if (x == vec.size()) return 1.;
    return vec[vec.size()-x-1];
}

int main()
{
    int T;
    cin >> T;
    rep(zz,T) {
        double ret;
        int A, B;
        cin >> A >> B;
        ret = B+2.;
        vector<double> vec(A);
        double t1;
        rep(i,A) {
            cin >> t1;
            if (i!=0)
                vec[i] = vec[i-1]*t1;
            else 
                vec[i] = t1;
        }
        

        for(int x=0; x<=A; x++) {
            double tmp = (2*x+(B-A)+1);
            tmp += (B+1)*(1-noerror(vec,x));
            if (ret > tmp) ret = tmp;
        }


        printf("Case #%d: %.6lf\n", zz+1, ret);
    }
}
