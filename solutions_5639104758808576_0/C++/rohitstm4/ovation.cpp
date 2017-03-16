#include <bits/stdc++.h>
using namespace std;

char str[1010];

int main(){
	int t;
	scanf("%i", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		int smax;
		scanf("%i", &smax);
		scanf("%s", str);
		int peopleTillNow = 0;
		int ans = 0;

		
		int nPeople; // no. of people with shyness i
		nPeople = int(str[0] - '0');
		peopleTillNow = nPeople;
		
		for (int i = 1; i <= smax; i++){
			nPeople = int(str[i] - '0');
			if (peopleTillNow < i and nPeople > 0){
				ans += (i - peopleTillNow);
				peopleTillNow = i;
			}
			peopleTillNow += nPeople;
		}
		printf("Case #%i: %i\n", test_case, ans);
	}
}