#include <iostream>
#include <vector>

using namespace std;

int bestWithSurprise(int n){
	if(n == 0) return 0;
	if(n%3 == 0) return (n-3)/3 + 2;
	else if(n%3 == 1) return (n-4)/3 + 2;
	else return (n-2)/3 + 2;
}

int bestWithoutSurprise(int n){
	if(n%3 == 0) return n/3;
	else if(n%3 == 1) return (n-1)/3 + 1;
	else return (n-2)/3 + 1;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0;i < t;++i){
		int n, s, p;
		cin >> n >> s >> p;
		vector<int> v;
		for(int j = 0;j < n;++j){
			int x;cin >> x;
			v.push_back(x);
		}
		int res = 0;
		for(int j = 0;j < n;++j){
			int x = v.at(j);
			int bws = bestWithoutSurprise(x);
			if(bws >= p) ++res;
			else if(s > 0){
				int bs = bestWithSurprise(x);
				if(bs >= p){
					++res;
					--s;
				}
			}
		}
		cout << "Case #" << (i+1) << ": " << res << endl;
	}
}

