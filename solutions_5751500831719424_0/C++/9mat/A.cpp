#include <iostream>
#include <cstdlib> 
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

#define FOR(i,n) for(int i = 0, _n = (n); i < _n; i++)

using namespace std;

void split(const string &s, string &ss, vector<int> &count){
	FOR(i, s.size()){
		if(i==0 || s[i] != s[i-1]){
			ss += s[i];
			count.push_back(1);
		} 
		else count[count.size()-1]++;
	}
}

int move( vector<vector<int> > & a){
	vector<int> med(a.size());
	int sum = 0;
	
	FOR(i, a.size()){
		sort(a[i].begin(), a[i].end());
		int med = a[i][a[i].size()/2];
		FOR(j, a[i].size()) sum += abs(a[i][j] - med);
	}
	
	return sum;
}

int main(){	
	int T;
	cin >> T;
	
	FOR(caseno, T){
		int N, flag = false;
		cin >> N;
		
		vector<string> s(N), ss(N);
		vector< vector<int> > count(N);
		
		FOR(i, N) cin>>s[i];
		FOR(i, N) split(s[i], ss[i], count[i]);
		
		// FOR(i, N){
			// cout<<i<<": ";
			// FOR(j, count[i].size())
				// cout<<count[i][j]<<" ";
			// cout<<endl;
		// }
		
		FOR(i, N) if(ss[i].compare(ss[0]) != 0){
			flag = true;
			break;
		}
		
		vector<vector<int> > count2(count[0].size(), vector<int>(count.size()));
		FOR(i, count.size()) FOR(j, count[0].size()) count2[j][i] = count[i][j];
		
		if(flag) cout<<"Case #"<<caseno+1<<": Fegla Won"<<endl;
		else cout<<"Case #"<<caseno+1<<": "<<move(count2)<<endl;
	}
	
	return 0;
}