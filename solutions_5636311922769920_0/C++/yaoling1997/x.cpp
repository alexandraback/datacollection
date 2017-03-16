#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int T,K,C,S,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d%d%d",&K, &C, &S);
		for (i= 1;i<=K;i++)
			printf("%d%c",i,i<K?' ':'\n');
	}return 0;
}
