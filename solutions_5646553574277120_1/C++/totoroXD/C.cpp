#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <string>
typedef long long LL;
int MOD=1000000007;
using namespace std;
int n;
int c,d,v;
int num[111];

void input(){
    scanf("%d%d%d",&c,&d,&v);
    for(int i=0; i<d; i++)scanf("%d",&num[i]);
}

void solve(){
	static int cas=1;
	printf("Case #%d: ",cas++);
	sort(num,num+n);
	int res=0;
	LL s=0;
	for(LL i=0; i<d; i++){
		if(s>=v)break;
		while(num[i]>s+1 && s<v){
			res++;
			s+= LL(c)*(s+1);
		}
		s+= LL(c)*num[i];
	}
	while( s<v){
		res++;
		s+= LL(c)*(s+1);
	}
	printf("%d\n",res);
}

int main()
{
	int zz;
	scanf("%d",&zz);
	while(zz--){
	    input();
	    solve();
	}
}

/*
5 2
-1 1 2 -1 1
*/