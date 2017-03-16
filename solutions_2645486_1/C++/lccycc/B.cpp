#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 10000 + 10;
LL v[maxn];
pair<LL, int> st[maxn];
int dirr[maxn];
LL l[maxn], r[maxn];
int main(){
	freopen("B-large.in","r", stdin);
	freopen("B.out","w", stdout);

	int E, R;
	int T;
	int cas = 0;
	for (cin>>T;T--;){
		int n;
		cin>>E>>R>>n;
		for (int i = 1; i<=n; i++){
			cin>>v[i];
			st[i] = make_pair(v[i], i);
		}
		sort(st+1, st+n+1);
		for (int i = 0; i<=n+2; i++){
			r[i] = i+1;
			l[i] = i-1;
		}
		for (int i = 1; i<=n; i++){
			int k = st[i].second;
			dirr[k] = r[k];
			l[r[k]] = l[k];
			r[l[k]] = r[k];
		}
		LL tot = 0;
		LL S = E;
		for (int i = 1; i<=n; i++){
			if (dirr[i] > n){
				tot += S * v[i];
				S = 0;
			}else{
				LL minRes = max (0, E - (dirr[i]-i)*R);
				minRes = min(minRes, S);
				tot += v[i] * (S - minRes);
				S=minRes;
			}
			S += R;
			if (S >= E){
				S = E;
			}
		}
		cas++;
		cout<<"Case #"<<cas<<": "<<tot<<endl;
	}
	return 0;
}
