#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
using namespace std;
int T,Ti;
int n;
int time[10],N[10];
int s[10],e[10];
int fs[10];
int delta_d[10];
int delta_p[10];
int delta_s[10];
int wallh[1000];
int Max[1000];
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		memset(wallh,0,sizeof(wallh));
		map<int,vector<int>> schedule;
		set<int> se;
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++) {
			scanf("%d",&time[i]);
			scanf("%d",&N[i]);
			scanf("%d%d",&s[i],&e[i]);
			scanf("%d",&fs[i]);
			scanf("%d%d%d",&delta_d[i],&delta_p[i],&delta_s[i]);
			for(j=0;j<N[i];j++) {
				schedule[time[i]+j*delta_d[i]].push_back(i);
				se.insert(time[i]+j*delta_d[i]);
			}
		}
		int cnt=0,tr;
		set<int>::iterator it;
		for(it=se.begin();it!=se.end();it++) {
			for(i=0;i<schedule[*it].size();i++) {
				tr=0;
				for(j=s[schedule[*it][i]];j<e[schedule[*it][i]];j++) {
					if(wallh[j+300]<fs[schedule[*it][i]]) {
						tr=1;
						Max[j+300]=Max[j+300]<fs[schedule[*it][i]]?fs[schedule[*it][i]]:Max[j+300];
					}
				}

				cnt+=tr;
				fs[schedule[*it][i]]+=delta_s[schedule[*it][i]];
				s[schedule[*it][i]]+=delta_p[schedule[*it][i]];
				e[schedule[*it][i]]+=delta_p[schedule[*it][i]];
			}
			for(j=0;j<1000;j++) {
				if(Max[j]>wallh[j]) wallh[j]=Max[j];
				Max[j]=0;
			}
		}
		printf("Case #%d: %d\n",Ti,cnt);
	}
	return 0;
}