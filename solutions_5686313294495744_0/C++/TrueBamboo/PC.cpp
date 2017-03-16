#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

set <string> l,r;
int code[1<<16];

int main() {
	int T,t,n,i,j,k,s;
	cin>>T;
	string a[20][2];
	memset(code,0,sizeof(code));
	for (i=1;i<(1<<16);i++)
	code[i]=code[i/2]+i%2;
	for (t=1;t<=T;t++) {
		cin>>n;
		for (i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1];
		s=0;
		for (k=0;k<(1<<n);k++)
		if (s<code[k]) {
			l.clear();
			r.clear();
			for (i=0;i<n;i++)
			if ((k&(1<<i))==0) {
				l.insert(a[i][0]);
				r.insert(a[i][1]);
			}
			for (i=0;i<n;i++)
			if ((k&(1<<i))>0) {
				if (l.find(a[i][0]) == l.end() || r.find(a[i][1]) == r.end())
				break;
			}
			if (i==n)
			s=code[k];
		}
		printf("Case #%d: %d\n",t,s);
	}
    return 0;
}

