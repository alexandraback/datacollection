#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

#define SIZE(X) ((int)(X.size()))
#define MP(X,Y) make_pair(X,Y)
#define two(X) (1<<(X))
typedef long long ll;

int A, B;
int power[10];
int vis[2000010];
/*inline int calclen(int n){
	for(int i = 1; i <= 7; ++i)
		if(n / power[i] < 10)return i;
}
*/
int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T, len, ans;
	power[0] = 1;
	for(int i = 1; i <= 7; ++i)
		power[i] = power[i - 1] * 10;
	
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
		memset(vis, 0, sizeof(vis));
		cin>>A>>B;
		ans = 0;
		for(int n = A; n <= B; ++n){
			for(int i = 1; i <= 7; ++i)
				if(n / power[i] == 0){
					len = i; break;
				}
			//cout<<n<<" "<<len<<endl;
			if(len == 1)continue;
			for(int i = 1; i < len; ++i){
				int m = n % power[len - i] * power[i] + n / power[len - i];
				if(n < m && m <= B && vis[m] != n){
					++ans;
					vis[m] = n;
				}
			}
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;				
}
