//clean version
#include<cmath>
#include<algorithm>
#include<functional>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef int mint;
typedef int ans_t;
typedef vector<mint> vi;
typedef vector<vi> vvi;
typedef map<mint,ans_t> mi;
typedef map<mint,mi> mmi;
// typedef vi mi;
// typedef vvi mmi;
typedef istringstream iss;
typedef ostringstream oss;
typedef stringstream ss;

int a;
int n;
vector<mint> m;

mmi dyar;
ans_t solve(int a,int ind){
	if(ind<0){
		return mint();
	}
	if(a>m.front())
		return 0;
	
	auto it = dyar.find(a);
	if(it != dyar.end()){
		auto it2 = it->second.find(ind);
		if(it2 != it->second.end())
			return it2->second;
	}
	ans_t & ans = dyar[a][ind];
	
	
	if(a > m[ind])
		ans = solve(a+m[ind],ind-1);
	else{
		ans = 1+min(solve(a,ind-1),solve(a*2-1,ind));
	}
	return ans;
}

int main(int argc, char** argv){
	// istringstream cin(R"(4
// 2 2
// 2 1
// 2 4
// 2 1 1 6
// 10 4
// 25 20 9 100
// 1 4
// 1 1 1 1)");
	ifstream cin(argv[1]);
	ofstream cout(string(argv[1])+".out");
	
	int t;
	cin>>t;
	for(int i = 0; i<t; i++){
		//get input
		cin>>a>>n;
		m=vi(n);
		for(auto&x:m)
			cin>>x;
		
		sort(m.begin(),m.end(),greater<mint>());
		dyar.clear();
		
		//solve
		ans_t ans;
		if (a>1)
			ans = solve(a,m.size()-1);
		else ans = m.size();
		
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
		
		// for(auto x:dyar){
			// cerr<<x.first<<endl;
			// for(auto y:x.second){
				// cerr<<'\t'<<y.first<<'\t'<<y.second<<endl;
			// }
		// }
		
	}
	return 0;
}
