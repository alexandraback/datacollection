#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long int in;
typedef vector<vector<bool> > GT;
typedef vector<in> VI;
typedef vector<bool> VB;
typedef stack<in> SI;
void testcase() {
	in N, M; cin >> N >> M;
	vector<string> codes;
	for(in i=0; i<N; i++) {
		string s; cin>>s;
		codes.PB(s);
	}
	GT G = GT(N,VB(N,false));
	for(in m=0; m<M; m++) {
		in a,b; cin >> a >> b; a--; b--;
		G[a][b] = true;
		G[b][a] = true;
	}
	VI P;
	for(in n=0; n<N; n++) P.PB(n);

	string opt,cur;
	for(in it=0; it<50000; it++) {
		SI S;
		cur = "";
		bool ok = true;
		for(in i=0; i<N; i++) {
			// cout << "P[" << i <<"] = " << P[i] << endl;
			if(i>0) {
				bool link = true;
				bool done = false;
				while(!done) {
					if(S.size()==0) {link=false; done=true;}
					else {
						if(G[S.top()][P[i]]) {link=true; done=true;}
						else S.pop();
					}
				}
				if(!link) ok = false;
			}
			S.push(P[i]);
			cur += codes[P[i]];
		}
		if(ok &&(opt.size()==0 || cur<opt)) {
			// cout << "new opt  " << cur << endl;
			opt = cur;
		}
		next_permutation(P.begin(),P.end());
	}
	cout << opt;
}

int main() {
	in T;
	cin >> T;
	for(int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		testcase();
		cout << endl;
	}
}