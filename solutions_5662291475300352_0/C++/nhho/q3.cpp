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

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define W(x) while(x-->0)
#define SI(x) scanf("%d",&x)
#define pb push_back

using namespace std;

int t,n;
int d[1005],h[1005];
long long int m[1005];
int ans;

int main(){
	SI(t);
	F2(tt,1,t){
		SI(n);
		F1(a,0,n){
			SI(d[a]);
			SI(h[a]);
			scanf("%lld",&m[a]);
		}
		if(n==1){
			d[1]=d[0];
			m[1]=m[0]+1;
		}
		if(m[0]==m[1])ans=0;
		else{
			if(m[0]>m[1]){
				swap(m[0],m[1]);
				swap(d[0],d[1]);
			}
			d[0]-=360;
			//printf(" %d %d %lld %lld\n",d[0],d[1],m[0],m[1]);
			//printf("   %lld %lld\n",(d[1]-d[0])*m[0],(360-d[1])*(m[1]-m[0]));
			if((d[1]-d[0])*m[0]>(360-d[1])*(m[1]-m[0]))ans=0;
			else ans=1;
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	//system("pause");
    return 0;
}
