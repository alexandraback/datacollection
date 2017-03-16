#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

#define MP make_pair
typedef long long LL;
typedef long double D;
typedef pair<LL,LL> PI;
#define PB push_back
#define typ second
#define num first

int t,n,m,a;
D d;
D times[2100];
D pos[2100];

D czas(D a, D tstart) {
	return tstart + sqrt(2*d / a);
} 

bool okTest(D a, D tstart,int point) {
	if(tstart>times[point]) return true;
	return ((times[point]-tstart)*(times[point]-tstart)*a/2 <= pos[point]);
}

void popraw_ostatniego() {
	for(int i=0;i<n;i++) {
		if(pos[i]>=d) {
			D v; 
			if(i == 0) {
				v = pos[i]/times[i];
				times[i] = d/v;
				pos[i]=d;
			}
			else {
				v = (pos[i]-pos[i-1])/(times[i]-times[i-1]);
				times[i] = (d-pos[i-1])/v + times[i-1];
				pos[i]=d;
			}
			n = i+1;
			break;
		}
	}
}
double da,aa,ca,ba;
int main() {
	scanf("%d",&t);
	for(int ind = 1;ind<=t;ind++) {
		scanf("%lf%d%d",&da,&n,&a);d=da;
		for(int i=0;i<n;i++) {
			scanf("%lf%lf",&times[i],&pos[i]);
		}
		//popraw_ostatniego();

		
		printf("Case #%d:\n", ind);
		for(int i=0;i<a;i++) {
			D atmp;scanf("%lf",&aa);atmp=aa;
			D wynik;
			
			D wynika = 0;
			D wynikb = times[n-1];
			
			for(int h=0;h<100;h++) {
				D c = (wynika+wynikb)/2;
				
				int ok = 1;
				for(int l=0;l<n;l++) {
					if(okTest(atmp,c,l) == false) {
						ok = 0;break;
					}
				}
				if(ok) wynikb = c;
				else wynika = c;
			}
			wynik = czas(atmp,wynikb);
			
			/*if(n==1) {
				if(okTest(atmp,0,0)) {
					wynik = czas(atmp,0);
				}
				else {
					wynik = czas(atmp,czasstartu(atmp,0));
				}
			}
			else {
				if(okTest(atmp,0,0) && okTest(atmp,0,1)) {
					wynik = czas(atmp,0);
				}
				else {
					wynik = czas(atmp,czasstartu(atmp,0));
				}
			
			}*/
			
			printf("%.8lf\n",(double)wynik);
		}

	}
	return 0;
}
