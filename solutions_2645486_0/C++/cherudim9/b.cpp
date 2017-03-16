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

const int MaxN=10000+10;

int E,R,N;
int V[MaxN];
LL ans;

LL ff(int E1, int E2, int *V, int N){
	if (N==0)
		return 0;

	int mid=1;
	Rep(i,1,N)
		if (V[i]>V[mid])
			mid=i;

	int E4=(int)max(0LL, E2-((LL)N-mid+1)*R);
	int E3=(int)min((LL)E, E1+((LL)mid-1)*R);

	//cout<<E3<<" "<<E4<<endl;

	return ((LL)E3-E4)*V[mid] + ff(E1,E3,V,mid-1) + ff(min(E,E4+R),E2,V+mid,N-mid) ;
}

int main2(){
	cin>>E>>R>>N;
	Rep(i,1,N) scanf("%d",V+i);

	ans=0;

	ans=ff(E,0,V,N);

	cout<<ans<<endl;

	return 0;
}

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int TC;
	cin>>TC;
	Rep(tc,1,TC){
		printf("Case #%d: ",tc);
		main2();
	}


    return 0;
}
