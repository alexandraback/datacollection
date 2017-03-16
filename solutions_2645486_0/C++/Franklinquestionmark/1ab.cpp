//clean version
#include<cmath>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long mint;
typedef mint ans_t;
typedef vector<mint> vi;
typedef vector<vi> vvi;
// typedef map<mint,ans> mi;
// typedef map<mint,mi> mmi;
typedef vi mi;
typedef vvi mmi;

mint e,r,n; //max, recharge, count
vi v;
mmi dyar;
//energy, activity
//returns gain
ans_t rec(mint en, mint ind){
	if(ind == v.size()) //success
		return 0;
	
	en = min(en,e); //cap en
	ans_t& ans = dyar[en][ind];
	
	if(ans)
		return ans;
	
	mint gain = 0;
	
	for(int i=en;i>=0;gain+=v[ind],i-- ){
		ans = max(rec(i+r,ind+1)+gain,ans);
	}
	
	return ans;
}

ans_t solve(){
	return rec(e,0);
}

int main(int argc, char** argv){
	// istringstream cin(R"(3
// 5 2 2
// 2 1
// 5 2 2
// 1 2
// 3 3 4
// 4 1 3 5)");
	
	ifstream cin(argv[1]);
	ofstream cout(string(argv[1])+".out");
	
	int t;
	cin>>t;
	for(int i = 0; i<t; i++){
		//get input
		cin>>e>>r>>n;
		v.resize(n);
		for(mint& x:v)
			cin>>x;
		dyar.clear();
		dyar.resize(e+1,mi(n+1));
		//solve
		ans_t ans = solve();
		
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
	return 0;
}
