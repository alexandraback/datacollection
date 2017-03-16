#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <ctime>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

#ifdef online
#else
#endif

#include <cmath>

void main2(){
	LL r,t;
	cin>>r>>t;

	LL le=1, ri=(LL)sqrt(t)+10;

	while(le<ri){
		LL x=(le+ri)/2+1;
		if ( 2.0*x*x-x+2.0*r*x > 1.5e18 || x*x*2-x+2*r*x > t )
			ri=x-1;
		else
			le=x;
	}

	cout<<le<<endl;
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int TC;
	cin>>TC;
	Rep(tc,1,TC){
		printf("Case #%d: ",tc);
		main2();
	}

    return 0;
}
