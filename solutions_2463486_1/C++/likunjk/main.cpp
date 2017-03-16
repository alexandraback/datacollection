#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;

int data[107];

vector<int> v;

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

	__int64 A,B,T;
	int cases;

	for(T=1;T<=10000000;T++)
	{
		if(func(T)==true && func(T*T)==true)
		{
			v.push_back(T);
		}
	}

	scanf("%d",&cases);
	
	for(T=1;T<=cases;T++)
	{
		scanf("%I64d %I64d",&A,&B);

		printf("Case #%I64d: ",T);
		
		__int64 k1 = sqrt(1.0*A);
		while(k1*k1<A)
		{
			k1++;
		}
		__int64 k2 = sqrt(1.0*B);

		int count = 0;

		int i;
		for(i=0;i<v.size();i++)
		{
			if(v[i]>=k1 && v[i]<=k2)
				count++;
		}

		printf("%d\n",count);
	}

	return 0;
}