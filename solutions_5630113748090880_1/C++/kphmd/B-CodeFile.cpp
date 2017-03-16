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
    int n;
    cin >> n;
    vector<vector<int> > bd(n+n-1,vector<int>(n));
    rep(i,n+n-1) {
        rep(j,n) cin >> bd[i][j];
    }
    
    // sort(bd.begin(),bd.end());
    // vector<int> idx(n+n-1);
    
    // vector<vector<int> > gd(n,vector<int>(n,0));
    // vector<vector<int> > mask(n,vector<int>(n,0));
    
    vector< vector<int> > cnts(n,vector<int>(2501,0));
    vector< int > dp(2501,0);
    rep(i,n+n-1) {
        rep(j,n) {
            cnts[j][bd[i][j]]++;
            dp[bd[i][j]]++;
        }
    }
    
    vector<int> ans;
    rep(i,2501) {
        if(dp[i]%2==1) ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    
    rep(i,ans.size()-1) cout << ans[i] << " ";
    cout << ans.back() << endl;
    
    
    
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
