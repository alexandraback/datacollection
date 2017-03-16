#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
int cnt;
int s[32];

int main() {
	freopen("c.out","w",stdout);
	n=16; cnt=50;
	printf("Case #1:\n");
	
	for (int i=0;i<cnt;++i) {
		memset(s,0,sizeof(s));
		s[0]=s[n-1]=1;
		for (int j=0;j<8;++j)
			if ((i>>j)&1)
				s[j*2+1]=s[j*2+2]=1;

		for (int j=n-1;j>=0;--j)
			printf("%d",s[j]);
		printf(" 3 4 5 6 7 8 9 10 11\n");
	}
}