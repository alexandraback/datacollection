#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int task,n,m,s;
int main() {
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	scanf("%d",&task);
	for (int id=1;id<=task;id++) {
		scanf("%d",&n);
		if (n==0) {
			printf("Case #%d: INSOMNIA\n",id);
			continue;
		}
		s=0;
		m=n;
		while (1) {
			int t=m;
			while (t) {
				s|=1<<(t%10);
				t/=10;
			}
			if (s==1023) break;
			m+=n;
		}
		printf("Case #%d: %d\n",id,m);
	}
	return 0;
}
