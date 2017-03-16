#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>

using namespace std;

int t,n,tt,ans;
int x[1005];

int main(){
	scanf("%d",&t);
	for(int a=1;a<=t;a++){
		scanf("%d",&n);
		for(int b=0;b<n;b++)scanf("%d",&x[b]);
		ans=INT_MAX;
		for(int b=1;b<=1000;b++){
			tt=b;
			for(int c=0;c<n;c++)tt+=(x[c]-1)/b;
			ans=min(ans,tt);
		}
		printf("Case #%d: %d\n",a,ans);
	}
	//system("pause");
	return 0;
}
