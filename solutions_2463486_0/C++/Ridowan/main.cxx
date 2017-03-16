//BISMILLAHIRRAHMANIRRAHIM



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define i64 long long
#define pii pair < int , int >
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)
#define mx 10000000

i64 rt[mx+10],sq[mx+10];

bool ispal(i64 a) {
	int d[16],l=0;
	while(a) {
		d[l++]=a%10;
		a/=10;
	}
	int i=0,j=l-1;
	while(i<j) {
		if(d[i]!=d[j]) return false;
		i++;j--;
	}
	return true;
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output2.out","w",stdout);
	int I,T,l=0;
	i64 i,j;
	for(i=1;i<=mx;i++) if(ispal(i) && ispal(i*i)) {
		rt[l]=i;
		sq[l]=i*i;
		l++;
	}
	cerr<<l<<'\n';
	//for(i=0;i<40;i++) cout<<rt[i]<<' '<<sq[i]<<'\n';
	cin>>T;
	i64 a,b;
	for(I=1;I<=T;I++) {
		cin>>a>>b;
		i=int(lower_bound(sq,sq+l,a)-sq);
		j=int(upper_bound(sq,sq+l,b)-sq);
		printf("Case #%d: %lld\n",I,j-i);
	}
	return 0;
}
