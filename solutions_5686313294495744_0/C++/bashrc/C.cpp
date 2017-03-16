#include <assert.h>
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

bool validate(vector<pair<string, string>> fake, vector<pair<string, string>> gen){
	map<string, int> frst;
	map<string, int> scnd;
	for (auto &v : gen){
		++frst[move(v.first)];
		++scnd[move(v.second)];
	}
	for (auto &x : fake){
		auto iter = frst.find(x.first);
		if (iter == frst.end()) return false;
		auto iter2 = scnd.find(x.second);
		if ((iter2== scnd.end())) return false;
	}
	return true;
}
auto Solve(const vector<pair<string, string>> &values){
	size_t mx = 0;
	for (int i = 0, sz = values.size(); i < (1<<(sz)); ++i){
		vector<pair<string,string>> fake;
		vector<pair<string, string>> gen;
		int tmp = i;
		int cntr = 0;
		while (cntr < sz){
			if (tmp &1){
				gen.push_back(values[cntr]);
			}else{
				fake.push_back(values[cntr]);
			}
			tmp>>=1;
			++cntr;
		}
		auto cnt = fake.size();
		assert(cnt + gen.size() == values.size());
		if (validate(fake, gen)) mx = max(mx, cnt);
	}
	return mx;
}

int main(){
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 1; i <= t; ++i){
		int N;
		cin >> N;
		vector<pair<string, string>> values(N);
		for (size_t idx = 0; idx < N; ++idx) { cin >> values[idx].first >> values[idx].second;}
		cout << "Case #" << i << ": "<<Solve(values)<<endl;
	}
}