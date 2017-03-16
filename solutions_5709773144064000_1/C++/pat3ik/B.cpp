#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

int main(){
	int t;
	double c,f,x,curr,time;
	
	scanf("%d",&t);
	FORR(tt,1,t + 1){
		scanf("%lf %lf %lf",&c,&f,&x);
		
		curr = 2.0;
		time = 0.0;
		double ans = x + x;
		FOR(it,100000 + 1){
			// buy farm
			ans = min(ans,time + x / curr);
			time += c / curr;
			curr += f;
		}
		printf("Case #%d: %.12lf\n",tt,ans);
	}
	
	return 0;
}
