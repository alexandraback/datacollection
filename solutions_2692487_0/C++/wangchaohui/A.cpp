#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
using namespace std;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
#define SIZE(x) ((int)(x).size())
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for0r(i,n) for(int i=(n)-1;i>=0;i--)
#define for1r(i,n) for(int i=(n);i>=1;i--)
typedef long long ll;



int main()
{
	//freopen("in.txt","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	int T,TC=0;
	scanf("%d",&T);
	while (++TC<=T)
	{
		printf("Case #%d: ",TC);
		priority_queue<int,vector<int>, greater<int> > Q;
		int A,n;
		scanf("%d %d",&A,&n);
		int ans=200000;
		while(n--)
		{
			int t;
			scanf("%d",&t);
			Q.push(t);
		}
		if(A==1)
		{
			printf("%d\n",SIZE(Q));
			continue;
		}
		int c=0;
		while(!Q.empty())
		{
			checkmin(ans,c+SIZE(Q));
			while(!Q.empty() && A<=Q.top())
			{
				A=2*A-1;
				c++;
			}
			if(!Q.empty())
			{
				A+=Q.top();
				Q.pop();
			}
		}
		checkmin(ans,c);
		printf("%d\n",ans);
	}
	return 0;
}
