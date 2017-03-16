#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int i;
	int cases;
	cin >> cases;
	
	ll c;
	int d;
	ll v;
	
	
	for(int i1 = 1;i1 <= cases;i1++) {
		
		cin >> c >> d >> v;
		ll a[d+1];
		for(int i = 0;i < d;i++) {
			cin >> a[i];
		}
		ll sum = 0;
		int ans = 0;
		/*
		for(int i = 2;i < a[0];i++) {
			if(sum >= v) {
				break;
			}
			if(sum < i) {
				ans++;
				sum += i;
			}
		}
		*/
		if(a[0] > 1) {
			for(ll i = 1;i < a[0];i++) {
				if(sum < i) {
					sum += i*c;
					ans++;
				}
			}
		}
		sum += a[0] * c;
		for(int i = 1;i < d;i++) {
			if(sum >= v) {
				break;
			}
			if(a[i] - sum > 1) {
				ans ++;
				sum += (sum + 1) * c;
				i--;
			}else {
				sum += a[i];
			}
		}
		while(sum < v) {
			ans ++;
			sum += (sum + 1) * c;
		}
		
		
		printf("Case #%d: %d\n", i1, ans);
	}
	return 0;
}
