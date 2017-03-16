#include <iostream>
#include <set>
#include <deque>
using namespace std;
void add(deque<int> &v,int n){
	int i = 0;
	while(n){
		if(v.size() <= i) v.push_back(0);
		v[i] += n%10;
		n /= 10;
		if(v[i] > 9) n += 1,v[i] -= 10;
		++i;
	}
}
long long conv(deque<int> v){
	long long ret = 0;
	if(!v.size()) return 0;
	int i = v.size()-1;
	while(!v[i]) --i;
	for(++i; i --> 0;)
		ret = ret*10 + v[i];
	return ret;
}
int main(){
	int T; cin >> T;
	for(int t = 1; t <= T; ++t){
		int n,c = 0; cin >> n;
		deque<int> num;
		int cnt[10] = {};
		bool cont = 1;
		set<long long> in;
		while(cont){
			add(num,n);
			for(int i:num) c += !cnt[i]++;
			if(c == 10) break;
			long long test = conv(num);
			if(in.find(test) != in.end()) cont = 0;
			in.insert(test);
		}
		cout << "Case #" << t << ": ";
		if(cont) for(int i = num.size(); i-->0;) cout << num[i];
		else cout << "INSOMNIA";
		cout << endl;
	}
}