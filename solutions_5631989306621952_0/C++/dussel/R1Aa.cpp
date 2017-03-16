/* attention to overflow */
#include <bits/stdc++.h>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S,class T> ostream& operator<<(ostream& os, const pair <S,T> &s){return os<<'('<<s.first<<','<<s.second<<')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const double EPS=1e-8;

string cs(int n){ return "Case #"+to_string(n)+": "; }

int main() {
	io();
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		string S;
		cin>>S;
		string ret=S.substr(0,1);
		for(int j=1;j<S.size();j++){
			char top=ret[0];
			if(top-'A'<=S[j]-'A') ret=S[j]+ret;
			else ret=ret+S[j];
		}
		cout<<cs(t)<<ret<<endl;
	}

	return 0;
}
