#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <climits>

#define abs(X) (((X)<0)?-(X):(X))
using namespace std;
typedef pair<int,int> PI;
typedef long long ll;
int V[200], V2[200];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	int N, S;
	double P, Sf;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d",&N);
		S = 0;
		for (int j = 0; j < N; j++)
			scanf("%d",&V[j]), S+=V[j], V2[j] = V[j];
		int imin = 0, icount;
		for (int j = 0; j < S; j++){
			imin = 0;
			for (int k = 1; k < N; k++)
				if (V2[k]<V2[imin])
					imin = k;
			V2[imin]++;
		}
		imin = 0, icount = 0;
		for (int k = 1; k < N; k++){
				if (V2[k]<V2[imin])
					imin = k, icount = 0;
				if (V2[k]==V2[imin])
					icount++;
		}
		if (icount>1)
			for (int j = 0; j < S; j++)
				if (V2[j]==V2[imin]+1 && V2[j]!=V[j])
					V2[j]--;
		printf("Case #%d:",i+1);
		Sf = S;
		for (int j = 0; j < N; j++){
			P = V2[j]-V[j];
			P*=100;
			P/=Sf;
			printf(" %.8f",P);
		}
		printf("\n");
	}
	return 0;
}
