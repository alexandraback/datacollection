#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

long long int gcd (long long int a,long long int b) {
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b,a % b);
	}
}

bool not_in_form (long long int n) {
	while (n % 2 == 0) {
		n = n / 2;
	}
	if (n != 1) {
		return true;
	}
	return false;
}

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.in","w",stdout);
	int t,it;
	scanf("%d",&t);
	for (it = 1; it <= t; it++) {
		long long int p,q,g;
		int i,ans;
		char s[50];
		scanf("%s",s);
		p = 0;
		q = 0;
		i = 0;
		while (s[i] != '/') {
			p = p * 10 + s[i] - '0';
			i++;
		}
		i++;
		while (s[i] != '\0') {
			q = q * 10 + s[i] - '0';
			i++;
		}
		g = gcd(p,q);
		p = p / g;
		q = q / g;
		if (not_in_form(q) == true) {
			printf("Case #%d: impossible\n",it);
		} else {
			ans = 1;
			while (2 * p < q) {
				ans++;
				q = q / 2;
			}
			printf("Case #%d: %d\n",it,ans);
		}
	}
	return 0;
}
