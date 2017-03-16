#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


long long strtoint(string res){
	long long ans = 0;
	for (int i = 0; i <res.length(); i++) {
		ans = ans*10 + (res[i] - '0');
	}
	return ans;
}

long long gcd(long long a, long long b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for (int _t = 0; _t < T; _t++){
		string inn;
		cin>>inn;
		string p1 = "", q1 = "";
		bool f = false;
		for (int i = 0; i < inn.length(); i++) {
			if (inn[i] == '/') f = true;
			else if (f) q1+=inn[i];
			else p1+=inn[i];
		}
		long long p = strtoint(p1);
		long long q = strtoint(q1);
		long long g = gcd(p,q);
		p/=g;
		q/=g;
		long long w = q;
		bool f1 = true;
		while (w!=1) {
			if (w%2 == 1) {
				f1 = false;
				break;
			}
			else w/=2;
		}
		if (!f1) {
			cout<<"Case #"<<_t+1<<": impossible"<<endl;
		} else {
			int ans = 0;
			while (q>p) {
				q/=2;
				ans++;
			}
			cout<<"Case #"<<_t+1<<": "<<ans<<endl;
		}

	}

    return 0;
}