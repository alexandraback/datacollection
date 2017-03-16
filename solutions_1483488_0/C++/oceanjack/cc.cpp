#include<stdio.h>
#include<algorithm>
using namespace std;
int num[2000005];
inline int fuck(int l, int r) 
{
	int shit[8], pow[8] = {1}, val = 0;
	for(int i = 1; i < 10; pow[i] = pow[i - 1] * 10, ++i);
	for(int i = l; i <= r; ++i)
	{
		int len = -1, newnum = i, id = 0;
		for(int j = i; j; shit[++len] = j%10, j /= 10);
		for(int j = 0; j<=len ; ++j)
		{
			newnum = newnum/10 + pow[len]*shit[j];
			if(i < newnum && newnum <= r)
				num[id++] = newnum;
		}
		if(id)
		{
			sort(num, num+id);
			val += unique(num, num+id) - num;
		}
	}
	return val;
}
int main() 
{
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int c, sc = 0;
	for (scanf("%d",&c); c; --c) 
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("Case #%d: %d\n",++sc,fuck(l, r));
	}
	return 0;
}

