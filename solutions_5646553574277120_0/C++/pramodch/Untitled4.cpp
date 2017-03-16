#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &x)
int den[52];

inline void Solve(){
	int c, d, v;
	cin>>c>>d>>v;
	for(int i = 0; i < d; i++){
		sd( den[i] );
	}
	set<int> st;
	for(int i = 0; i < (1 << d); i++){
		int val = 0;
		for(int j = 0; j < d; j++){
			if( (1 << j) & i ){
				val += den[j];
			}
		}
		st.insert(val);
	}
	int ans = 0;
	vector<int> v1;
	for(int i = 1; i <= v; i++){
		if(st.find(i) != st.end()){
			continue;
		}
		ans++;
		v1.clear();
		for(set<int>::iterator it = st.begin(); it != st.end(); it++){
			v1.push_back( (*it) + i );
		}
		for(int j = 0; j < v1.size(); j++){
			st.insert( v1[j] );
		}
	}
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, tt = 0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++tt<<": ";
		Solve();
	}
	return 0;
}
