#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back


int main(){
	int t; cin>>t;
	forn(tc,t){
		printf("Case #%d: ", tc+1);
		int a, b, k; cin>>a>>b>>k;
		int res = 0;
		forn(x,a)forn(y,b){
			if((x&y)<k)res++;
		}
		printf("%d\n",res);
	}
}
