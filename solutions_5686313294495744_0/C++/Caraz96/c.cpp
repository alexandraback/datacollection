#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int N;
vector<string> a,b;

int solve(int how){
	set<string> A, B;
	vector<bool> used(3000,false);
	int H=how, k=0, tot=0;
	while(H>0){
		//cout << H << endl;
		if(H&1){
			A.insert(a[k]);
			B.insert(b[k]);
			used[k]=true;
			tot++;
		}
		H>>=1;
		k++;
	}
//	for( auto j: A )cout << j << " ";
	for(k=0;k<N;k++){
		if(!used[k])
			if(A.find(a[k])==A.end() || B.find(b[k])==B.end())return 0;
	} return a.size()-tot;
}

int main(){
	int T, tt;
	string s1, s2;
	cin >> T;
	for( tt = 1; tt <= T; tt++ ){
		int ans=0;
		a.clear(); b.clear();
		printf( "Case #%d: ", tt );
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> s1 >> s2;
			a.push_back(s1);
			b.push_back(s2);
		}
		for(int i=0;i<(1<<(N));i++){
			//cout << "---------";
			//cout << i << " " << solve(i) << endl;
			ans = max(ans,solve(i));
		} cout << ans << endl;
	}
	return 0;
}
