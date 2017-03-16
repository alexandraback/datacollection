#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define pb push_back
#define mp make_pair
#define s second
#define f first
using namespace std;
int main(){
	int t,no=0; scanf("%d",&t);
	while(t--){
		printf("Case #%d: ",++no);
		double C,F,X,now=2.0; scanf("%lf %lf %lf",&C,&F,&X);
		vector< pair<double,double> >  V;
		V.pb(mp(0,X/now));
		while(1){
			V.pb(mp(V[V.size()-1].f+(C/now),0.0));
			now+=F;
			V[V.size()-1].s=V[V.size()-1].f+(X/now);
			if(V[V.size()-1].s>V[V.size()-2].s){
				V.pop_back();
				break;
			}
		}
		printf("%.7lf\n",V[V.size()-1].s);
	}
}
