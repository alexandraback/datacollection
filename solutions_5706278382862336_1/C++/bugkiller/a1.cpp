#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

const int K = 1000;
int A[K + 10];

void precompute() {
	long long int i = 1LL;
	long long int j;
	A[0] = i;
	for(j=1; j<=43; j++) {
		i *= 2;
		A[j] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	precompute();
	//memset(a, 0, sizeof a);
	for(int test = 1; test <= t; test++) {
		long long int a;
		long long int b;
		char c;
		/*cin>>a;
		cin>>c;
		//getchar();
		cin>>b;
		cin>>c;
		*/
		scanf("%lld %c %lld",&a, &c, &b);

		long long int g = __gcd(a, b);
		a /= g;
		b /= g;


		int ans = 0;
		bool possible = false;
		int j = 0;
		if(binary_search(A, A+42, b)) {
			j = 1;
			possible = false;
			if(a > b) {
				cout<<"Case #"<<test<<": "<<"impossible\n";
				possible = true;
			}
			while(j <= 40 && !possible) {
				if(a >= b/2) {
					cout<<"Case #"<<test<<": "<<j<<"\n";
					possible = true;
				}
				b /= 2;
				j++;
			}
			if(!possible) {
				cout<<"Case #"<<test<<": "<<"impossible\n";
			}
		}
		else {
			cout<<"Case #"<<test<<": "<<"impossible\n";
		}
	}
	return 0;
}