# include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &fr, vector<bool> &used, vector<int> &circ, int pos)
{
	int cur = circ[pos];
	if (!used[fr[cur]]) {
		used[fr[cur]] = true;
		circ[pos + 1] = fr[cur];
		int mx = fun(fr, used, circ, pos+1);
		used[fr[cur]] = false;
		return mx;
	}
	else {
		if (fr[cur] == circ[0] && pos > 1) {
			return pos+1;
		}
		else if (fr[cur] == circ[pos-1]) {
			int mx = 0;
			for(int i=0; i<fr.size(); ++i) {
				if (!used[i]) {
					used[i] = true;
					circ[pos + 1] = i;
					int ret = fun(fr, used, circ, pos+1);
					used[i] = false;
					mx = max(mx, ret);
				}
			}
			return max(mx, pos+1);
		}
		else {
			return 0;
		}
	}
}

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		int n; cin >> n;
		
		vector<int> fr(n);
		for(int i=0; i<n; ++i) {
			scanf("%d", &fr[i]);
			fr[i] -= 1;
		}
		
		vector<bool> used(n, false);
		vector<int> circ(n);
		
		int mx = 1;
		for(int i=0; i<n; ++i) {
			used[i] = true;
			circ[0] = i;
			int cnt = fun(fr, used, circ, 0); 
			used[i] = false;
			mx = max(mx, cnt);
		}		
				
		printf("Case #%d: %d\n", T_, mx);
	}
	return 0;
}