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
	int T,t;
	cin>>T;
	int n,i,j,a[2600];
	for (t=1;t<=T;t++){
		cin>>n;
		memset(a,0,sizeof(a));
		for (i=0;i<n*(2*n-1);i++) {
			scanf("%d",&j);
			a[j]++;
		}
		printf("Case #%d:", t);
		for (i=0;i<=2500;i++)
		if (a[i]%2==1)
		printf(" %d",i);
		printf("\n");
	}
    return 0;
}
