#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int gcd(int a, int b) {
	a=abs(a); b=abs(b);
	while (b!=0) { int c=a%b; a=b; b=c; }
	return a;
}

int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++) {
		int h,w,d;
		scanf("%d %d %d",&h,&w,&d);
		char s[35];
		int y0=-1,x0=-1;
		for (int i=0;i<h;i++) {
			scanf("%s",s);
			for (int j=0;j<w;j++) if (s[j]=='X') {
				y0=i-1; x0=j-1;
			}
		}
		h-=2; w-=2;
		set<pair<int,int> > rays;
		for (int y=-d;y<=d;y++) for (int x=-d;x<=d;x++) {
			if (x==0 && y==0) continue;
			int y1=(h-abs(y0))*2-1, y2=abs(y0)*2+1;
			if (y<0) { swap(y1,y2); y1*=-1; y2*=-1; }
			int dy=((abs(y)+1)/2)*y1 + (abs(y)/2)*y2;
			int x1=(w-abs(x0))*2-1, x2=abs(x0)*2+1;
			if (x<0) { swap(x1,x2); x1*=-1; x2*=-1; }
			int dx=((abs(x)+1)/2)*x1 + (abs(x)/2)*x2;
			if (dy*dy+dx*dx<=d*d) {
				int g=gcd(dx,dy);
				rays.insert(make_pair(dx/g,dy/g));
			}
		}
		printf("Case #%d: %d\n",test,rays.size());
	}
    return 0;
}
