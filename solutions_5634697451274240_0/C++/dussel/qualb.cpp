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
	for(int i=1;i<=T;i++){
		string s;
		cin>>s;

		int cnt=1;
		for(int j=1;j<s.size();j++){
			if(s[j]!=s[j-1]) cnt++;
		}
		if((s[0]=='-' && cnt%2==1) || (s[0]=='+' && cnt%2==0)){
			cout<<cs(i)<<cnt<<endl;
		}else{
			cout<<cs(i)<<cnt-1<<endl;
		}
	}
	return 0;
}
