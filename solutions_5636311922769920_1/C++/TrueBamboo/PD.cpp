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

long long power(long long x, long long y) {
	long long p=1;
	for (;y;y--)
	p*=x;
	return p;
}

int main() {
	long long T,t,k,c,s,i,j,p,q;
	cin>>T;
	for (t=1;t<=T;t++) {
		printf("Case #%I64d:",t);
		cin>>k>>c>>s;
		if ((k-1)/c+1>s) {
			printf(" IMPOSSIBLE");
		}
		else {
			for (i=0;i<(k-1)/c+1;i++) {
				p=q=i*c+1;
				for (j=1;j<c;j++) {
					q++;
					if (q>k)
					q=k;
					p=(p-1)*k+q;
				}
				printf(" %I64d",p);
			}
		}
		printf("\n");
	}
    return 0;
}
