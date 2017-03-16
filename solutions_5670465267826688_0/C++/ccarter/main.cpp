#include <iostream>
#include <cstdio>

using namespace std;
int nums[160000];
int tran(char x)
{
	switch (x)
	{
		case '1': return 1;
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
	}
}
int mul(int x,int y)
{
	int sign=1;
	if (x<0)
	{
		sign*=-1;
		x*=-1;
	}

	if (y<0)
	{
		sign*=-1;
		y*=-1;
	}

	if (x==1 || y==1)
		return x*y*sign;
	else if (x==y)
		return -1*sign;
	else if (x==2)
		return sign*(y==3?4:-3);
	else if (x==3)
		return sign*(y==2?-4:2);
	else
		return sign*(y==2?3:-2);

}
int main()
{
    char str[10001];
    int tt,tc;

    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		int l;
		long long x;
		scanf("%d %lld %s",&l,&x,str);
		if (x>=16)
			x=x%4+12;
		for (int i=0;i<l*x;i++)
			nums[i]=tran(str[i%l]);
		int flag=0;
		int m=1;
		int i;
		for (i=0;i<l*x;i++)
		{
			m=mul(m,nums[i]);
			if (m==2)
			{
				flag=1;
				i++;
				break;
			}
		}
		if (flag==1)
			for (m=1;i<l*x;i++)
			{
				m=mul(m,nums[i]);
				if (m==3)
				{
					flag=2;
					i++;
					break;
				}
			}
		if (flag==2)
			for (m=1;i<l*x;i++)
			{
				m=mul(m,nums[i]);
			}
		if (flag==2 && m==4)
			flag=3;
		if (flag==3)
			printf("Case #%d: %s\n",tc,"YES");
		else
			printf("Case #%d: %s\n",tc,"NO");
	}
    return 0;
}
