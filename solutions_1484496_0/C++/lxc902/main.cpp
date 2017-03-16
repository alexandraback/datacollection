#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[22];
int n;

void Out(int s) {
	int blank=0;
	for(int j=0;j<n;++j) if(s&(1<<j)) {
		if(blank) putchar(' ');
		blank=1;
		printf("%d",a[j]);
	}
	puts("");
}

char has[2000000+10];
int sta[2000000+10];

int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    int T; scanf("%d",&T);
    for(int ka=1;ka<=T;++ka) {
    	scanf("%d",&n);
    	for(int i=0;i<n;++i) scanf("%d",a+i);

    	memset(has,0,sizeof has);

    	int imp=1;
    	int s1,s2;
    	for(int s=0;s<(1<<20);++s) {
    		int sum=0;
    		for(int j=0;j<20;j++) if((1<<j)&s) {
    			sum+=a[j];
    		}
    		if(has[sum]) {
    			imp=0;
    			s1=s,s2=sta[sum];
    			break;
    		} else {
    			sta[sum]=s;
    			has[sum]=1;
    		}
    	}

		printf("Case #%d:\n",ka);
    	if(imp) puts("Impossible");
    	else {
    		Out(s1);
    		Out(s2);
    	}
    }

    return 0;
}
