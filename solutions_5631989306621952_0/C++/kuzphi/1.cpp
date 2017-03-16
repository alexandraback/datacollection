#include <map>
#include <cmath>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cstring>
#define PB push_back
#define ll long long
#define MP make_pair
#define X first
#define Y second
#define LS k*2,l,mid
#define RS k*2+1,mid+1,r
using namespace std;

const int  Maxn = 300010 , Maxm = 30 , INF = 2100000000 >> 2, Mo = 1e9 + 7;
const double pi = acos(-1.0);
string st , s;
int main(){
	int T;
	cin >> T;
	for (int cas = 1;cas <= T;cas++){
		cout << "Case #"<<cas << ": ";
		cin >> st;
		string ans = "";
		for (int i=0;i<st.size();i++){
			if (ans == ""){
				ans = ans + st[i];
				continue;
			}
			if (st[i] >= ans[0]) ans = st[i] + ans;
			else ans = ans + st[i];
		}
		cout << ans << endl;
	}	
}

