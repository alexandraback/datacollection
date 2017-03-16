// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=false;
const double eps = 1e-8;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

bool is_less(double a, double b) {
    return a < b - eps;
}

void print(vector<int> &v) {
    for(int i=0;i<SZ(v);++i)
        printf("%d ",v[i]);
    puts("");
}

double solve(int val, int sum, vector<int> &v) {
    double lo=0.0;
    double hi=1.0;
    for(int i=0;i<10000;++i) {
        double mid = (hi+lo)/2.0;
        double target = val + sum * mid;
        bool ok=true;
        double rem = 1.0 - mid;
        for(int j=0;j<SZ(v) && ok;++j) {
            double required = (target - v[j])/sum;
            required = max(0.0,required);
            if(required < rem - eps) {
                rem -=required;
            } else {
                ok = false;
                break;
            }
        }
        if(ok) {
            lo=mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

vector<double> solve(vector<int> &v) {
    int sum = accumulate(ALL(v),0);
    vector<double> ans;
    for(int i=0;i<SZ(v);++i) {
        vector<int> nv;
        for(int j=0;j<SZ(v);++j)
            if(i!=j)
                nv.push_back(v[j]);
        ans.push_back(solve(v[i], sum, nv) * 100.0);
    }
    return ans;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        int n;
        scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;++i) {
            scanf("%d",&v[i]);
        }
        vector<double> ans = solve(v);
        printf("Case #%d:",t);
        for(int i=0;i<SZ(ans);++i) {
            printf(" %0.7f",ans[i]);
        }
        puts("");
    }
    return 0;
}

