
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
	for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back
#define MP make_pair

typedef long long LL;

int main() {
	int t;
	cin >> t;
	REP(tc,1,t) {
		int r,n,m,k;
		cin >> r >> n >> m >> k;
		cout << "Case #" << tc << ":" << endl;
		while (r--) {
			vector<int> V;
			FOR(i,0,k) {
				int tmp;
				cin >> tmp;
				V.PB(tmp);
			}
			if (n==1) {
				cout << V[0] << endl;
			}
			else if (n==2) {
				int gf=0;
				REP(i,2,m) {
					REP(j,2,m) {
						int pos1=i*j;
						int pos2=i;
						int pos3=j;
						int pos4=1;
						int flag=1;
						FOR(lp,0,k) {
							if (V[lp]==pos1 || V[lp]==pos2 || V[lp]==pos3 || V[lp]==pos4) {
							}
							else flag=0;
						}
						if (flag==1) {
							cout << i << j << endl;
							gf=1;
							break;
						}
					}
					if (gf) break;
				}
				if (gf==0) cout << 22 << endl;
			}
			else if (n==3) {
				int gf=0;
				REP(i,2,m) {
					REP(j,2,m) {
						REP(p,2,m) {
							int pos1=i*j,pos2=j*p,pos3=i*p,pos4=i,pos5=j,pos6=p,pos7=i*j*p,pos8=1;
							int flag=1;
							FOR(lp,0,k) {
								if (V[lp]==pos1 || V[lp]==pos2 || V[lp]==pos3 || V[lp]==pos4 || V[lp]==pos5 || V[lp]==pos6 || V[lp]==pos7 || V[lp]==pos8) {
								}
								else {
						//			if (i==2 && j==3 && p==4) cout << V[lp] << endl;
									flag=0;
								}
							}
							if (flag==1) {
								cout << i << j << p << endl;
								gf=1;
								break;
							}
						}
						if (gf) break;
					}
					if (gf) break;
				}
				if (gf==0) cout << 333 << endl;
			}
		}
	}
	return 0;
}
