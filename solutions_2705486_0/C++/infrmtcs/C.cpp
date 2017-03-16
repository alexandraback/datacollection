#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#define fi "C.INP"
#define fo "C.OUT"
#define nmax 5000+5
#define mmax 600000+5
#define INF 1000000000
using namespace std;
typedef vector<int> VI;
//VARIABLES
int m,n,f[nmax][nmax],d[nmax];
char s[nmax];
string a[mmax],st,sx;
VI c[nmax];
//MAIN
int Check(string &p, string &q)
{
	int m=int(p.size()),last=-INF,S=0;
	for (int i=0;i<m;++i)
	if (p[i]!=q[i])
	{
		if (abs(last-i)<5) return INF;
		++S;last=i;
	}
	return S;
}
int main()
{
	int test;
	VI::iterator it;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
	m=521196;
	for (int i=1;i<=m;++i)
	{
		scanf("%s",&s);
		a[i]=string(s);
		c[int(a[i].size())].push_back(i);
	}
//	for (int i=0;i<15;++i) cout << int(c[i].size()) << endl;
	scanf("%d",&test);
	for (int tc=1;tc<=test;++tc)
	{
		scanf("%s",&s);
		st=string(s);n=int(st.size());
		cerr << tc << endl;
		for (int i=0;i<n;++i)
		for (int j=1;i+j-1<n;++j)
		{
			f[i][i+j-1]=INF;
			sx=st.substr(i,j);
			for (it=c[j].begin();it!=c[j].end();++it) f[i][i+j-1]=min(f[i][i+j-1],Check(sx,a[*it]));
//			cout << i << " " << j << "    " << f[i][i+j-1] << endl;
		}
		d[0]=0;
		for (int i=1;i<=n;++i)
		{
			d[i]=INF;
			for (int j=0;j<i;++j) d[i]=min(d[i],d[j]+f[j][i-1]);
		}
		printf("Case #%d: %d\n",tc,d[n]);
	}
       return 0;
}
