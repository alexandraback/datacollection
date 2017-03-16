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
	
	int c;
	int d;
	int v;
	
	
	for(int i1 = 1;i1 <= cases;i1++) {
		
		cin >> c >> d >> v;
		int a[d+1];
		for(int i = 0;i < d;i++) {
			cin >> a[i];
		}
		int sum = 0;
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
			for(int i = 1;i < a[0];i++) {
				if(sum < i) {
					sum += i;
					ans++;
				}
			}
		}
		sum += a[0];
		for(int i = 1;i < d;i++) {
			if(sum >= v) {
				break;
			}
			if(a[i] - sum > 1) {
				ans ++;
				sum += sum + 1;
				i--;
			}else {
				sum += a[i];
			}
		}
		while(sum < v) {
			ans ++;
			sum += sum + 1;
		}
		
		
		printf("Case #%d: %d\n", i1, ans);
	}
	return 0;
}
