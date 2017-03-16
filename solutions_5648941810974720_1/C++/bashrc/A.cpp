#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <array>
#define PR(x) cout<<#x<<"="<<x<<endl
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RP(i,a) for(int i=0;i<a;i++)
#define tr(iter,container) for(auto iter = container.begin();iter!=container.end();iter++) 
#define S(x) cin>>x
#define PRARR(x,n) for(int i=0;i<n;i++) cout<<#x<<"["<<i<<"]= "<<x[i]
#define rd(arr,i,n) for(int i=0;i<n;i++) cin>>arr[i]
#define PB push_back
#define SUM(arr,n,sum) {sum=0;for(int i=0;i<n;i++) sum+=arr[i]; }
#define VC vector
#define CLR(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

auto Solve(const string &s){
	vector<int> hash(256, 0);
	for (auto x  : s){
		++hash[x];
	}
	vector<int> cnt(10);
	cnt[0] = hash['Z'];
	cnt[2] = hash['W'];
	cnt[4] = hash['U'];
	cnt[6] = hash['X'];
	cnt[8] = hash['G'];
	cnt[1] = hash['O'] - cnt[0] - cnt[2] - cnt[4];
	cnt[3] = hash['H'] -  cnt[8];
	cnt[5] = hash['F'] - cnt[4];
	cnt[7] = hash['V'] - cnt[5];
	cnt[9] = hash['I'] - cnt[5] - cnt[6] - cnt[8];
	string value;
	for (int i = 0; i <=9 ; ++i){
		for (int j = 0; j < cnt[i]; ++j) value.push_back(i + '0');
	}
	return value;
}

int main(){
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 1; i <= t; ++i){
		string s;
		cin >> s;
		cout << "Case #" << i << ": "<<Solve(s)<<endl;
	}
}