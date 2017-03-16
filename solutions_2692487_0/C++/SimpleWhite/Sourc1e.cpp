#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

ll a, n, m[102];

ll func(int x){
	ll ar = a, death = 0;
	int attemp = x;
	for(int i = 0; i < n; i++){
		if(ar > m[i])
			ar += m[i];
		else{
			if(attemp > 0){
				ar += (ar - 1);
				attemp--;
				i--;
			}
			else{
				death++;
			}
		}
	}
	return death;
}
int main(){
	#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
	#endif
   ll t;
   scanf("%lld", &t);
   for(long long c = 1; c <= t; c++){
	   ll min = 100;

	   scanf("%lld %lld\n", &a, &n);
	   for(ll i = 0; i < n; i++)
		   scanf("%lld", &m[i]);

	   bool flag = false;
	   if(a == 1){
		   printf("Case #%lld: %lld\n", c, n);
	   }
	   else{
		   sort(m, m + n);
		   for(int x = 0; x < 25; x++){
			   ll death = func(x);
			   if((death + x) < min){
				   min = death + x;
			   }
			   if(death = 0){
				  printf("Case #%lld: %lld\n", c, min);
				  flag = true;
				  break;
			   }
		   }

		   if(flag == false)
			   printf("Case #%lld: %lld\n", c, min);
	   }
   }
}