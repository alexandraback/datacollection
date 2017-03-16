#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef __int64 Uint;
const int MAX=500005;
const int N=100005;
int w[N];
int main()
{
	int T,cse=0;
	int e,r,n;
	Uint sum;
	Uint res;
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&e,&r,&n);
		sum=0;
		for(int i=0;i<n;sum+=w[i],i++)
			scanf("%d",&w[i]);
		sort(w,w+n);
		res=(sum-w[n-1])*r+e*w[n-1];
		printf("Case #%d: ",++cse);
		printf("%I64d\n",res);
	}
	return 0;
}
/*


Output 

3
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5
Case #1: 12
Case #2: 12
Case #3: 39

*/