#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

string N;
string M;

string add(string s){
	string t=s;
	for(int i=s.size()-1; i >= 0; --i){
		if(s[i] == '9'){
			t[i]='0';
		}
		else{
			++t[i];
			return t;
		}
	}
	t="1" + t;
	return t;
}

string rev(string s){
	string t;
	for(int i=s.size()-1; i >= 0; --i)
		t.push_back(s[i]);
	return t;
}

void solve(){
	cin >> N;
	cout << N << endl;
	int nz=0;
	for(int i=N.size()-1; i >= 0; --i){
		if(N[i] != '0'){
			nz=i;
			break;
		}
	}
	int ans=0;
	if(nz*2 < N.size() && (nz || N[0] != '1')){
		++ans;
		for(int i=N.size()-1; i >= 0; --i){
			if(N[i] == '0')
				N[i]='9';
			else{
				--N[i];
				break;
			}
		}
	}
	M="1";
	while(true){
		if(M.size() < N.size()){
			bool ok=1;
			for(int i=0; i < M.size(); ++i){
				if(M[i]!= '9')
					ok=0;
			}
			if(ok){
				M=add(M);
				++ans;
				continue;
			}
			bool any=0;
			for(int i=M.size()/2; i < M.size(); ++i)
				if(M[i] != '9') {
					M=add(M);
					++ans;
					any=1;
					break;
				}
			if(!any){
				M=rev(M);
				++ans;
			}
		}
		else{
			//cout << M << endl;
			bool ok=1;
			int badpos;
			for(int i=0; i < M.size(); ++i){
				if(M[i]!= N[i]){
					ok=0;
					badpos=i;
					break;
				}
			}
			if(ok){
				printf("%d\n", ans+1);
				return;
			}
			if(badpos >= M.size()/2){
				M=add(M);
				++ans;
				continue;
			}
			/*if(rev(add(M)) > N){
				M=rev(M);
				++ans;
				continue;
			}
			M=add(M);
			++ans;*/
			bool any=0;
			for(int i=M.size()/2; i < M.size(); ++i)
				if(M[i] != N[M.size()-i-1]) {
					M=add(M);
					++ans;
					any=1;
					break;
				}
			if(!any){
				/*if(rev(M) > N){
					M=add(M);
					++ans;
				}
				else{*/
					M=rev(M);
					++ans;
				//}
			}
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
