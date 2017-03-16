#include<iostream>

using namespace std;
typedef long long LL;

LL	r,t;
bool	check(LL x){
	double	area1 = 2.0*r*x+2.0*(x-1)*x+x;
	if ( area1 > t+100 ) return false;
	LL		area2 = 2*r*x+2*(x-1)*x+x;
	return area2<=t;
}

int		main(){
	int cas,tt;
	for(cin>>cas,tt = 1; tt<=cas; tt++ ){
		cin>>r>>t;
		LL	g = 1, h = 1e12,ans;
		while ( g <= h ){
			LL	mid = (g+h)>>1;
			if ( check(mid) )  g = mid+1 , ans = mid;
			else h = mid-1;
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
}
