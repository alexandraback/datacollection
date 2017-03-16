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
using namespace std;

#define pii pair < int , int >
#define pdi pair < pii , int >
#define i64 long long
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

pii d[2][10000];
bool vis[3000];

int main() {
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-small-attempt3.out","w",stdout);
	int I,T,i,q,n,u,m,c,j;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n;
		m=0;
		CLR(vis);
		for(i=0;i<n;i++) {
			cin>>u;
			d[0][i]=pii(u,i);
			cin>>u;
			d[1][i]=pii(u,i);
		}
		sort(d[0],d[0]+n);
		sort(d[1],d[1]+n);
		q=c=0;
		bool f=1;
		
		for(i=j=0;i<n;i++) {
			while(j<n && c>=d[1][j].first) {
				if(!vis[d[1][j].second]) c+=2;
				else c++;
				vis[d[1][j].second]=1;
				q++;
				j++;
			}
			if(j>=n) break;
			if(c<d[0][i].first) {
				f=0;
				break;
			}
			if(!vis[d[0][i].second]) {
				c++;
				q++;
				vis[d[0][i].second]=1;
			}
		}
		if(j<n) f=0;
		if(f) printf("Case #%d: %d\n",I,q);
		else printf("Case #%d: Too Bad\n",I);
	}
	return 0;
}
