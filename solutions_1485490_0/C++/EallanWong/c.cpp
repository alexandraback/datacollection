#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;

#define maxn 110
#define datat long long
#define ansdatat int

int n,m;
datat x[maxn],y[maxn],a[maxn],b[maxn],ans;

void init_deal(){
}

int main(){
	
	int tttt;
	scanf("%d", &tttt);
	for(int ttt = 1;ttt<=tttt;ttt++){
		printf("Case #%d: ",ttt);

		ans = 0;
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			cin>>y[i]>>x[i];
		}
		
		while (true)
		{
			bool more = false;
			for (int i = 1; i<n; i++)
				if(x[i] == x[i+1])
			{
				more = true;
				y[i] = y[i]+y[i+1];
				for(int j = i+1;j<n;j++){
					x[i] = x[i+1];
					y[i] = y[i+1];
				}
				n--;
				break;
			}
			if (!more)
			{
				break;
			}
		}
		for(int j = 1;j<=m;j++){
			cin>>b[j]>>a[j];
		}

		if(n == 1){
			datat tot = 0;
			for(int i = 1;i<=m;i++)
				if(x[1] == a[i]){
					tot+=b[i];
			}
			ans = min(tot,y[1]);
		}
		else
		if(n == 2){
			for (int div = 0; div <=m; div++)
			{
				datat tmp = 0;
				int ok[3] = {1,div,m+1};
				datat tot = 0;
				for(int j = 0;j<2;j++){
					tot = 0;
					for(int i = ok[j];i<=ok[j+1];i++)
						if(x[j+1] == a[i]){
							tot+=b[i];
					}
					tmp += min(tot,y[j+1]);
				}
				if(ans<tmp)
					ans = tmp;
			}
		}
		else
		if(n == 3){
			for (int div1 = 0; div1 <=m; div1++)
				for(int div2 = div1;div2<=m;div2++)
			{
				datat tmp = 0;
				int ok[4] = {1,div1,div2,m+1};
				datat tot = 0;
				for(int j = 0;j<3;j++){
					tot = 0;
					for(int i = ok[j];i<=ok[j+1];i++)
						if(x[j+1] == a[i]){
							tot+=b[i];
					}
					tmp += min(tot,y[j+1]);
				}
				if(ans<tmp)
					ans = tmp;
			}
		}

		//cout>>ans>>endl;
		//printf("%lld\n", ans);
		cout<<ans<<endl;


	}
	

	return 0;
};

