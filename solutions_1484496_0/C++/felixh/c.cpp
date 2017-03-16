#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

long long arr[501];
int T,N;

int main(){
	scanf("%d",&T);
	for (int tc=1; T--; tc++){
		printf("Case #%d:\n",tc);
		fprintf(stderr,"Case #%d:\n",tc);
		scanf("%d",&N);
		REP(i,N) scanf("%lld",&arr[i]);
		
		vector<pair<long long, int> > sums;
		REP(i,1<<N){
			if (i==0) continue;
			long long sum = 0;
			REP(j,N) if (i&(1<<j)) sum += arr[j];
			sums.push_back(make_pair(sum,i));
		}
		sort(sums.begin(), sums.end());
		REP(i,sums.size()-1){
			if (sums[i].first == sums[i+1].first){
				bool first = 1;
				REP(j,N) if (sums[i].second&(1<<j)){
					if (first) first = 0; else printf(" ");
					printf("%lld",arr[j]);
				}
				puts("");
				first = 1;
				REP(j,N) if (sums[i+1].second&(1<<j)){
					if (first) first = 0; else printf(" ");
					printf("%lld",arr[j]);
				}
				puts("");
				break;
			}
		}
	}
}
