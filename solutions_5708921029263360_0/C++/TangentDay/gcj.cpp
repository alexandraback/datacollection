#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)
#define pi M_PI

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

VI a, b, c;

void pb(int x, int y, int z){
	a.push_back(x);
	b.push_back(y);
	c.push_back(z);
	return;
}

int main(void) {
	ifstream ifs("input.txt");
	FILE *fp;
	fp = fopen("out.txt","w");
	int t;
	ifs >> t;
	REP(cas,t){		
		fprintf(fp,"Case #%d: ",cas+1);
		int j, p, s, k;
		ifs >> j >> p >> s >> k;

		a.clear();
		b.clear();
		c.clear();

		if (j==1){
			if (p==1){
				pb(1,1,1);
				if (s==2 && k>=2){
					pb(1,1,2);
				}else if (s==3){
					if (k>=2){
						pb(1,1,2);
					}
					if (k>=3){
						pb(1,1,3);
					}
				}
			}else if (p==2){
				if (s==2){
					pb(1,1,2);
					pb(1,2,1);
					if (k>=2){
						pb(1,1,1);
						pb(1,2,2);
					}
				}else if(s==3){
					pb(1,1,2);
					pb(1,2,1);
					if (k>=2){
						pb(1,1,1);
						pb(1,2,2);					
					}
					if (k>=3){
						pb(1,1,3);
						pb(1,2,3);
					}
				}
			}else if (p==3){
				pb(1,1,1);
				pb(1,2,2);
				pb(1,3,3);
				if (k>=2){
					pb(1,1,2);
					pb(1,2,3);
					pb(1,3,1);
				}
				if (k>=3){
					pb(1,2,1);
					pb(1,3,2);
					pb(1,1,3);
				}
			}
		}else if (j==2){
			if (p==2){
				if (s==2){
					pb(1,1,1);
					pb(1,2,2);
					pb(2,1,2);
					pb(2,2,1);
					if (k>=2){
						pb(1,1,2);
						pb(1,2,1);
						pb(2,1,1);
						pb(2,2,2);
					}
				}else if (s==3){
					pb(1,1,1);
					pb(1,2,2);
					pb(2,1,2);
					pb(2,2,1);
					if (k>=2){
						pb(1,1,2);
						pb(1,2,1);
						pb(2,2,2);
						pb(2,1,1);
					}
					if (k>=3){
						pb(1,1,3);
						pb(1,2,3);
						pb(2,2,3);
						pb(2,1,3);
					}
				}
			}else if (p==3){
				pb(1,1,1);
				pb(1,2,2);
				pb(1,3,3);
				pb(2,1,2);
				pb(2,2,3);
				pb(2,3,1);
				if (k>=2){
					pb(2,1,1);
					pb(2,2,2);
					pb(2,3,3);
					pb(1,1,2);
					pb(1,2,3);
					pb(1,3,1);
				}
				if (k>=3){
					pb(1,1,3);
					pb(1,2,1);
					pb(1,3,2);
					pb(2,1,3);
					pb(2,2,1);
					pb(2,3,2);
				}
			}
		}else if (j==3){
			pb(1,1,1);
			pb(1,2,2);
			pb(1,3,3);
			pb(2,1,2);
			pb(2,2,3);
			pb(2,3,1);
			pb(3,1,3);
			pb(3,2,1);
			pb(3,3,2);
			if (k>=2){
				pb(2,1,1);
				pb(2,2,2);
				pb(2,3,3);
				pb(3,1,2);
				pb(3,2,3);
				pb(3,3,1);
				pb(1,1,3);
				pb(1,2,1);
				pb(1,3,2);
			}
			if (k>=3){
				pb(3,1,1);
				pb(3,2,2);
				pb(3,3,3);
				pb(1,1,2);
				pb(1,2,3);
				pb(1,3,1);
				pb(2,1,3);
				pb(2,2,1);
				pb(2,3,2);
			}
		}

		fprintf(fp,"%d\n",a.size());
		cout << a.size() << endl;
		REP(i,a.size()){
			fprintf(fp,"%d %d %d\n",a[i],b[i],c[i]);
			printf("%d %d %d\n",a[i],b[i],c[i]);
		}

	}

	return 0;
}