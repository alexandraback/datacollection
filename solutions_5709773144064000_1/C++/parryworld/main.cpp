#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#define mp make_pair
#define pb push_back
#define SCAN(n) scanf("%d",&n)
#define SCAN2(a,b) scanf("%d%d",&a,&b)
#define SCANS(a) scanf("%s",a)
#define PRINT(n) printf("%d\n",n)
#define sqr(a) ((a)*(a))
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N=1200010;
const int M=3000010;
const int INF=1e9;
const int MOD=1e9+7;
const double eps=1e-6;



void solve(){
	int t;
	SCAN(t);
	double c,f,x;
	for(int cs=1;cs<=t;cs++){
		scanf("%lf%lf%lf",&c,&f,&x);
		double m=2;
		double ans=0;
		while(m<(x*f-c*f)/c){
			ans+=c/m;
			m+=f;
		}
		ans+=x/m;
		printf("Case #%d: %.7lf\n",cs,ans);
	}
}

int main()
{
   	freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    //ios :: sync_with_stdio(false);
    solve();
    return 0;
}
