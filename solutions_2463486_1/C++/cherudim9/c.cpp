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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

vector<LL> F;

bool parlin(LL x){
	stringstream O;
	O<<x;
	string s;
	O>>s;
	string s1(s);
	reverse(ALL(s1));
	return s==s1;
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	Rep(i,1,(int)1e7)
		if (parlin(i) && parlin((LL)i*i))
			F.pb((LL)i*i);//cout<<i<<" "<<(LL)i*i<<endl;

	int TT;
	cin>>TT;
	Rep(tt,1,TT){
		printf("Case #%d: ",tt);
		LL A,B;
		cin>>A>>B;
		cout<<lower_bound(ALL(F),B+1)-lower_bound(ALL(F),A)<<endl;
	}

    return 0;
}
