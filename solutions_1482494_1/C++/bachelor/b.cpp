#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int MAXN = 1010;
int a[MAXN], b[MAXN], vis[MAXN];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, n;
	int have, com, ans;
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
		cin>>n;
		for(int i = 1; i <= n; ++i){
			cin>>a[i]>>b[i];
			vis[i] = 0;
		}
		ans = have = com = 0;
		int flag = 1;
		
		while(com < n && flag){
			int h = have;
			int f = 1;
			while(f){//judeg 2-starts
				f = 0;
				for(int i = 1; i <= n; ++i){
					if(vis[i] != 2 && have >= b[i]){
						have += 2 - vis[i];
						vis[i] = 2;
						f = 1;
						++com;
						++ans;
					}
				}
			}
			int os = -1;
			for(int i = 1; i <= n; ++i){
				if(vis[i] == 0 && have >= a[i]){
					if(os == -1 || b[i] > b[os])os = i;
				}
			}
			if(os != -1){
				vis[os] = 1;
				have++;
				++ans;
			}
			flag = (h != have);
		}
		if(com == n){
			printf("Case #%d: %d\n", tt, ans);
		}else {
			printf("Case #%d: Too Bad\n", tt);
		}
	}
	
	return 0;
}	
