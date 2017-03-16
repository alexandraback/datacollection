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
	int T,t,p,i;
	cin>>T;
	for (t=1;t<=T;t++) {
		char s[110];
		scanf("%s",s);
		p=0;
		for (i=1;i<strlen(s);i++)
		if (s[i]!=s[i-1])
			p++;
		if (s[strlen(s)-1]=='-')
			p++;
		printf("Case #%d: %d\n",t,p);
	}
    return 0;
}
