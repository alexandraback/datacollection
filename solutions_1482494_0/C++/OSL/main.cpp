#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;
    
const
    int max_n = 1001;
 
int n, testcase;

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
	cin >> testcase;
	for(int i = 0; i < testcase; ++i){
		cin >> n;
		bool one[max_n], two[max_n];
		for(int i = 0; i < n; ++i){
			one[i] = false;
			two[i] = false;
		}
		vector<pair<int, int> > a;
		for(int j = 0; j < n; ++j){
			int u, v;
			cin >> u >> v;
			a.push_back(make_pair(u, v));
		}
		int count = 0, ans = 0, star = 0, step = 0;
		while(count != n && step < n * n + 1){
			int o = -1, t = -1, prev = -1;
			{
				for(int i = 0; i < n; ++i)
					if (!one[i] && a[i].first <= star && prev <= a[i].second) {
						o = i;
						prev = a[i].second;
					}
				for(int i = 0; i < n; ++i)
					if (!two[i] && a[i].second <= star){
						t = i;
						break;
					}
				
			}
			if (t != -1){
				if (one[t])
					star++;
				else 
					star += 2;
				two[t] = true;
				one[t] = true;
				count++;
				ans++;
			} else
				if(o != -1){
					one[o] = true;
					ans++;
					star++;
				}
			step++;
		}
		if (count != n)
			cout << "Case #" << i + 1 << ": Too Bad" << endl;
		else
			cout << "Case #" << i + 1 << ": " << ans << endl;
	}

}