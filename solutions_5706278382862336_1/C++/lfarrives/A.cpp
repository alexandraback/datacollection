#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

long long gcd(long long a,long long b)
{
	if (b == 0) {
	   return a;
    }
    return gcd(b, a%b); 
}
 
int main() 
{
   // freopen("inp.in", "r", stdin);
   // freopen("out.txt", "w", stdout);
    
	int t, cases;
	long long p, q, g, i, j, k, ans;
	
    scanf("%d", &t);
 
	for (cases = 1; cases <= t; cases++) {
		scanf("%lld/%lld", &p, &q);

        g = gcd(p, q);
        p = p/g;
        q = q/g;

		ans = 0;
		
		int flag = 0;
 
        if ((q&(q-1)) != 0 || p > q) {
           flag = 1;
        }
        
        if (!flag) {
           ans = 1;
		   while (ans <= 40) {
                 if (p >= q/2) {
				    break;
	             }
			     q = q/2;
			     ans++;
           }
        }
 
		if (flag) {
			printf("Case #%d: impossible\n", cases);
        } else {
			printf("Case #%d: %lld\n", cases, ans);
        }
	}
	return 0;
}
