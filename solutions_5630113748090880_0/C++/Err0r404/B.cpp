#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream cin("BS.in");
	ofstream cout("BS.txt");
	int T; cin >> T;
	for (int i=0;i<T;i++){
	
		int N; cin >> N;
		int cn[2501] = {0};
		for (int i=0;i<(2*N-1) *N;i++){
			int x; cin >> x;
			cn[x]++;
		}
		vector<int> ans(0);
		for (int i=1;i<=2500;i++){
			if (cn[i]%2) ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		cout << "Case #" << i+1 << ": ";
		for (int i=0;i<ans.size();i++){
			cout << ans[i];
			if (i != ans.size()-1) cout << " "; else cout << endl;
		}
	}
}
