#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	freopen("C:/Users/lucio_yang/Downloads/A-small-attempt0.in","r",stdin);
	freopen("F:/A-small1.out", "w", stdout);
	int n;
	cin >> n;
	long long x;
	int vis[15];
	int cas = 1,get = 0;
	while (n--)
	{
		scanf("%lld",&x);
		printf("Case #%d: ",cas++);
		memset(vis,0,sizeof(vis));
		if (x == 0){
			printf("INSOMNIA\n");
			continue;
		}
		long long y = x;
		get = 0;
		while (1){
			long long tmp = x;
			int num;
			while (tmp){
				num = tmp % 10;
				tmp /= 10;
				if (vis[num] == 0){
					vis[num] = 1;
					get++;
				}
			}
			if (get == 10){
				printf("%lld\n", x);
				break;
			}
			x += y;
		}
	}
	return 0;
}