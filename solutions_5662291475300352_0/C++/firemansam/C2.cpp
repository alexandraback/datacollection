#include<bits/stdc++.h>
using namespace std;
int tcs, n, d, h, m;
struct hike{
	double cp, sp;
	hike(double a, double b){
		cp = a; sp = b;
	}
};
bool cmp(hike a, hike b){
	if (a.cp == b.cp) return a.sp < b.sp;
	return a.cp < b.cp;
}
vector<hike> hks;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i", &n);
		hks.clear();
		for(int i=0;i<n;i++){
			scanf("%i%i%i", &d, &h, &m);
			for(int j=0;j<h;j++){
				hks.push_back(hike(d, (360.0/(m+j))));
			}
		}
		sort(hks.begin(), hks.end(), cmp);
		n = hks.size();
		int ans = 0;
		if(hks[0].sp == hks[1].sp) ans = 0;
		else if(hks[0].sp > hks[1].sp){
			//1st check collision pt
			if(hks[0].cp + (((hks[1].cp - hks[0].cp) / (hks[0].sp - hks[1].sp)) * hks[0].sp) >= 360.0) ans = 0;
			else ans = 1;
		} else {
			if((hks[1].cp - hks[0].cp) <= (hks[1].sp - hks[0].sp) * (360.0/hks[0].sp)) ans = 1;
			else ans = 0;
		}
		printf("Case #%i: %i\n", tc, ans);
	}
}