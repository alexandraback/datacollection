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
        double my_a, you_a, you_b;
        double dist;
        int N, A;
        cin >> dist >> N >> A;
        double prev_t, prev_x, cur_t, cur_x;
        if(N == 2){
            cin >> prev_t >> prev_x >> cur_t >> cur_x;
            you_b = prev_x;
            you_a = (cur_x - prev_x) / cur_t;
        }else{
            cin >> prev_t >> prev_x;
            you_b = dist;
            you_a = 1.0;
        }

		printf("Case #%d:\n", z+1);
        FOR(i, 0, A){
            double res;
            cin >> my_a;
            double a = 0.5 * my_a, b = -1 * you_a, c = -1 * you_b;
            double t = (- b + sqrt(b*b - 4*a*c)) / (2 * a);
            double conf_point = you_a * t + you_b;
            if(conf_point > dist){
                res = sqrt(dist / (0.5 * my_a));
            }else{
                res = (dist - you_b) / you_a;
            }
            printf("%.9f\n", res);
        }

	}
}
