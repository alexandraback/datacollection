#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define mp make_pair
#define pb push_back
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T,cnt,tmp;
	cin >> T;
	 cnt=1;
	 int N;
	while(T--){
		map<int,int> M;
		map<int,int>::iterator it;
		cin >> N;
		for(int i=0;i<2*N-1;i++){
			for(int j=0;j<N;j++){
				cin >> tmp;
				M[tmp]++;
				M[tmp] %=2;
			}

		}
		cout << "Case #" << cnt++ << ": ";
		vector<int> ans;
		for(it= M.begin();it!=M.end();it++){
			if(it->second == 1)
				cout << it->first << " ";
		}
		cout << endl;
	}

	return 0;
}