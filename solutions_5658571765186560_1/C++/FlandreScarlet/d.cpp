#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int main() {
	int tt,x,r,c;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: ",te);
		if (r*c%x!=0) {
			puts("RICHARD");
			continue;
		}
		if (x>=7) {
			puts("RICHARD");
		}
		if (x==1) {
			puts("GABRIEL");
		}
		if (x==2) {
			puts("GABRIEL");
		}
		if (x==3) {
			if (min(r,c)<2) {
				puts("RICHARD");
				continue;
			}
			puts("GABRIEL");
		}
		if (x==4) {
			if (min(r,c)<2) {
				puts("RICHARD");
				continue;
			}
			if (r*c/x<3) {
				puts("RICHARD");
				continue;
			}
			puts("GABRIEL");
		}
		if (x==5) {
			if (min(r,c)<3) {
				puts("RICHARD");
				continue;
			}
			if (r*c/x<3) {
				puts("RICHARD");
				continue;
			}
			puts("GABRIEL");
		}
		if (x==6) {
			if (min(r,c)<3) {
				puts("RICHARD");
				continue;
			}
			if (r*c/x<3) {
				puts("RICHARD");
				continue;
			}
			puts("GABRIEL");
		}
	}
}
