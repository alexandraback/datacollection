#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;

int data[107];

inline void Init()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
}

inline bool func(__int64 num)
{
	int i = 0,j;
	while(num > 0)
	{
		data[i++] = num%10;
		num /= 10;
	}
	int len = i;
	for(i=0,j=len-1;i<j;i++,j--)
	{
		if(data[i]!=data[j])
			return false;
	}
	return true;
}


int main(void)
{
	Init();
	int A,B,T,cases;
	scanf("%d",&cases);
	for(T=1;T<=cases;T++)
	{
		scanf("%d %d",&A,&B);
		printf("Case #%d: ",T);
		
		__int64 k = sqrt(1.0*A);
		while(k*k<A)
		{
			k++;
		}
		__int64 count = 0;
		for( ;k*k<=B; k++)
		{
			if(func(k)==true && func(k*k)==true)
				count++;
		}
		printf("%I64d\n",count);
	}

	return 0;
}