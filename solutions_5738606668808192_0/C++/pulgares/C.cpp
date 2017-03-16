#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

char on[40];

int main(){
	int TC;
	ri(TC);
	int N, J;
	rii(N,J);
	printf("Case #1:\n");
	for(int mascarita=0; mascarita<J; mascarita++){
		FOR(j,0,N/2-1){
			if(mascarita & (1<<j)){
				on[2*j]=on[2*j+1]='1';
			}else{
				on[2*j]=on[2*j+1]='0';
			}
		}
		printf("1%s1",on);
		FOR(b,2,11) printf(" %d",b+1);
		printf("\n");
	}
}

