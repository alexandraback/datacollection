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

int main() {
	long long n,j,i,C,c,p,m;
	cin>>C;
	for (c=1;c<=C;c++) {
		cin>>n>>j;
		printf("Case #%I64d:\n", c);
		for (;j;j--) {
			p=0;
			char s[110];
			s[0]=s[n/2-1]=s[n/2]=s[n-1]='1';
			s[n]=0;
			int x=j;
			for (i=1;i<=n/2-2;i++) {
				s[i]=s[n/2+i]='0'+x%2;
				x/=2;
			}
			printf("%s",s);
			for (i=2;i<=10;i++) {
				p=0;
				for (m=0;m<n/2;m++) {
					p=p*i+s[m]-'0';
				}
				printf(" %I64d",p);
			}
			printf("\n");
		}
	}
    return 0;
}
