#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define INF 2123123123

#define LL long long
using namespace std;

int T,N,M;
string poscode[10];
bool admat[10][10];
int order[10];

string coba(){
	vector<int> stek;
/*
	REP(i,N){
		printf("%d ", order[i]);
	}
	printf("\n");
*/
	string ret = poscode[order[0]];
	stek.PB(order[0]);
//	printf("push %d\n", order[0]);
	FOR(i,1,N-1){
		while (!admat[stek.back()][order[i]]){
			stek.pop_back();
//			printf("pop\n");
			if (stek.size() == 0){
				// NO WAY
//				printf("wakacau\n");
				return "z";
			}
		}

//		printf("push %d\n", order[i]);
		stek.PB(order[i]);
		ret += poscode[order[i]];
	}

	return ret;
}

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d%d", &N, &M);
		REP(i,N){
			char sc[10];
			scanf("%s", sc);

			poscode[i] = sc;
		}
		RESET(admat,0);
		REP(i,M){
			int a,b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			admat[a][b] = 1;
			admat[b][a] = 1;
		}


		REP(i,N){
			order[i] = i;
		}
		string ans = "z";
		do{
			ans = min(ans, coba());
		}while (next_permutation(order, order + N));

		printf("Case #%d: %s\n", jt+1, ans.c_str());
	}
	return 0;
}
