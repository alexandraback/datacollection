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
		int best_by_sur = 0;
        int res = 0;
        int n, max_sur, p;
        cin >> n >> max_sur >> p;
        int i;
        for(i = 0; i < n; i++){
            int score;
            cin >> score;
            if((score+2)/3 >= p) res++;
            else{
                if(score == 0) continue;
                if(score%3 == 1) continue;
                else if(score%3 == 0){
                    if(score/3 + 1 >= p) best_by_sur++;
                }else{
                    if(score/3 + 2 >= p) best_by_sur++;
                }
            }
        }

		printf("Case #%d: ", z+1);
		printf("%d\n", res + min(best_by_sur, max_sur));
	}
}
