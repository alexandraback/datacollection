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
		int N;
		cin>>N;
		vector <int> a(2525,0);
		for(int i=0;i<2*N-1;i++){
			for(int j=0;j<N;j++){
				int height;
				cin>>height;
				a[height]++;
			}
		}

		vector <int> ans;
		for(int i=0;i<2525;i++){
			if(a[i]%2) ans.push_back(i);
		}
		sort(ans.begin(),ans.end());

		cout<<cs(t);
		for(int i=0;i<N;i++){
			cout<<ans[i];
			if(i!=N-1) cout<<' ';
		}
		cout<<endl;
	}

	return 0;
}
