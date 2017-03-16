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
    string s;
    cin >> s;
    int n = s.length();
    string t;
    rep(i,n) {
        if(t.length()==0) {
            t += s[i];
        } else if(t[0] > s[i]) {
            t += s[i];
        } else if(t[0] <= s[i]){
            t = s[i] + t;
        }
    }
    cout << t << endl;
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
