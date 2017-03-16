#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using std::vector;
using std::set;


bool check(set<long long int>::iterator l, set<long long int>::iterator r, long long int v, long long int c) {
	set<long long int>::iterator it;
	long long int k;
	bool ret = false;
	it = r;
//	printf("Checking %lld using numbers between %lld and %lld\n", v, *l, *r);
	while (it != l && v > 0) {
		k = v / (*it);
		v = v - (k > c ? c : k)*(*it);
		--it;
//		printf("temp %lld\n", v);
	}
	if (v > 0) { //it == l
		k = v / (*it);
		v = v - (k > c ? c : k)*(*it);
	}
	if (v == 0)
		ret = true;
	return ret;
}

int main() {
	long long int i,j,k;
	long long int t,n,m, c,d,v, ret ,maxval, sum;
	set<long long int> coins;
	set<long long int>::iterator it;
	scanf("%lld\n", &t);
	
	for (i = 1; i <= t ; i++) {
		//one case here
		scanf("%lld %lld %lld\n", &c, &d, &v);
		coins.clear();
		ret = 0;
		sum = 0;
		for (j = 0; j < d; j++) {
			scanf("%lld", &n);
			coins.insert(n);
			sum += n;
		}
		scanf("\n");

		j = 1;
		while (j <= v) {	
			it = coins.lower_bound(j);
			if (it == coins.begin()) {
				if (*it > j) { //mniejsza wartosc niz najmniejsza w coins
					coins.insert(j);
					//printf("Inserting %lld\n", j);
					ret += 1;		
					sum += j;	
				}
				j++;
			} else {
				if (it == coins.end()) --it;
				if (!check(coins.begin(), it, j, c)) {
					coins.insert(j);
					//printf("Inserting %lld\n", j);
					ret += 1;
					sum +=j;
					j = 2*j - 1;

				} else {
					j++;
				}
			}
		}
		

		printf("Case #%lld: %lld\n", i, ret);
	}
	return 0;
}

