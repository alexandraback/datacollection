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
int S[20];
map<int,int> M;
int CASE;
bool check(int mask){
	int t = mask, s = 0;
	for (int i = 0; i < 20; i++, t/=2)
		if (t%2)
			s+=S[i];
	if (M.find(s)!=M.end()){
		printf("Case #%d:\n",CASE);
		t = M.find(s)->second;
		bool f = true;
		for (int i = 0; i < 20; i++, t/=2)
			if (t%2)
				if (f)
					printf("%d",S[i]), f = false;
				else
					printf(" %d",S[i]);
		printf("\n");
		t = mask;
		f = true;
		for (int i = 0; i < 20; i++, t/=2)
			if (t%2)
				if (f)
					printf("%d",S[i]), f = false;
				else
					printf(" %d",S[i]);
		printf("\n");
		return true;	
	} else {
		M[s] = mask;
		return false;
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T, N;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d",&N);
		M.clear();
		for (int j = 0; j < N; j++)
			scanf("%d",&S[j]);
		CASE = i+1;
		for (int j = 1; j < (1<<(N-1)); j++)
			if (check(j))
				break;
	}
	return 0;
}
