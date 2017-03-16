#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<utility>

using namespace std;

#define PB push_back
#define LE length()
#define SZ size()
#define MP make_pair
#define X first
#define Y second

bool connect(string &a, string &b){
	return a[int(a.LE)-1] == b[0];
}

int comb(vector<string> &vs, vector<int> &vi, int p, bool connected){
	if(p +1 == int(vs.size())){
		if(connected) return 1;	
		else return 0;
	}
	if(p == 0){
		if(connect(vs[vi[0]], vs[vi[1]]))
			return comb(vs, vi, p+1, true);
		else return 0;
	}

	int res = 0;
	if(connect(vs[vi[p]], vs[vi[p+1]])){
		res += comb(vs, vi, p+1, true) + comb(vs, vi, p+1, false);
	}
	else if(!connected) return 0;
	else res+= comb(vs, vi, p+1, false);

	return res;
}

int main(){
	int kases; cin>>kases;
	for(int kase = 1; kase <= kases;kase++){
		int N; cin>>N;
		vector<string> vs;
		vector<int> pr;
		string s;
		for(int i=0;i<N;i++){
			cin>>s;
			vs.PB(s);
			pr.PB(i);
		}
		//sort(vs.begin(),vs.end());
		
		int res = 0;
		do{
			res += comb(vs, pr,0,false);
		}while(next_permutation(pr.begin(), pr.end()));		

		cout<<"Case #"<<kase<<": "<<res<<endl;
	}
}
