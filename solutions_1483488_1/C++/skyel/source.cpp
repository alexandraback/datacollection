#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

inline int modify(int nr, int base)
{
	return (nr/10 + (nr%10)*pow(10,base));
}


int count(int nr, int limit)
{
	set<int> occur;
	int temp = nr, len = 0, var, toRet = 0;
	do
	{
		temp /= 10;
		len++;
	}while(temp);
	var = nr;
	for (int i = 0 ; i < len; ++i)
	{
		var = modify(var,len-1);
		if(var > nr && var <= limit && occur.count(var) == 0)
		{
			toRet ++;
			occur.insert(var);
		}
	}
	return toRet;
}

int main()
{
	int t,n,a,b,toOut,var;
	freopen("input","r",stdin);
	scanf("%d\n",&t);
	for(int x = 1; x <= t; ++x)
	{
		scanf("%d %d\n",&a,&b);
		toOut = 0;
		for(int i = a; i < b; ++i)
		{
			var = count(i,b);
			toOut += var;
		}
		printf("Case #%d: %d\n",x,toOut);
	}

}
