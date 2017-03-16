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

vector<string> digits = {
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string ten0 = "ZWUFGHOXSI";
vector<int> ten1 = {0,2,4,5,8,3,1,6,7,9};

void runCase()
{
    string s;
    cin >> s;
    map<char,int> cnt;
    for(char c : s) cnt[c]++;
    
    map<int,int> ans;
    for(int i = 0; i < (int)ten0.size(); i++) {
        int num = cnt[ten0[i]];
        // cout << ten0[i] << " " << num << endl;
        ans[ten1[i]] = num;
        for(char c : digits[ten1[i]]) {
            cnt[c] -= num;
        }
    }
    
    for(auto & item : ans) {
        rep(i,item.second) {
            cout << item.first;
        }
    }
    cout << endl;
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
