#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=200;
const double EPS=1e-9;
const int INF=1000000000;
int n;
double a[MAXN+10],b[MAXN+10];
double tmp,sum;
int DoubleCmp(double x,double y)
{
	if (fabs(x-y)<EPS)return 0;
	return x<y?-1:1;
}
struct P {
	double v;
	int ID;
	friend bool operator<(const P &a,const P &b)
	{
		return DoubleCmp(a.v,b.v)<0;
	}
} data[MAXN+10];
void ReadIn() {
	scanf("%d",&n);
	tmp=0;
	for (int i=0;i<n;i++) {
		scanf("%lf",&data[i].v);
		data[i].ID=i;
		tmp+=data[i].v;
	}
}
int main()
{
	int cases;
	scanf("%d",&cases);
	for (int c=1;c<=cases;++c) {
		ReadIn();
		sum=tmp;
		sort(data,data+n);
		data[n].v=INF;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++) {
			if (DoubleCmp(tmp,(i+1)*(data[i+1].v-data[i].v))>0) {
				a[i]=(data[i+1].v-data[i].v);
				tmp-=a[i]*(i+1);
			} else {
				a[i]=tmp/(i+1);
				break;
			}
		}
		for (int i=n-1;i>=0;i--) a[i]+=a[i+1];
		for (int i=0;i<n;i++) b[data[i].ID]=a[i];

		printf("Case #%d:",c);
		for (int i=0;i<n;i++) printf(" %.6f",b[i]/sum*100);
		puts("");
	}
	return 0;
}
