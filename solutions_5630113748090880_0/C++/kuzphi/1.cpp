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
int N;
map<int,int> w;
vector<int> ans;
int main(){
	int T;
	cin >> T;
	for (int cas = 1;cas <= T;cas++){
		cout << "Case #"<<cas << ": ";
		cin >> N;
		w.clear();
		for (int i=1;i<=2 * N - 1;i++){			
			for (int j=1;j<=N;j++){
				int x;
				cin >> x;
				w[x] += 1;
			}
		}
		ans.clear();
		map<int,int>::iterator i = w.begin();
		for (;i!=w.end();i++){
			if (i -> second & 1)
				ans.push_back(i->first);
		}
		sort(ans.begin(),ans.end());
		for (int i=0;i<ans.size();i++) cout << ans[i] <<" "; cout << endl;
	}	
}

