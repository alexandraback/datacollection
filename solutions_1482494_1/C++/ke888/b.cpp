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

#define MAXN 1000000
int stages[1000][2];
int n;

int main() {
	int zz;
	cin >> zz;
	FOR(z, 0, zz){
        cin >> n;
        FOR(i, 0, n){
            int a, b;
            cin >> a >> b;
            stages[i][0] = a;
            stages[i][1] = b;
        }
        int cur = 0;
        vector <int> st1(n,0);
        vector <int> st2(n,0);
        int cnt = 0;
        while(cur < n * 2){
            bool flg = true;
            while(flg){
                flg = false;
                FOR(i,0,n){
                    if(st1[i] == 1 && st2[i] != 1 && stages[i][1] <= cur){
                        cur++;
                        cnt++;
                        st2[i] = 1;
                        flg = true;
                    }
                    if(st1[i] != 1 && stages[i][1] <= cur){
                        cur += 2;
                        cnt++;
                        st1[i] = 1;
                        st2[i] = 1;
                        flg = true;
                    }
                }
            }
            int max_v = -1, max_i;
            FOR(i,0,n){
                if(st1[i] == 0 && stages[i][0] <= cur){
                    if(max_v < stages[i][1]){
                        max_v = max(max_v, stages[i][1]);
                        max_i = i;
                    }
                }
            }
            if(max_v == -1) break;
            else{
                st1[max_i] = 1;
                cur++;
                cnt++;
            }
        }

		printf("Case #%d: ", z+1);
        if(cur < n * 2){
            cout << "Too Bad" << endl;
        }else{
            printf("%d\n", cnt);
        }
	}
}
