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

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
    int J,P,S,K;
    cin >> J >> P >> S >> K;
    if(K>=3) {
        cout << J * P * S << endl;
        rep(i,J) rep(j,P) rep(k,S) {
            cout << i+1 << " " << j+1 << " " << k+1 << endl;
        }
    } else if(K==1) {
        cout << J * P << endl;
        rep(i,J) rep(j,P) {
            cout << i+1 << " " << j+1 << " " << 1 << endl;
        }
    } else {
        if(J==1 && P==1) {
            cout << min(2,S) << endl;
            rep(k,S) cout << 1 << " " << 1 << " " << k+1 << endl;
        } else if(J==1 && P==2) {
            S = 2;
            cout << 4 << endl;
            rep(k,S) cout << 1 << " " << 1 << " " << k+1 << endl;
            rep(k,S) cout << 1 << " " << 2 << " " << k+1 << endl;
        } else if(J==1 && P==3) {
            cout << 6 << endl;
            cout << "1 1 1" << endl;
            cout << "1 1 2" << endl;
            cout << "1 2 2" << endl;
            cout << "1 2 3" << endl;
            cout << "1 3 3" << endl;
            cout << "1 3 1" << endl;
        } else if(J==2 && P==2) {
            cout << 8 << endl;
            cout << "1 1 1" << endl;
            cout << "1 1 2" << endl;
            cout << "1 2 1" << endl;
            cout << "1 2 2" << endl;
            cout << "2 1 1" << endl;
            cout << "2 1 2" << endl;
            cout << "2 2 1" << endl;
            cout << "2 2 2" << endl;
        } else if(J==2 && P==3) {
            cout << 12 << endl;
            cout << "1 1 1" << endl;
            cout << "1 1 2" << endl;
            cout << "1 2 2" << endl;
            cout << "1 2 3" << endl;
            cout << "1 3 3" << endl;
            cout << "1 3 1" << endl;
            cout << "2 1 1" << endl;
            cout << "2 1 2" << endl;
            cout << "2 2 2" << endl;
            cout << "2 2 3" << endl;
            cout << "2 3 3" << endl;
            cout << "2 3 1" << endl;
        } else if(J==3) {
            cout << 15 << endl;
            cout << "1 1 1" << endl;
            cout << "1 1 2" << endl;
            cout << "1 2 2" << endl;
            cout << "1 2 3" << endl;
            cout << "1 3 3" << endl;
            cout << "1 3 1" << endl;
            cout << "2 1 1" << endl;
            cout << "2 1 2" << endl;
            cout << "2 2 2" << endl;
            cout << "2 2 3" << endl;
            cout << "2 3 3" << endl;
            cout << "2 3 1" << endl;
            cout << "3 1 3" << endl;
            cout << "3 2 1" << endl;
            cout << "3 3 2" << endl;
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
