#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>

#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,at;
char x[1005];
pair<char,int> y[1005];
vector<char> za,zb;

int main(){
	scanf("%d",&t);
	F2(a,1,t){
		n=0;
		scanf("%s",x);
		while(x[n]){
			y[n]=make_pair(x[n],n);			
			n++;
		}
		sort(y,y+n);
		at=n;
		F4(b,n-1,0)if(y[b].second<at){
			za.pb(y[b].first);
			F3(c,at-1,y[b].second)zb.pb(x[c]);
			at=y[b].second;
		}
		F1(b,0,n)x[b]=0;
		printf("Case #%d: ",a);
		F1(b,0,za.size())printf("%c",za[b]);
		reverse(zb.begin(),zb.end());
		F1(b,0,zb.size())printf("%c",zb[b]);
		za.clear(),zb.clear();
		printf("\n");
	}
	//system("pause");
	return 0;
}
