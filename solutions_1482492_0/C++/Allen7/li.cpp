#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int readsinglenum(){
	int x;
	scanf("%d",&x);
	return x;
}
int _T,N,A;
double _a[11];
double v[3];
double t[3];
double x[3];
int mv;
void solve(double a ){
	double res=0;
	double ms=0;

}
int main(){

	double len;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	_T=::readsinglenum();
	for(int _t=1;_t<=_T;_t++){
		printf("Case #%d:\n",_t);
		scanf("%lf%d%d",&len,&N,&A);
		for(int i=0;i<N;i++){
			scanf(" %lf %lf",&t[i],&x[i]);
		}
		for(int i=0;i<A;i++){
			scanf("%lf",&_a[i]);
		}
		if(N==1){
			for(int i=0;i<A;i++){
				printf("%.7lf\n",sqrt(2.00*len/_a[i]));
			}
		}
		else{
			double S=x[0];
			double V=(x[1]-x[0])/(t[1]-t[0]);
			if(x[1]>len)
				t[1]=(len-x[0])/v[0];
			double T=t[1];
			for(int i=0;i<A;i++){
				mv=0;
				double tt=(V+sqrt(V*V+2*_a[i]*S))/_a[i];
				if(tt<T){
					double ts= V*tt+S;
					double res=tt+(len-S-V*tt)/V;
					printf("%.7lf\n",res);
				}
				else{
					printf("%.7lf\n",sqrt(2.00*len/_a[i]));
				}
			}
		}
	}
	return 0;
}
