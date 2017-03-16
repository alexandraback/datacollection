#include <iostream>
#include <set>
#include <map>
using namespace std;
map<long long, long long> m;
bool isPalindrome(long long n){
	long long x = 0, t= n, d;
	while(t){
		d = t%10;
		x = x*10+d;
		t = t/10;
	}
	return x == n;
}
void init(){
	long long cnt = 1;
	for(long long i = 1; i <= 10000010; i++)
		if(isPalindrome(i) && isPalindrome(i*i))
			m[i*i] = cnt++;
}
int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	init();
	long long n, a, b;
	cin >> n;
	for(long long cases = 1; cases <= n; cases++){
		if(cases != 1) cout << endl;
		cout << "Case #" << cases << ": ";
		long long ans = 0;
		cin >> a >> b;
		ans = (*(m.upper_bound(b)--)).second - (*(m.upper_bound(a)--)).second;
		double roota;
		int ra;
		if(pow(a, 0.5) == double(int(pow(a, 0.5))))
			if(isPalindrome(a) && isPalindrome(int(pow(a, 0.5)))) ans++;

		cout << ans;
	}
	return 0;
}