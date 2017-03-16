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
using namespace std;

#define pii pair < int , int >
#define i64 long long
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

double pb[100090];

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int I,T,i,j,a,b;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>a>>b;
		for(i=1;i<=a;i++) scanf("%lf",&pb[i]);
		pb[0]=1;
		for(i=1;i<=a;i++) pb[i]*=pb[i-1];
		double q=b+2,t;
		//cout<<q<<'\n';
		for(i=a;i>=0;i--) {
			t=(a-i+b-i+1)+(1-pb[i])*(b+1);
			//cout<<i<<' '<<t<<' '<<(a-i+b-i+1)<<' '<<(1-pb[i])<<' '<<(b+1)<<'\n';
			q=min(t,q);
		}
		printf("Case #%d: %.9lf\n",I,q);
	}
	return 0;
}
