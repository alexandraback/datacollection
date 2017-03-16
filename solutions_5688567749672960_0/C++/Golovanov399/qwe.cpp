#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

long long get(long long n){
	if (n < 10){
		return n;
	}
	vector<int> a;
	long long N = n;
	while (N){
		a.push_back(N % 10);
		N /= 10;
	}
	long long k = 1;
	for (int i = 0; i < (int)a.size() - 1; i++){
		k *= 10;
	}
	k--;
	long long ans = get(k) + 1;
	bool flag = true;
	for (int i = 0; i < (int)a.size() - 1; i++){
		flag &= (a[i] == 0);
	}
	if (flag){
		if (a.back() == 1)
			return ans;
		ans++;
		for (int i = 0; i < (int)a.size() - 1; i++){
			a[i] = 9;
		}
		a.back()--;
	}
	if (1){
		// cerr << n << ":\n" << ans << "\n";
		// for (auto x : a)
		// 	cerr << x << " ";
		// cerr << "\n";
		/*flag = false;
		for (auto x : a){
			if (x == 1)
				flag = true;
		}
		for (int i = 1; i < (int)a.size(); i++){
			if (a[i])
				ans += a[i] + 1;
		}
		if (a.back() == 1)
			ans -= 2;
		else
			ans--;
		ans += a[0];*/

		long long s = accumulate(all(a), 0);
		long long cnt = 0;
		for (auto x : a)
			if (x)
				cnt++;
		if (a.back() == 1){
			if (a[0] == 0)
				ans += (s - 1) + (cnt - 1);
			else
				ans += (s - 1) + (cnt - 2);
		} else {
			flag = false;
			for (auto x : a)
				if (x == 1)
					flag = true;
			if (flag){
				if (a[0] && cnt > 2)
					ans--;
				ans += (s - 1) + (cnt - 1);
			} else {
				if (a[0] == 0)
					ans++;
				ans += (s - 1) + (cnt - 1);
			}
		}
	}
	return ans;
}

const int nn = 1e6 + 1;
int res[nn];
int Cn = 0;

void init(){
	res[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()){
		int v = q.front();
		Cn++;
		if (Cn % 10000 == 0)
			cerr << Cn << "\n";
		q.pop();
		if (v + 1 < nn && res[v + 1] == 0){
			res[v + 1] = res[v] + 1;
			q.push(v + 1);
		}
		vector<int> a;
		int w = v;
		while (w){
			a.push_back(w % 10);
			w /= 10;
		}
		w = 0;
		for (auto x : a)
			w = w * 10 + x;
		if (res[w] == 0){
			res[w] = res[v] + 1;
			q.push(w);
		}
	}
}

void solve(){
	long long n;
	cin >> n;
	cout << get(n) << "\n";
}

int main(){

	init();
	// cerr << "qwe\n";
	// for (int i = 1; i < nn; i++){
	// 	if (get(i) != res[i]){
	// 		cerr << i << " " << get(i) << " " << res[i] << "\n";
	// 		return 0;
	// 	}
	// }

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		// solve();
		int n;
		scanf("%d", &n);
		printf("%d\n", res[n]);
		cerr << "Test #" << i + 1 << " completed\n";
	}

	return 0;
}