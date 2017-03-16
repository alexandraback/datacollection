#include <cstdio>
#include <cmath>
using namespace std;

double s[210];
int T,n;

bool check(double ns,int index){
	double sum=0;
	for (int i=0;i<n;++i){
		if (i==index) continue;
		if (s[i]>s[index]+ns) continue;
		sum+=s[index]+ns-s[i];
	}
	if (sum>100-ns) return true;
	else return false;
}

int main()
{
	scanf("%d",&T);
	for (int cases=0;cases<T;++cases){
		scanf("%d",&n);
		double tot=0;
		for (int i=0;i<n;++i){
			scanf("%lf",&s[i]);
			tot+=s[i];
		}
		for (int i=0;i<n;++i) s[i]=s[i]/tot*100;
		printf("Case #%d:",cases+1);
		for (int i=0;i<n;++i){
			double lower=0;
			double upper=100;
			while (fabs(upper-lower)>1e-8){
				double mid=(lower+upper)/2;
				if (check(mid,i)) upper=mid;
				else lower=mid;
			}
			printf(" %.7lf",(lower+upper)/2);
		}
		printf("\n");
	}
	return 0;
}
