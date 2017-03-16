#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

class DancingWiththeGooglers{
	int N,S,P;
	vector<int> T;
public:
	void init(){
		scanf("%d%d%d",&N,&S,&P);
		T.resize(N);
		REP(i,N)scanf("%d",&T[i]);
	}
	int run(){
		int res = 0;
		sort(ALL(T));
		reverse(ALL(T));
		REP(i,T.size()){
			int tPoint = T[i];
			int pattern = 0;
			for(int start=0 ; start<=10 ; start++){
				for(int a=0 ; a<=2 ; a++){
					for(int b=0 ; b<=2 ; b++){
						bool isS = (a==2||b==2);
						if(3*start+a+b==tPoint){
							int bResult = max(start+a,start+b);
							if(bResult>=P){
								if(!isS)pattern = 2;
								if(pattern==0 && isS)pattern = 1;
							}
						}
					}
				}
			}
			if(pattern==2)res++;
			if(S>0 && pattern==1){
				S--;
				res++;
			}
		}
		return res;
	}
};

int main(){
	int T;
	scanf("%d",&T);
	DancingWiththeGooglers solver;
	for(int c=1 ; c<=T ; c++){
		solver.init();
		printf("Case #%d: %d\n",c,solver.run());
	}
	return 0;
}
