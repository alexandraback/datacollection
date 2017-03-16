#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, pair<long long, long long> > > arr;
vector<pair<long long, pair<long long, long long> > > ans;

bool check(pair<long long, pair<long long, long long> > p, long long K){
	long long i, a=0, b=0, c=0;
	for(i=0;i<ans.size();i++){
		if(ans[i].first==p.first and ans[i].second.first==p.second.first) a++;
		if(ans[i].first==p.first and ans[i].second.second==p.second.second) b++;
		if(ans[i].second.first==p.second.first and ans[i].second.second==p.second.second) c++;
		if(p==ans[i]) return 0;
	}
	if(a>=K or b>=K or c>=K) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long T, cas, K, J, P, S, i, j, k, f;
	cin >> T;
	for(cas=1;cas<=T;cas++){
		cout << "Case #" << cas  << ": ";
		arr.clear();
		ans.clear();
		cin >> J >> P >> S >> K;
		for(i=1;i<=J;i++){
			for(j=1;j<=P;j++){
				for(k=1;k<=S;k++){
					if(!(i==j and j==k)) arr.push_back(make_pair(i, make_pair(j, k)));
				}
			}
		}
		sort(arr.begin(), arr.end());
		if(J>=1 and P>=1 and S>=1) arr.push_back(make_pair(1, make_pair(1, 1)));
		if(J>=2 and P>=2 and S>=2) arr.push_back(make_pair(2, make_pair(2, 2)));
		if(J>=3 and P>=3 and S>=3) arr.push_back(make_pair(3, make_pair(3, 3)));
		f=1;
		while(f){
			f=0;
			for(i=0;i<arr.size();i++){
				if(check(arr[i], K)){
					f=1;
					ans.push_back(arr[i]);
				}
			}
		}
		cout << ans.size() << '\n';
		for(i=0;i<ans.size();i++){
			cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << '\n';
		}
	}
	return 0;
}
