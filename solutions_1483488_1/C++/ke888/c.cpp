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

int getD(int a){
    int res = 0;
    while(a != 0){
        res++;
        a /= 10;
    }
    return res;
}

int moveD(int n, int i){
    int p = (int)pow(10, i);
    int d = getD(n);
    int rem = n%p;
    n /= p;
    return n + rem * (int)pow(10, d - i);
}

int main() {
	int zz;
	cin >> zz;
	FOR(z, 0, zz){
		int a, b;
        cin >> a >> b;
        int digits = getD(a);

        int res = 0;
        int k;
        for(k = a; k <= b; k++){
            map <int, bool> m;
            int i;
            for(i = 1; i < digits; i++){
                int tmp = moveD(k, i);
                if(getD(tmp) != digits) continue;
                if(k < tmp && tmp <= b){
                    if(m.find(tmp) != m.end()) continue;
                    res++;
                    m[tmp] = true;
                }
            }
        }
		printf("Case #%d: ", z+1);
		printf("%d\n", res);
	}
}
