#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

#define MAXN 2000010

vector<int> R[MAXN];
int TC,A,B;

int main(){
	REP(i,MAXN){
		int F=i, B=0, P=1, P2=1;
		for (int j=F; j; j/=10) P2 *= 10;
		while (1){
			B += P * (F%10);
			F /= 10;
			P *= 10;
			P2 /= 10;
			if (!F) break;
			assert(P2>=10);
			int j = B*P2 + F;
			if (i<j) R[i].push_back(j);
		}
		R[i].erase(unique(R[i].begin(), R[i].end()), R[i].end());
	}

	scanf("%d",&TC);
	for (int tc=1; TC--; tc++){
		scanf("%d %d",&A,&B);
		int res = 0;
		for (int i=A; i<=B; i++)
			REP(j,R[i].size())
				if (i<R[i][j] && R[i][j]<=B)
					res++;
		printf("Case #%d: %d\n",tc,res);
		fprintf(stderr,"Case #%d: %d\n",tc,res);
	}
}
