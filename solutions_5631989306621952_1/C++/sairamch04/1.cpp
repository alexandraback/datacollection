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
	int T,cnt;
	string s;
	cin >> T;
	 cnt=1;
	while(T--){
		cout << "Case #" << cnt++ << ": ";
		deque<char> ans;
		cin >> s;
		for(int i=0;i<s.size();i++){
			if(ans.size() ==0){
				ans.push_back(s[i]);
			}
			else{
				if(ans.front() - s[i] > 0){
					ans.push_back(s[i]);
				}
				else{
					ans.push_front(s[i]);
				}
			}
		}
		while(ans.size() >0){
			cout << ans.front();
			ans.pop_front();
		}
		cout << endl;



	}
	return 0;
}