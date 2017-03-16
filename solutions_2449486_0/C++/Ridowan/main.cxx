//BISMILLAHIRRAHMANIRRAHIM



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define i64 long long
#define pii pair < int , int >
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

int cm[110],rm[110],g[110][110];

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	int I,T;
	int n,m,i,j;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n>>m;
		CLR(cm);
		CLR(rm);
		for(i=0;i<n;i++) for(j=0;j<m;j++) {
			cin>>g[i][j];
			cm[i]=max(cm[i],g[i][j]);
			rm[j]=max(rm[j],g[i][j]);
		}
		bool f=1;
		for(i=0;i<n;i++) for(j=0;j<m;j++) if(g[i][j]!=min(cm[i],rm[j])) f=0;
		printf("Case #%d: %s\n",I,f?"YES":"NO");
	}
	return 0;
}
