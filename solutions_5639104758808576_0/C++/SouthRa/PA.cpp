#include<cstdio>
#include<cstring>

using namespace std;

int shy[10];

int main()
{
	freopen("C:\\A-small-attempt0.in", "r", stdin);
	freopen("C:\\A-small-attempt0.txt", "w", stdout);
	int t, i, j, smax, ans, stand;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		ans=0;
		scanf("%d",&smax);
		getchar();
		//getchar();
		for(j=0;j<=smax;j++){
			shy[j]=(getchar()-'0');
		}
		stand=shy[0];
		for(j=1;j<=smax;j++){
			if(stand<j){
				ans+=(j-stand);
				stand=j;
			}
			stand+=shy[j];
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
