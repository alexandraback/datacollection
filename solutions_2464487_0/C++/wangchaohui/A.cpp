#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
#define SIZE(x) ((int)(x).size())
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for0r(i,n) for(int i=(n)-1;i>=0;i--)
#define for1r(i,n) for(int i=(n);i>=1;i--)
typedef long long ll;

bool check(ll r,ll t,int n)
{
	ll a=2*r+2*n-1;
	if(t/n<a)return false;
	return true;
}

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
		ll t,r;
		scanf("%I64d %I64d",&r,&t);
		int l=1,h=1000000000;
		while(l<h)
		{
			int m=(l+h+1)/2;
			if(check(r,t,m))
			{
				l=m;
			}
			else
			{
				h=m-1;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
