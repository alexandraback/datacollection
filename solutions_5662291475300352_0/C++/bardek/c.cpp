#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

#define fru(j,n) for(int j=0;j<(n);++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
typedef vector<int> vi;

const int MAXN = 1001;

vector<pii> czasy(int s,int m){
	s=360-s;
	vector<pii> R;
	fru(i,2){
		R.push_back(pii(1LL*s*m,1));
		s+=360;
	}
	fru(i,2){
		int d=__gcd(R[i].x,R[i].y);
		R[i].x/=d;
		R[i].y/=d;
	}
	return R;
}
bool mniejrow(pii a, pii b){
	return 1LL*a.x*b.y<=1LL*b.x*a.y;
}

int solve(){
	int n;
	scanf("%d",&n);
	int d[n],m[n],h[n];
	fru(i,n) scanf("%d%d%d",&d[i],&h[i],&m[i]);
	if(n==1 && h[0]==1) return 0;
	vector<vector<pii> >EE;
	fru(i,n) fru(j,h[i]) EE.push_back(czasy(d[i],m[i]+j));
	if(EE.size()>2) return -1;
//	fru(i,2) fru(j,2) printf("%d %d-te kolko w chiwli %.2lf\n",i,j,1.*EE[i][j].x/EE[i][j].y);
	fru(i,2) if(mniejrow(EE[i][1],EE[1-i][0])) return 1;
	return 0;
}
int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 printf("%d\n",solve());
	}
    return 0;
}
