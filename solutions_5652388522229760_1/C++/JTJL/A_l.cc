#include<bits/stdc++.h>
using namespace std;

int cnt[100];

int main(){
	freopen("Al.in", "r", stdin);
	freopen("Al.out", "w", stdout);
	int T, n, m;
	cin>>T;
	for(int o = 1; o <= T; o++){
		printf("Case #%d: ", o);
		scanf("%d", &n);
		if (n == 0)
			puts("INSOMNIA");
		else{
			int tot = 10; m = 0;
			for(int i = 0; i < 10; i++)
				cnt[i] = 0;
			while(tot){
				for(int i = m += n; i; i /= 10)
					tot -= !(cnt[i % 10]++);
			}
			printf("%d\n", m);
		}
	}
	return 0;
} 
