#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define REP(i,a,b) for(int i=a; i<b; ++i)
#define DOWN(i,a,b) for(int i=a; i>=b; --i)
#define ft first
#define sd second
#define mp make_pair
#define pb push_back

using namespace std;

int A,B,ile,n,t,pot,u=0;

int main(){
	scanf("%d", &t);
while(t--){
	u++;
	scanf("%d%d", &A,&B);
	int v = A;
	pot = 1;
	while(v){ pot*=10; v/=10;}
	pot/=10;
	ile = 0;
	REP(x,A,B+1){
		
		int y = x;
		while(1){
			y = (y/10)+(y%10)*pot;
			if(y==x) break;
			if(y >= A && y <= B) ile++;
		}
	}
	printf("Case #%d: %d\n",u, ile/2);
}
}
