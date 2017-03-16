#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
// const int FS_CNT=6;	// 5+1
// /*
const int FS_CNT=40;	// 39+1
// */
LL fs[FS_CNT]={
1,
4,
9,
121,
484,
// 1e3+1
// /*
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
1e14+1
// */
};
int main()
{
	int T;
	LL A,B;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int head,tail;
		scanf("%lld %lld",&A,&B);
		for(int j=0;j<FS_CNT;j++)
			if(A<=fs[j])
			{
				head=j;
				break;
			}
		for(int j=0;j<FS_CNT;j++)
			if(B<fs[j])
			{
				tail=j;
				break;
			}
		printf("Case #%d: %d\n",i+1,tail-head);
	}
	return 0;
}
