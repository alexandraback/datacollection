#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;

long long int power10(long long int a) {
	long long int ret;
	ret = 10;
	a--;
	while (a > 0) {
		ret *= 10; a--;
	}
	return ret;
}

long long int f(long long int digits) {
	//how many moves to get to 10^digits
	long long int ret, i, tmp;
	ret = 10;
	while (digits > 1) {
		tmp  = power10(digits / 2);
		if (digits % 2 == 0) {
			ret += 2*tmp -1;
		} else {
			ret += tmp + 10*tmp -1;
		}
		digits--;
	}
	return ret;
}

int main() {
	long long int i,j,k;
	long long int t,n,mul, tmp, ret, digits, limit;
	vector<long long int> v;


	scanf("%lld\n", &t);

	for (i = 1; i <= t ; i++) {
		v.clear();
		//each case here
		ret = 0;
		scanf("%lld\n", &n);
		if (n <= 20) {
			ret = n;
		} else {
			k = 0;
			while (n > 0) {
				k += n % 10;
				v.push_back(n % 10);					
				n = n / 10;
			}
			digits = v.size();
			ret += f(digits-1);
			if (k > 1) {
				tmp = 0;
				for (j =0 ; j < digits/2; j++)
					tmp += v[j];
				if (tmp == 0) { 
					j = 0;
					while (v[j] == 0) {
						v[j] = 9; j++;
					}
					v[j] -= 1;
					ret +=1;
				}
				mul = 1;
				for (j= 0; j < (digits/2); j++) {
					ret += mul*(v[j] + v[digits -j-1]);
					mul *=10;
				}
				if ((digits % 2) != 0) ret+= mul*v[digits/2];
				tmp = 0;
				k = digits/2 + (digits % 2 ? 1 : 0);
				for (j = digits -1; j >= k; j--) {
					tmp += v[j];
				}
				if (tmp == 1) ret -= 1;
			}
		}
		printf("Case #%lld: %lld\n", i, ret);
	}
	return 0;
}

