//BISMILLAHIRRAHMANIRRAHIM



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define pii pair < int , int >
#define i64 long long
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

int d[300],n,s;

bool chk(double a,int p,double lf) {
	int i;
	double t;
	for(i=0;i<n;i++) if(i!=p && a>d[i]) {
		t=double(a-d[i])/s;
		//cout<<' '<<d[i]<<' '<<t<<' '<<lf<<'\n';
		if(t>lf) return true;
		lf-=t;
	}
	if(fabs(lf)>1e-10) return false;
	return true;
}

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int I,T,i,j;
	double st,fn,md;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n;
		s=0;
		for(i=0;i<n;i++) {
			cin>>d[i];
			s+=d[i];
		}
		printf("Case #%d:",I);
		for(i=0;i<n;i++) {
			st=0;
			fn=1;
			j=500;
			while(j--) {
				md=(st+fn)/2;
				//cout<<i<<' '<<st<<' '<<fn<<' '<<md<<'\n';
				if(chk(d[i]+s*md,i,1-md)) fn=md;
				else st=md;
			}
			md=(st+fn)*50;
			printf(" %.9lf",md+1e-8);
		}
		puts("");
	}
	return 0;
}
