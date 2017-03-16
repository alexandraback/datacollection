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

struct st{
	int a;
	int b;
	int c;
	explicit st(int x, int y, int z) : a(x), b(y),c(z){}
	bool operator<(const st& rhs) const { return tie(a,b,c) < tie(rhs.a, rhs.b, rhs.c); }
};

string padAndConvert(int value, const string &v){
	string x = to_string(value);
	if (x.size() > v.size()) return string{};
	string X;
	for (size_t i = 0; i < v.size() - x.size(); ++i) X.push_back('0');
	X += x;
	return X;
}

bool validate(int value , const string &v){
	string X = padAndConvert(value, v);
	if (X.empty()) return false;
	for (size_t idx = 0; idx < v.size(); ++idx){
		if (v[idx] == '?') continue;
		if (X[idx] != v[idx]) return false;
	}
	return true;
}


auto Solve(string &s, string &c){
	int digits = s.size();
	auto mn =  st(1000000000,10000000,100000);
	for (int first = 0; first <= 1000; ++first){
		if (validate(first, s)){
			for (int second = 0; second <= 1000; ++second){
				if (validate(second, c)) mn = min(mn, st(abs(second-first), first, second));  
			}
		}
	}
	
	return make_pair(padAndConvert(mn.b, s), padAndConvert(mn.c, c));
}

int main(){
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 1; i <= t; ++i){
		string s,c;
		cin >> s>> c;
		auto v = Solve(s, c);
		cout << "Case #" << i << ": "<<v.first << " " << v.second<<endl;
	}
}