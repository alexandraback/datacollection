//#include <vector>
//#include <list>
//#include <map>
//#include <set>
//#include <deque>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <sstream>
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <cstring>
//#define INF 1<<30
//#define MAXN 10010
//#define MOD 1000000007
//using namespace std;
//
//int  main()
//{
//	int seed;
//	seed = time(NULL);
//	srand(seed);
//	for(int r = 0;r < 100;r++)
//	{
//		int n ,m;
//		do
//		{
//			n = rand();
//		}while(n >5||n<1);
//		do
//		{
//			m = rand();
//		}while(m > 5|| m < 1);
//		printf("%d %d\n",n ,m);
//		int t;
//		for(int i = 0;i < n;i++)
//		{
//			for(int j = 0;j < m;j++)
//			{
//				do
//				{
//					t = rand();
//				}while(t>10000||t<=0);
//				printf("%d ",t);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define INF 1<<30
#define MAXN 10010
#define MOD 1000000007
using namespace std;

int num[5][5] ,no[5][5];
int flag[20];
double ans ,f ,c ,x ,sum;

int main()
{
	int t;
	double s;
	scanf("%d",&t);
	for(int r = 1;r<=t;r++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		s = 2.0;
		if(x <= c)
		{
			printf("Case #%d: ",r);
			printf("%.7lf\n",x / s);
		}
		else
		{
			double time = 0;
			while(1)
			{
				ans = x / s;
				sum = c / s + x / (s + f);
				if(sum <= ans)
				{
					time += c / s;
					s += f;
				}
				else
				{
					time += ans;
					break;
				}
			}
			printf("Case #%d: ",r);
			printf("%.7lf\n",time);
		}
		
	}
	return 0;
}