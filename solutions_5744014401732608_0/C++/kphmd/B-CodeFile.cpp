#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (int)(n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
    long long B,M;
    cin >> B >> M;
    long long MM = 1;
    MM <<= (B-2);
    if(M>MM) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;
        MM = 1;
        int n = 0;
        for(;;) {
            // if(0==(M&(~(MM-1)))) break;
            if(MM >= M) break;
            MM <<= 1;
            n++;
        }
        
        vector<string> res(B,string(B,'0'));
        res[0][B-1] = '1';
        if(MM == M) {
            for(int i = 0; i < n; i++) {
                res[0][i+1] = '1';
                res[i+1][B-1] = '1';
            }
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j < i; j++) {
                    res[i][j] = '1';
                }
            }
        } else {
            n  --;
            for(int i = 0; i < n; i++) {
                res[0][i+1] = '1';
                res[i+1][B-1] = '1';
            }
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j < i; j++) {
                    res[i][j] = '1';
                }
            }
            
            MM >>= 1;
            M -= MM;
            n++;
            res[0][n] = '1';
            // cout << M << endl;
            for(int i = 1; i < n; i++) {
                if((1&(M>>(i-1)))==1) {
                    res[n][i] = '1';
                }
            }
        }
        
        rep(i,res.size()) {
            cout << res[i] << endl;
        }
        
    }
}

void solve()
{
	int n;
    cin >> n;
	// scanf("%d",&n);
	// getchar();

	for(int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": ";
		// printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}
