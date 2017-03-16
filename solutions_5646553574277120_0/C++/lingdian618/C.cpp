#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 33;
int f[N];
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("ou.txt", "w", stdout);
	int t, c, d, v, kase=0;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &c, &d, &v);
		memset(f, 0, sizeof(f));
		f[0] = 1;
		int cnt = v;
		for(int i=0; i<d; i++){
			int x;
			scanf("%d", &x);
			for(int j=v; j-x>=0; j--){
				if(f[j]==0 && f[j-x]){
					f[j] = 1;
					cnt--;
				}
			}
		}
		int ans = 0;
		while(cnt){
			int x;
			for(int i=1; i<=v; i++){
				if(f[i]==0){
					x = i;
					break;
				}
			}
			for(int j=v; j-x>=0; j--){
				if(f[j]==0 && f[j-x]){
					f[j] = 1;
					cnt--;
				}
			}
			ans++;
		}
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}