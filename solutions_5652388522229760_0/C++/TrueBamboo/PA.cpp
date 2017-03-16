#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<iterator>
#include<stack>
#include<queue>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

bool v[10];
int n,i,r,c,p;

void cal(int x) {
	while (x) {
		if (!v[x%10]) {
			r--;
			v[x%10]=1;
		}
		x/=10;
	}
	return;
}

int main() {
	cin >>n;
	for (c = 1; c <=n; c++) {
		memset(v,0,sizeof(v));
		scanf("%d",&p);
		if (p==0) {
			printf("Case #%d: INSOMNIA\n",c);
		}
		else {
			r = 10;
			for (i = 1; r > 0; i ++) {
				cal(p * i);
			}
			printf("Case #%d: %d\n",c,(i-1)*p);
		}
	}
    return 0;
}
