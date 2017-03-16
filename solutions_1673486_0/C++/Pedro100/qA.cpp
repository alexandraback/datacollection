#include <cstdio>
#include <algorithm>

using namespace std;
double p[100000];

int main(){
	double v[4];
	int casos;
	double pp;
	scanf("%d",&casos);
	for(int u=1; u<=casos; u++){
		int a, b;
		scanf("%d %d",&a,&b);
		for(int i=0;i<a; i++)scanf("%lf",&p[i]);
		v[0] = b + 2.0;
		pp = 1.0;
		for(int i=0;i<a; i++)pp *= (p[i]);
		v[1] = (b-a+1)*pp + (b-a+b+2)*(1.0-pp);
		
		pp = 1.0;
		for(int i=0;i<a-1; i++)pp *= (p[i]);
		v[2] = (b-a+3)*pp + (b-a+b+4)*(1.0-pp);
		
		pp = 1.0;
		for(int i=0;i<a-2; i++)pp *= (p[i]);
		v[3] = (b-a+5)*pp + (b-a+b+6)*(1.0-pp);
		
		sort(v,v+4);
		//for(int i=0; i<4; i++) printf(" >> %.6lf\n",v[i]);
		printf("Case #%d: %.8lf\n",u,v[0]);
	}
	return 0;
}
