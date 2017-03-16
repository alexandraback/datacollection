#include <stdio.h>

// 返回true表示先手必胜
bool slove(unsigned int x,unsigned int r,unsigned int c)
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