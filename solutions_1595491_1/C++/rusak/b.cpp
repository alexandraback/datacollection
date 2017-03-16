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
int t,n,p,s,a;

int main(){
	scanf("%d", &t);
	int u = 0;
while(t--){
	 u++;
	 scanf("%d%d%d", &n,&s,&p);
	 int res = 0;
	 REP(i,0,n){
	    scanf("%d", &a);
	    if(p==1){
	    	if(a != 0) res++;
	    }
	    else{
	    if(a >= 3*p-2) res++;
	    else if(a>=3*p-4){
	    	if(s>0){ res++; s--;}
	    }}
	 }
	 printf("Case #%d: %d\n", u,res);
}
}
