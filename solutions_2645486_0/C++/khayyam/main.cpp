#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))


int E,R,N;
int v[100];
int cache[11][6];
int solve(int current, int e){
	if(current>=N){
		return 0;
	}
	if(cache[current][e]!=-1){
		return cache[current][e];
	}
	int best=-1;
	for(int i=0;i<=e;++i){
		int ne=MIN(E, e-i+R);
		int op=i*v[current]+solve(current+1, ne);
		if(best<op){
			best=op;
		}
	}
	return cache[current][e]=best;
}

int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		cin>>E>>R>>N;
		for(int i=0;i<N;++i){
			cin>>v[i];
		}
		memset(cache,-1,sizeof(cache));
		int sol=solve(0,E);
		printf("Case #%d: %d\n",c,sol);
	}
	return 0;
}

