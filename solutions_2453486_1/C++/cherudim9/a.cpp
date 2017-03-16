#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <ctime>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

char a[10][10];

bool Win(char opp){
	Rep(i,1,4){
		bool won=1;
		Rep(j,1,4)
			if (a[i][j]==opp || a[i][j]=='.')
				won=0;
		if (won)
			return 1;
	}

	Rep(j,1,4){
		bool won=1;
		Rep(i,1,4)
			if (a[i][j]==opp || a[i][j]=='.')
				won=0;
		if (won)
			return 1;
	}

	bool won=1;
	Rep(i,1,4)
		if (a[i][i]==opp || a[i][i]=='.')
			won=0;
	if (won)
		return 1;

	won=1;
	Rep(i,1,4)
		if (a[i][5-i]==opp || a[i][5-i]=='.')
			won=0;
	if (won)
		return 1;

	return 0;
}

void doit(){
	int nEmpty=0;
	Rep(i,1,4){
		scanf("%s",a[i]+1);
		Rep(j,1,4)
			if (a[i][j]=='.')
				nEmpty++;
	}

	if (Win('O')){
		puts("X won");
		return;
	}
	if (Win('X')){
		puts("O won");
		return;
	}

	if (nEmpty){
		puts("Game has not completed");
		return;
	}
	puts("Draw");
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int TT;
	cin>>TT;

	Rep(tt,1,TT){
		printf("Case #%d: ",tt);
		doit();
	}

    return 0;
}
