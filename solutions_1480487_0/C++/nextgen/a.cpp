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

int n;
vector<int>v;
double s;

double b_s(double left, double right, int i) {
	while(fabs(right-left)>EPS){
		double mid=(left+right)/2;
		double m=1-mid;
		double score=v[i]+s*mid;
		bool boo=1;
		double ans=0;
		forn(j,n){
			if(j==i) continue;
			if(score<v[j]) continue;
			ans+=(score-v[j])/s;
		}
		if(ans>m) boo=0;
		if(boo)	left=mid;
		else right=mid;
	}
	return right;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q=1; q<=t; q++) {
		scanf("%d",&n);
		v.resize(n);
		s=0;
		forn(i,n) {
			scanf("%d",&v[i]);
			s+=v[i];
		}
		printf("Case #%d:",q);
		forn(i,n) {
			double r=b_s(0,1,i);
            printf(" %.6lf",r*100);
		}
		printf("\n");
	}
	return 0;
}