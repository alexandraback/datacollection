#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if(b == 0)
	{
	        return a;
	}
	else if (a == 0) {
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}
}


pair<long long,long long> lcdOutput(long long num,long long den){
    long long temp = gcd(num, den);
    return make_pair(num / temp, den / temp);
}

int main() {
	long long tc;
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> tc;
	for (long long q=1; q <=tc; q++) {
		long long a=0,b=0,counter = 0;
		bool flag = false;
		char c;
		scanf("%lld%c%lld", &a,&c,&b);
		
		pair<long long,long long> t = lcdOutput(a,b);
		a = t.first;
		b = t.second;
		long long temp = b;
		int tracker = 0;
//		cout << a << " " << b << endl;
		while (temp != 2) {
			
			
			if (temp %2 != 0) {
				printf("Case #%d: impossible\n", q);
				flag = true;
				break;
			}
			temp /= 2;
			tracker++;
			if (tracker > 40) {
				printf("Case #%d: impossible\n", q);
				flag = true;
				break;
			}
		}
		if (flag) continue;
		while (a/b < 1) {
			a *= 2;
			counter++;
		}
			
		printf("Case #%d: %d\n", q, counter);
	}
}
