#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;


int cs[1000005];
string s;
int n;

#define isc(x) (!((x)=='a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u'))

ll bf1(){
	ll ans = 0;
	for(int i = 0; i < s.size(); ++i)
		for(int j = i; j < s.size(); ++j){
			int cnt = 0, best = 0, k = i;
			while(k <= j){
				cnt = 0;
				while(k <= j && isc(s[k]))k++,cnt++;
				k++;
				if(cnt > best) best = cnt;
			}
			if(best >= n) ans ++;
		}
	return ans;
}
ll summ(int a, int b){
	int n = (b - a + 1);
	return (ll) a * n + (n-1) * n / 2;
}
ll bf2(){
	ll ans = 0;
	vector<pair<int, int> > seq;
	int i, start;
	while(i < s.size()) {
		int cnt = 0;
		start = i;
		while(i < s.size() && isc(s[i]))i++,cnt++;
		if(cnt >= n){
			seq.push_back(make_pair(start, cnt));
		}
		i++;
	}
	int lst = 0;
#if 1
	for(int i = 0; i < seq.size(); ++i) {
	//	cout << "@" << seq[i].first << " " << seq[i].second << endl;
		for(int st = lst; st <= seq[i].first + seq[i].second - n; st++) {
			int end = max(seq[i].first + n - 1, st + n - 1);
//			cout << "st=" << st << " end=" << end << "-> " << (s.size() - end) << endl;
			ans += (s.size() - end);
		}
		lst = seq[i].first + seq[i].second - n + 1;
	}
	return ans;
#endif
	for(int i = 0; i < seq.size(); ++i) {
		ans += ((ll) seq[i].first - lst) * (s.size() - seq[i].first - n + 1);
		int a = seq[i].first;
		int b = seq[i].first + seq[i].second - n;
		ll nn = b - a + 1;
		ans += nn * (s.size() + 1 - n) - summ(a, b);
		lst = seq[i].first + seq[i].second - n + 1;
	}
	return ans;
}
int main(){
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++){
		cin >> s >> n;
		cout << "Case #" << c << ": " << bf2() << endl;
	}
	return 0;
}
