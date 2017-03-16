#include <iostream>
#include <cstring>

using namespace std;

double ans;

int n, nall;
double p[100005], pm[100005];

double ppm(int k){
	if(k<0) return 1.0;
	else return pm[k];
}

int main(){
	int cs;

	freopen("output", "w", stdout);

	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);

		cin >> n >> nall;
		for(int i=0;i<n;i++){
			scanf("%lf", &p[i]);
		}
		pm[0] = p[0];
		for(int i=1;i<n;i++) pm[i]=pm[i-1]*p[i];

		ans = 1E10;
		double c;
		for(int j=0;j<=n;j++){
			c = ppm(n-1-j)*(nall-n+2*j+1);
			c+= (1.0-ppm(n-1-j))*(nall+1 +nall-n+2*j+1);
			ans = ans<c?ans:c;
		}
		if(n==nall){
			c = pm[n-1]*1+(1.0-pm[n-1])*(nall+2);
			ans = ans<c?ans:c;
		}else{
			c = 2+nall;
			ans = ans<c?ans:c;
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}