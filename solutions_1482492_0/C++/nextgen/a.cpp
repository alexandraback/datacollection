#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define forn(i,n) for (int (i)=0; (i)<(n); (i)++)

using namespace std;
const int INF=~(1<<31);
const double EPS=1e-9;
const double PI=3.141592653589793;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q=1; q<=t; q++) {
		double v,d,a,b,c,aa,e;
		int n,k;
		cin>>d>>n>>k;
		printf("Case #%d:\n",q);
		if (n!=1) {
			cin>>a>>b>>c>>e;
			//v=(e-b)/(c-a);
			double t1=(d-b)*(c-a)/(e-b);
			forn(j,k) {
				cin>>aa;
				double t2=sqrt(d/(0.5*aa));
				printf("%.7llf\n",max(t1,t2));
			}
		} else {
			cin>>a>>b;
			forn(j,k) {
				cin>>aa;
				double t2=sqrt(d/(0.5*aa));
				printf("%.7llf\n",t2);
			}
		}
	}	
	return 0;
}