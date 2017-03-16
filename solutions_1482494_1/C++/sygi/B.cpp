//Jakub Sygnowski
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
//#include<gmp.h> // http://gmplib.org/
//#include<gmpxx.h>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define ST first
#define ND second
#define INF 1000000007
#define PB push_back
#define MP make_pair
typedef pair<int,int> PII;
typedef long long LL;

int t;
bool done[1007], donehalf[1007];
int trzeba2[1007],n, trzeba1[1007], res, mam;
vector<pair<int,int> > koszty, mozna;
int main(){
	scanf("%d",&t);
	REP(nr,t){
		printf("Case #%d: ",nr+1);
		scanf("%d",&n);
		koszty.clear();
		mozna.clear();
		REP(i,n){ scanf("%d%d",&trzeba1[i], &trzeba2[i]);
			koszty.PB(MP(trzeba2[i], i));
			mozna.PB(MP(trzeba1[i], i));
			done[i] = false;
			donehalf[i] = false;
		}
		mam = 0;
		res = 0;
		sort(ALL(koszty));
		reverse(ALL(koszty));
		sort(ALL(mozna));
		reverse(ALL(mozna));
		while(koszty.size()){
			while(koszty.size() && koszty.back().ST <= mam){
				if (donehalf[koszty.back().ND]){
					mam += 1;
				} else mam +=2;
				done[koszty.back().ND] = true;
				donehalf[koszty.back().ND] = true;
				res += 1;
				koszty.pop_back();
			}
			if (!koszty.size()) break;
			int best = -1, gdzie = -1;
			REP(i, n){
				if (!donehalf[i] && trzeba1[i] <= mam){
					if (trzeba2[i] > best){
						best = trzeba2[i];
						gdzie = i;
					}
				}
			}
			if (best == -1){
				printf("Too Bad\n");
				break;
			}
			mam += 1;
			res += 1;
			donehalf[gdzie] = true;
		}
		if (!koszty.size()){
			printf("%d\n", res);
		}
	}
}
