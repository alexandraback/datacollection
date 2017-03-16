#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define __ puts("")

using namespace std;

int nkasus;
char sc[15][15];
map<char,int> peta;
bool en,wn;

void cek(){
	if ((peta['O'] == 4) || (peta['T'] == 1 && peta['O'] == 3)){
		en = 1;
		wn = 0;
	}
	if ((peta['X'] == 4) || (peta['T'] == 1 && peta['X'] == 3)){
		en = 1;
		wn = 1;
	}	
}

int main(){
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		REP(i,4){
			scanf("%s", sc[i]);
		}
		
		bool emp = 0;
		REP(i,4){
			REP(j,4){
				if (sc[i][j] == '.') emp = 1;
			}
		}	
		
		en = 0;
		wn = 0;
		REP(i,4){
			peta.clear();
			REP(j,4){
				peta[sc[i][j]]++;
			}
			cek();
		}
		REP(j,4){
			peta.clear();
			REP(i,4){
				peta[sc[i][j]]++;
			}	
			cek();
		}
	
		peta.clear();
		REP(i,4){
			peta[sc[i][i]]++;
			cek();
		}
	
		peta.clear();
		REP(i,4){
			peta[sc[i][3-i]]++;
			cek();
		}
		
		printf("Case #%d: ", jt+1);
		if (en){
			printf("%c won\n", wn ? 'X' : 'O');
		}else{
			if (emp){
				printf("Game has not completed\n");
			}else{
				printf("Draw\n");
			}
		}
	}
	
	return 0;
}
