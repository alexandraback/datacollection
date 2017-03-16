#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b) for(int a=0; a<b; a++)

using namespace std;

//returns how many do I need to add
int possible(int a, vector < int > mots){
	if(a==1 && mots.size()!=0)
		return 1000000;
	int adds=0;
	FOR(i, mots.size()){
		while(a<=mots[i]){
			a=a+(a-1);
			adds++;
		}
		a+=mots[i];
	}
	return adds;
}

//returns number of operations
int solveCase(){
	int A, N;
	scanf("%d", &A);
	scanf("%d", &N);
	
	vector < int > mots;
	mots.resize(N);
	FOR(i, N){
		scanf("%d", &mots[i]);
	}
	
	sort(mots.begin(), mots.end());
	
	int best=1000000;
	vector < int > nmots;
	FOR(i, N+1){
		nmots=mots;
		nmots.resize(i);
		
		//kolko ich odoberiem + kolko ich pridam
		int cur = (N-i) + possible(A, nmots);
		if (best> cur)
			best= cur;
	}
	return best;
}

int main(){
	int T;
	scanf("%d", &T);
	FOR(i,T)
		printf("Case #%d: %d\n", i+1, solveCase());	
}
