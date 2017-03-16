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

string cs(int n){ return "Case #"+to_string(n)+":"; }

int main() {
	io();
	int T;
	cin>>T;

	for(int i=1;i<=T;i++){
		int N,J;
		cin>>N>>J;
		int num=N/2;
		cout<<cs(i)<<endl;
		for(int j=0;j<J;j++){
			string s="";
			int tmp=j;
			for(int k=0;k<num-2;k++,tmp/=2) s=to_string(tmp%2)+s;
			s=to_string(1)+s+to_string(1);
			cout<<s<<s;
			for(int p=2;p<=10;p++){
				long long t=1;
				long long val=0;
				for(int q=s.size()-1;q>=0;q--){
					val+=t*(s[q]-'0');
					t*=p;
				}
				cout<<' '<<val;
			}
			cout<<endl;
		}
	}


	return 0;
}
