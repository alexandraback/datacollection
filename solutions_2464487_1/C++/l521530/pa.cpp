
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )

typedef long long int LL;

using namespace std;

LL r,t;

bool enough(LL k){
	if( t/k >= 2*r+2*k-1 )return true;
	return false;
}

int main(){

	int zn;
	scanf("%d",&zn);
	for(int zi=0;zi<zn;zi++){
		cin >> r >> t;
		LL mn=1, mx=t, md;
		while(mn<mx){
			md=(mn+mx+1)/2;
			if(enough(md)) mn=md;
			else mx=md-1;
		}
		printf("Case #%d: ",zi+1);
		cout << mn << endl;
	}

	return 0;
}
