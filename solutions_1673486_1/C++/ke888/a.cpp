#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<(int)b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;
#define debug(x) cerr << #x << " = " << (x) << \
" (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template <class T> void debugall(T a, T b) { cerr << " (L" << __LINE__ << ") "; for(T i = a; i != b; i++) cerr << *i << ", "; cerr << endl; }


int main() {
	int zz;
	cin >> zz;
	FOR(z, 0, zz){
		int a, b;
        cin >> a >> b;
        vector <double> prob(a+1, 1.0);
        int i = 0;
        for(; i < a; i++){
            double tmp;
            cin >> tmp;
            prob[a - i - 1] = prob[a - i] * tmp;
        }
        double res = 1000000.0;
        for(i = 0; i <= a; i++){
            double tmp = 0.0;
            int num_types = 2 * i + (b - a) + 1;
            tmp += prob[i] * num_types;
            tmp += (1.0 - prob[i]) * (num_types + b + 1);
            res = min(res, tmp);
            // debug(prob[i]);
        }
        res = min(res, (double)1 + b + 1);

		printf("Case #%d: ", z+1);
        printf("%.9f\n", res);
	}
}
