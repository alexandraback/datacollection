#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back
#define EPS 1e-11

int n, ns;

char ts[11111];
int s[11111], p[11111], l[11111];
bool fr[11111];

double ep[1111111];
int nep;

bool pos[2][1211111];
bool vl[1211111];

int main() {

int nt, tt=0; scanf("%d", &nt); while(nt--){
	scanf("%d", &n);
	FOR(i,0,n){
		scanf("%s%d%d", ts, &s[i], &p[i]);
		l[i] = (ts[0]=='L'?0:1);
	}

	nep = 0;
	ep[nep++] = 0.0;

	FOR(i,0,n)FOR(j,0,n) if(s[i]>s[j]){
		double tep;
		tep = -(p[i]-(p[j]-5.0))*1.0/(s[i]-s[j]);
		if(tep > 0.0) ep[nep++] = tep;
		tep = -(p[i]-(p[j]+0.0))*1.0/(s[i]-s[j]);
		if(tep > 0.0) ep[nep++] = tep;
		tep = -(p[i]-(p[j]+5.0))*1.0/(s[i]-s[j]);
		if(tep > 0.0) ep[nep++] = tep;
	}

	sort(ep, ep+nep);
	int onep = nep; nep = 0;
	FOR(i,0,onep) if(nep == 0 || ep[i]-ep[nep-1]>EPS)
		ep[nep++] = ep[i];

	ns = (1<<n);

	int i0=0, i1=1;
	FOR(k,0,ns) pos[i0][k] = false;
	{
		int x = 0; FOR(i,0,n) if(l[i]) x += (1<<i);
		pos[i0][x] = true;
	}

#define COL(x,y) (fabs((x)-(y))<5.0-EPS)
#define DI(x,i) (((x)>>(i)) & 1)

	double t = 0.0;
	double ans = 0.0;

	bool bad = false;

	FOR(ti,0,nep){
		bad = true;

		t = ep[ti];
		FOR(k,0,ns){
			pos[i1][k] = false;
			vl[k] = true;
			FOR(i,0,n){
				double ix = p[i] + t*s[i];
				FOR(j,i+1,n) if(DI(k,i) == DI(k,j)){
					double jx = p[j] + t*s[j];
					if(COL(ix, jx)){
						vl[k] = false;
						break;
					}
				}
				if(!vl[k])break;
			}
		}

		//printf("%.3f : ", t);
		//FOR(k,0,ns)printf("%c", vl[k]?'X':'.'); printf(" ");

		FOR(i,0,n)fr[i] = true;
		FOR(i,0,n){
			double ix = p[i] + t*s[i];
			FOR(j,i+1,n){
				double jx = p[j] + t*s[j];
				if(COL(ix, jx)){
					fr[i] = fr[j] = false;
				}
			}
		}
		int mk = 0;
		FOR(i,0,n) if(fr[i]) mk += (1<<i);

		FOR(k,0,ns) if(pos[i0][k]){
			for(int tk=mk;; tk=((tk-1) & mk)){
				int k2 = (k^tk);
				if(vl[k2]){
					pos[i1][k2] = true;
					bad = false;
				}
				if(tk == 0)break;
			}
		}
		//FOR(k,0,ns)printf("%c", pos[i1][k]?'X':'.'); printf("\n");

		if(bad)break;
		ans = t;
		swap(i0, i1);
	}

	printf("Case #%d: ", ++tt);

	if(bad) printf("%.8f\n", ans); else printf("Possible\n");
}
	return 0;
}


