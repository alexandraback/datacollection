#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
int n,h[1005];
double d[1005],m[1005];
int main() {
	int tc;
	scanf("%d",&tc);
	for (int kk=0;kk<tc;kk++) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%lf%d%lf",&d[i],&h[i],&m[i]);
		}
		int ans;
		double d1,d2,s1,s2;
		if (n==1) {
			d1=d2=d[0];
			s1=360.0/m[0];
			s2=360.0/(m[0]+1.0);
		} else {
			if (m[0]<m[1]) {
				d1=d[0];
				d2=d[1];
				s1=360.0/m[0];
				s2=360.0/m[1];
			} else {
				d1=d[1];
				d2=d[0];
				s1=360.0/m[1];
				s2=360.0/m[0];
			}
		}
		double dd,s,t;
		if (d1>d2) {
			dd=360.0-d1+d2;
		} else {
			dd=360.0+d2-d1;
		}
		s=s1-s2;
		t=dd/s;
		double f=t*s2+d2;
		if (f>360.0) ans=0;
		else ans=1;
		/*
		if (n==1) {
			double t1=(720.0-d[0])/360.0*m[0];
			double t2=(360.0-d[0])/360.0*(m[0]+1.0);
			if (t1<t2) ans=1;
			else ans=0;
		} else if (n==2) {
			if (d[0]==d[1]) {
				if (m[0]<m[1]) {
					double t1=(720.0-d[0])/360.0*m[0];
					double t2=(360.0-d[1])/360.0*m[1];
					if (t1<t2) ans=1;
					else ans=0;
				} else {
					double t1=(720.0-d[1])/360.0*m[1];
					double t2=(360.0-d[0])/360.0*m[0];
					if (t1<t2) ans=1;
					else ans=0;
				}
			} else {
				if (m[0]<m[1]) {
					double t1=(720.0-d[0])/360.0*m[0];
					double t2=(360.0-d[1])/360.0*m[1];
					if (t1<t2) ans=1;
					else ans=0;
				} else {
					double t1=(720.0-d[1])/360.0*m[1];
					double t2=(360.0-d[0])/360.0*m[0];
					if (t1<t2) ans=1;
					else ans=0;
				}
			}
		}
		*/
		printf("Case #%d: %d\n", kk+1,ans);
	}
}