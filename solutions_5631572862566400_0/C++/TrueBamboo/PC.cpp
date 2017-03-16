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

int T,t;
int n,i,j,s,p,a[1100];
vector <int> from[1100];
bool v[1100];
int f[1100];
int b[1100];
int tp[1100];

int code(int d) {
	int j=a[d],mm=d;
	for (;j!=d;j=a[j])
	mm=min(mm,j);
	return mm;
}

int dfs(int d) {
	if (v[d])
		return 0;
	v[d]=1;
	int m=0;
	for (int k=0;k<from[d].size();k++)
	m=max(m,dfs(from[d][k]));
	return m+1;
}

int main() {
	cin>>T;
	for (t=1;t<=T;t++){
		int best = 2;
		memset(b,0,sizeof(b));
		cin>>n;
		memset(tp,0,sizeof(tp));
		for (i=1;i<=n;i++)
		from[i].clear();
		for (i=1;i<=n;i++) {
			scanf("%d",a+i);
			from[a[i]].push_back(i);
		}
		for (i=1;i<=n;i++) {
			memset(v,0,sizeof(v));
			s=0;
			for (j=i;!v[j];j=a[j]) {
				s++;
				v[j]=1;
				p=j;
			}
			if (a[j]==p) {
				v[p]=0;
				s+=dfs(p)-1;
			}
			else if (j!=i)
				s=0;
			if (a[j]==p){
				tp[code(p)]=1;
			}
			else if (j==i)
				tp[code(p)]=2;
			b[code(p)]=max(b[code(p)],s);
		}
		s=0;
		for (i=1;i<=n;i++)
		if (tp[i]==1)
		s+=b[i];
		for (i=1;i<=n;i++)
		if (tp[i]==2)
		s=max(s,b[i]);
		printf("Case #%d: %d\n",t,s);
	}
    return 0;
}
