#include <bits/stdc++.h>
using namespace std;

double sim(int n, double c, double f, double x){
	double res=0, cps=2;
	for(int i=0; i<n; i++){
		res+=c/cps;
		cps+=f;
	}
	return res+x/cps;
}

int main(){
	
	freopen("b.in", "r", stdin);
	freopen("b-2.out", "w", stdout);
	
	int t;
	cin>>t;
	for(int tc=1; tc<=t; tc++){
		
		double c, f, x;
		cin>>c>>f>>x;
		
		int l=0, r=100001;
		while(r-l>=3){
			int ll=(2*l+r)/3;
			int rr=(2*r+l)/3;
			if(sim(ll, c, f, x)<sim(rr, c, f, x)) r=rr-1;
			else l=ll+1;
		}
		
		double ans=sim(l, c, f, x);
		for(int i=l; i<=r; i++)
			ans=min(ans, sim(i, c, f, x));
		
		printf("Case #%d: %.7lf\n", tc, ans);
	}

	return 0;
}
