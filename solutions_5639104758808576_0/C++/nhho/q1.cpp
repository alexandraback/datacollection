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

int t,n,m,ans;
char x;

int main(){
	scanf("%d%c",&t,&x);
	for(int a=1;a<=t;a++){
		m=0;
		ans=0;
		scanf("%d%c",&n,&x);
		for(int b=0;b<=n;b++){
			scanf("%c",&x);
			x-='0';
			if(x!=0){
				ans+=max(0,b-m);
				m+=max(0,b-m);
			}
			m+=x;
		}
		scanf("%c",&x);
		printf("Case #%d: %d\n",a,ans);
	}
	//system("pause");
	return 0;
}
