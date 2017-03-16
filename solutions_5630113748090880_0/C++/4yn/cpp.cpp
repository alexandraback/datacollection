#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
	int tc; cin >> tc;
	for(int t=1;t<=tc;t++){
		cout << "Case #" << t << ": ";
		int n; cin >> n;
		int count[2509]; memset(count,0,sizeof(count));
		int sold;
		for(int i=0;i<(n*2-1)*n;i++){
			cin >> sold;
			count[sold]++;
		}
		vi ans;
		for(int i=0;i<2509;i++){
			if(count[i]%2==1){
				ans.push_back(i);
			}
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}