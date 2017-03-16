
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

int r[30],ty;

bool good(LL t){
	int l=0;
	while(t){
		r[l++]=t%10;
		t/=10;
	}
	for(int i=0;i<l;i++){
		if(r[i]!=r[l-1-i])return false;
	}
	ty=0;
	if(l&1 && r[l/2]==1)ty=1;
	for(int i=0;i<l;i++){
		if(r[i]==2) ty=2;
	}
	if(l&1 && r[l/2]==2 )ty=3;
	return true;
}

void go(){
	LL a,b;
	cin >> a >> b;
	LL sa=sqrt(a),sb=sqrt(b)+1;
		
	//cout << sa << '-' << sb << endl;
	LL ans=0;
	for(LL i=sa; i<=sb; i++){
		LL si=i*i;
		if(si<a || si>b)continue;
		if(good(si) && good(i)){
			ans++;
			//for(int j=0;j<9*ty;j++)printf(" ");
			//cout << i << endl;
		}
	}
	static int zi=0;
	printf("Case #%d: %lld\n",++zi,ans);
}


int main(){

	int zn;
	scanf("%d",&zn);
	while(zn--){
		go();
	}

	return 0;
}
