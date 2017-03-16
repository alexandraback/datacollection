#include <stdio.h>
#include <assert.h>

// 返回true表示先手必胜
bool slove_small(unsigned int x,unsigned int r,unsigned int c)
{
	unsigned int count = r*c;
	if(1 == x) return false;
	if(2 == x) return (0 != (count&1));
	if(3 == x)
	{
		if(1 == r || 1 == c) return true;			// 折
		if(0 != (count%3)) return true;
		return false;								// 至少有一边是3,另外一个大于等于2时,两个折可以构成2*3,剩下的用条形
	}
	if(4 == x)
	{
		if(1 == r || 1 == c) return true;			// 方形
		if(r < 4 && c < 4) return true;				// 长条
		if(0 != (count%4)) return true;
		// 至少有一个为4
		if(2 == r || 2 == c) return true;			// 凸形
		return false;
	}
	return true;
}

// 返回true表示先手必胜
bool slove(unsigned int x,unsigned int r,unsigned int c)
{
	unsigned int count = r*c;
	if(0 != (count%x)) return true;					// 任意一个
	if(r < x && c < x) return true;					// 1*x
	if(r < (x+1)/2 || c < (x+1)/2) return true;		// 一竖一横

	if(1 == x) return false;
	if(2 == x) return (0 != (count&1));
	if(x >= 7) return true;							// 中间有洞

	if(3 == x) return false;						// 至少有一边是3,另外一个大于等于2时,两个折可以构成2*3,剩下的用条形
	if(4 == x)
	{
		// 至少有一个为4
		if(2 == r || 2 == c) return true;			// 凸形
		return false;
	}
	if(5 == x)
	{
		return false;
	}
	if(6 == x)
	{
		if(3 == r || 3 == c) return true;
		return false;
	}

	return false;
}
int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int x = 0,r = 0,c = 0;scanf("%d%d%d",&x,&r,&c);
		bool ans = slove(x,r,c);
		printf("Case #%u: %s\n",iCases,ans?"RICHARD":"GABRIEL");
	}
	return 0;
}