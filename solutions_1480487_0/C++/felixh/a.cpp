#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)
#define EPS 1e-9

struct Tuple {
	int idx, pts;
	long double vote;
};
bool pts_cmp(Tuple a, Tuple b){ return a.pts < b.pts; }
bool idx_cmp(Tuple a, Tuple b){ return a.idx < b.idx; }

vector<Tuple> arr;
int T,N,X;

bool eliminated(int i, long double Y){
	long double scorei = arr[i].pts + X*Y;
	long double rem = 1.0 - Y;
	REP(j,N) if (j!=i){
		if (scorei < arr[j].pts) return true;
		long double needVote = (scorei - arr[j].pts) / X;
		if (needVote > 0){
			rem -= needVote;
			if (rem < 0) return false;
		} else {
			long double scorej = arr[j].pts + X*rem;
			if (scorei < scorej) return true;
		}
	}
	return rem > 0;
}

int main(){
	scanf("%d",&T);
	for (int tc=1; T--; tc++){
		scanf("%d",&N);
		
		X = 0;
		arr.resize(N);
		REP(i,N){
			arr[i].idx = i;
			scanf("%d",&arr[i].pts);
			X += arr[i].pts;
		}
		sort(arr.begin(), arr.end(), pts_cmp);
		
		REP(i,N){
			long double lo=0.0, hi=1.0, res = -1;
			REP(xx,1000){
				long double Y = (lo+hi)/2.0;
				if (eliminated(i,Y)){
					lo = Y;
				} else {
					hi = Y;
					res = Y;
				}
			}
			arr[i].vote = res;
		}

		sort(arr.begin(), arr.end(), idx_cmp);

		printf("Case #%d:",tc);
		REP(i,N) printf(" %.9Lf",arr[i].vote * 100);
		puts("");
	}
}
