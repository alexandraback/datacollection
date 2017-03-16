#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long lli;

lli gcd(lli a, lli b){
	return b ? gcd(b, a%b) : a;
}

lli lcm(lli a, lli b){
	lli tmp = gcd(a, b);
	a /= tmp;
	return a * b;
}

class Dev{
public:
	lli a, b;
	Dev(){}
	Dev(lli c, lli d){
		lli tmp = gcd(c, d);
		a = c / tmp;
		b = d / tmp;
	}
	/*
	Dev plus(Dev d){
		lli tmp = lcm(b, d.b);
		return Dev(tmp / b * a + tmp / d.b * d.a, tmp);
	}
	*/
	bool operator < (const Dev& s) const {
		if(a == s.a){
			return b < s.b;
		}
		return a < s.a;
/*
	lli tmp = lcm(b, s.b);
	return tmp / b * a < tmp / s.b * s.a;
*/
	}
};

map<Dev, lli> used;

lli calc(lli a, lli b){
	Dev d = Dev(a, b);
	if(used.find(d) != used.end()) return used[d];
	lli res = -1;
	if(a == 1 && b == 2){
		res = 1;
	}
	else if(b % 2 == 1) res = -1;
	else if(a / b >= 2) res = -1;
	else if(2 * a >= b){
		Dev tmp2 = Dev(2 * a - b, b);
		if(used.find(tmp2) != used.end()){
			if(used[tmp2] == -1) res = -1;
			else res = 0;
		}
		if(calc(tmp2.a, tmp2.b) != -1){
			res = 1;
		}
	}
	else{
		Dev next = Dev(a * 2, b);
		lli tmp = calc(next.a, next.b);
		if(tmp != -1) res = tmp + 1;
	}
	used[d] = res;
	return res;
}

int main(){
	int n;
	cin >> n;
	for(int t=0;t<n;t++){
		string in;
		cin >> in;
		lli a, b;
		for(int i=0;i<in.size();i++){
			if(in[i] == '/'){
				a = atoll(in.substr(0, i).c_str());
				b = atoll(in.substr(i+1).c_str());
			}
		}
		Dev tmp = Dev(a, b);
		a = tmp.a;
		b = tmp.b;
		cout << "Case #" << t + 1 << ": ";
		if(b % 2 == 1){
			cout << "impossible" << endl;
		}
		else{
			lli res = calc(a, b);
			if(res == -1){
				cout << "impossible" << endl;
			}else{
				cout << calc(a, b) << endl;
			}
		}
	}
	return 0;
}
