#include<cstdio>
#include<algorithm>

using namespace std;

int used[2505];
int ans[55];

void init()
{
	int i;
	for(i=0;i<2503;i++) used[i]=0;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int t, n, cases, i, tmp, index;
	scanf("%d", &t);
	for(cases=1;cases<=t;cases++){
		scanf("%d", &n);
		init();
		index=0;
		for(i=0;i<n*(2*n-1);i++){
			scanf("%d", &tmp);
			used[tmp]++;
		}
		for(i=1;i<=2500;i++){
			if(used[i]%2){
				ans[index]=i;
				index++;
			}
		}
		sort(ans, ans+index);
		printf("Case #%d: ", cases);
		for(i=0;i<index;i++) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}
