#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

map <string,int> l,r;
int cl[1100],cr[1100];
int g[2200][2200];
int hd,tl,ll[110000][3];
bool v[2200];

int main() {
	int T,t,n,i,j,k,n1,n2,end,m,is,it,x;
	cin>>T;
	string a[1100][2];
	for (t=1;t<=T;t++) {
		cin>>n;
		for (i=0;i<=n;i++)
		cl[i]=cr[i]=-1;
		l.clear();
		r.clear();
		for (i=0;i<n;i++) {
			cin>>a[i][0]>>a[i][1];
			fflush(fout);
			if (l.find(a[i][0])==l.end()) {
				l.insert(make_pair(a[i][0],l.size()+1));
			}
			cl[l.find(a[i][0])->second]++;
			if (r.find(a[i][1])==r.end()) {
				r.insert(make_pair(a[i][1],r.size()+1));
			}
			cr[r.find(a[i][1])->second]++;
		}
		memset(g,0,sizeof(g));
		n1=l.size();
		n2=r.size();
		end=1+n1+n2;
		for (i=1;i<=n1;i++) {
			g[0][i]=cl[i];
		}
		for (i=1;i<=n2;i++) {
			g[n1+i][end]=cr[i];
		}
		for (i=0;i<n;i++) {
			g[l.find(a[i][0])->second][n1+r.find(a[i][1])->second]=1;
		}
		m=0;
		while (1) {
			hd=0;
			tl=1;
			ll[0][0]=0;
			ll[0][1]=999999;
			memset(v,0,sizeof(v));
			v[0]=1;
			while (hd<tl) {
				x=ll[hd][0];
				if (x>=n1+1 && x<=n1+n2 && g[x][end]>0) {
					ll[tl][0]=end;
					ll[tl][1]=min(ll[hd][1],g[x][end]);
					ll[tl][2]=hd;
					break;
				}
				if (x==0) {
					is=1;
					it=n1;
				}
				else if (x>=0 && x<=n1) {
					is=n1+1;
					it=n1+n2;
				}
				else if (x>=n1+1 && x<=n1+n2) {
					is=1;
					it=n1;
				}
				for (k=is;k<=it;k++)
				if (!v[k] && g[x][k]>0) {
					v[k]=1;
					ll[tl][0]=k;
					ll[tl][1]=min(ll[hd][1],g[x][k]);
					ll[tl][2]=hd;
					tl++;
				}
				hd++;
			}
			if (hd==tl)
			break;
			x=ll[tl][1];
			m+=ll[tl][1];
			while (tl>0) {
				hd=ll[tl][2];
				is=ll[hd][0];
				it=ll[tl][0];
				g[is][it]-=x;
				g[it][is]+=x;
				tl=hd;
			}
		}
		printf("Case #%d: %d\n",t,m);
	}
    return 0;
}

