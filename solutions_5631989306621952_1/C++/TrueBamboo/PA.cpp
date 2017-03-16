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
	int T,t,i,j;
	cin>>T;
	char s[1100];
	for (t=1;t<=T;t++){
		string r = "";
		scanf("%s",s);
		printf("Case #%d: ", t);
		r=s[0];
		for (i=1;i<s[i];i++) {
			if (s[i]>=r[0]) {
				r=s[i]+r;
			}
			else r+=s[i];
		}
		cout<<r<<endl;
	}
    return 0;
}
