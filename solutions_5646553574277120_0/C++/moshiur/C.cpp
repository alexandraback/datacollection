#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;

int C,D,V;
int coins[111];

void update(set<int>& valid, int val){
	vector<int> newVals;
	for (set<int>::iterator it = valid.begin(); it != valid.end(); ++it){
		int x = *it + val;	
		if (x <= V){
			newVals.push_back(x);
		}
	}

	for (int i=0;i<newVals.size();++i) valid.insert(newVals[i]);
}

int main(){
	int T=INT;
	REP(t,1,T){
		C=INT;D=INT;V=INT;	
		FOR(i,D)coins[i]=INT;	

		set<int> valid;
		valid.insert(0);
		FOR(i,D)update(valid,coins[i]);

		int ans=0;
		REP(i,1,V){
			if(valid.count(i)==0){
				++ans;
				update(valid, i);
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
