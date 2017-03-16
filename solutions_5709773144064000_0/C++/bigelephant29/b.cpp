#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

double find(int t, long double c, long double f, long double x){
	long double sum = 0.0, now = 2.0;
	while(t--){
		sum += c / now;
		now += f;
	}
	sum += x / now;
	return sum;
}

int main(){
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		double c, f, x, ans = 1e18;
		cin>>c>>f>>x;
		int l = 0, r = int(x) / 2 + 5;
		for(int i = 0 ; i <= 2000; i++){
			double tmp = find(i, c, f, x);
			ans = min(tmp, ans);
		}
		/*
		while(l < r){
			int mid = (l+r)>>1;
			double tmpl = find(mid, c, f, x);
			double tmpr = find(mid+1, c, f, x);
			if(tmpl < tmpr){
				ans = min(ans, tmpl);
				r = mid;
			}else{
				ans = min(ans, tmpr);
				l = mid+1;
			}
		}
		*/
		ans = min(ans, find(l, c, f, x));
		printf("Case #%d: %.7f\n", casen, ans);
	}
	return 0;
}
