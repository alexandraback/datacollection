#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

typedef vector< vector<int> > Graph;



int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int N, M; cin >> N >> M;
		Graph g(N);
		vector<string> vs(N);
		vector<int> state(N, 0);
		for(int i=0;i<N;i++) cin >> vs[i];
		for(int i=0;i<M;i++){
			int a, b; cin >> a >> b;
			g[a-1].push_back(b-1);
			g[b-1].push_back(a-1);
		}
		string res = "Z";
		vector<int> order(N);
		for(int i=0;i<N;i++) order[i] = i;
		do{
			bool valid = true;
			stack<int> st;
			st.push(order[0]);
			for(int i=1;i<N;i++){
				while(true){
					if(st.empty()){
						valid = false;
						break;
					}
					int pos = st.top();
					bool ok = false;
					for(int j=0;j<g[pos].size();j++){
						if(g[pos][j] == order[i]) ok = true;
					}
					if(ok){ st.push(order[i]); break; }
					else st.pop();
				}
				if(!valid) break;
			}
			if(valid){
				string str;
				for(int i=0;i<N;i++) str += vs[order[i]];
				res = min(res, str);
			}
		}while(next_permutation(order.begin(), order.end()));
		printf("Case #%d: %s\n", test, res.c_str());
	}
}
