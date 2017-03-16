#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long ul;

ul gcd(ul a, ul b)
{
  ul c;
  while ( a != 0 ) {
    c = a; 
    a = b%a;  
    b = c;
  }
  return b;
}

int main()
{
	
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		ul p, q;
		scanf("%lu/%lu", &p, &q);
		// cout << p << ": "<< q << endl;
		ul pq_gcd = gcd(p, q);
		p = p / pq_gcd;
		q = q / pq_gcd;
		// cout << p << ": "<< q << endl;

		int ans = 0;
		for(int j = 1; j <= 40; ++j) {
			p = 2 * p;
			if(p >= q) {
				p -= q;
			 	if(ans == 0) {
			 		ans = j;
			 	}
			}
			// cout << p << endl;
			if(p == 0) {
				break;
			}
		}
		if(p == 0) {
			cout << "Case #" << i+1 << ": " << ans << endl;
		} else {
			cout << "Case #" << i+1 << ": impossible" << endl;
		}
 	}
}