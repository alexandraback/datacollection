#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

#define REP(i,a,b) 	for(int i=a;i<(int)b;i++)
#define FOR(it,A)	for(typeof A.begin() it=A.begin();it!=A.end();it++)
#define all(x) 		(x).begin(),(x).end()
#define pb 			push_back
#define clr(x,y)	memset(x,y,sizeof x)
#define oo 			(1<<30)
#define inf 		(1LL<<40)
#define bit(x)		__builtin_popcount(x)
#define mp			make_pair
#define fst			first
#define snd			second
#define maxN		100005
#define mod			1000000007

typedef long long     ll;
typedef vector<int>   vi;
typedef pair<int,int> pii;
typedef long double   ld;


int main(){
	
	int Cases;
	scanf("%d",&Cases);
	int A,B,K;
	REP(ii,1,Cases+1){
		printf("Case #%d:",ii);
		scanf("%d %d %d",&A,&B,&K);		
		vi ands;
		REP(i,0,A){
			REP(j,0,B){
				ands.pb(i&j);
			}
		}
		int ans=0;
		REP(i,0,ands.size()){
			if(ands[i]<K)ans++;
		}
		cout << " "<<ans <<endl;
	}	
	
    return 0;
}














