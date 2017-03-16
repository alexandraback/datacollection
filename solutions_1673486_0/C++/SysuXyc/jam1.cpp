#include<iostream>
#include<string>
#include<memory.h>
#include<fstream>
#include<cstdio>
#include<iomanip>
using namespace std;
const int MAXN=100000;
double p[MAXN];
double pp[MAXN];
double p2[MAXN];
int main(){
	int T,n,m;
	ifstream ipt("A-small-attempt0.in");
	ofstream ot("A-small-attempt0.out");
	ipt >> T;
	int c=T;
	while(T--){
		ipt >> n >> m;
		for(int i=1;i <= n;i++)
			ipt >> p[i];
		pp[0]=1;
		pp[1]=p[1];
		for(int i=2;i <= n;i++)
			pp[i]=pp[i-1]*p[i];
		int x=n/2;
		double p1=(pp[n])*(m-n+1)+(1-pp[n])*(2*m-n+2);
		for(int i=n;i >= 1;i--){
			p2[i]=(1-pp[n-i])*(m-(n-i)+1+i+m+1)+pp[n-i]*(i+m-(n-i)+1);
		}
		double minn=100000000;
		for(int i=1;i <= n;i++)
			if(p2[i] < minn)
				minn=p2[i];
		double p3=m+2;
		double tp=p1 > minn ? minn : p1;
		double ans=tp > p3 ? p3 : tp;
		ot << "Case #" << c-T << ": ";
		ot << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}