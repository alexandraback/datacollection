#include <iostream>
using std::cin;

int pows[8] = {1,10,100,1000,10000,100000,1000000,10000000};
int tt[10];
inline int breaknumber (int a , int b)
{
	int len = 0;
	int bits[20];
	int res = 0;
	int t = a;
	while(t)
	{
		bits[len++] = t%10;
		t /= 10;
	}
	int ttl = 0;
	for (int i = 0 ; i < len ; i++)
	{
		int sum = 0;
		int j = 0;
		bool flag = true;
		
		while(j < len)
		{
			sum = sum*10 + bits[(len - i - j -1 + len)%len];
			//剪枝1
			if(sum*pows[len-j-1] > b)
			{
				flag = false;
				break;
			}
			j++;
		}
		if(flag)
		{
			if(sum <= b && sum > a)  //符合条件,如果存在
			{
				bool f2 = true;
				for (int k = 0 ; k < ttl ; k++)
				{
					if(sum == tt[k])
					{
						f2 = false;
						break;
					}
				}
				if(f2)
					res++ , tt[ttl++] = sum;
			}
		}
	}
	return res;
}
int getp(int a, int b)
{
	int sum = 0;
	for (int i = a ; i < b ; i++)
		sum += breaknumber(i,b);
	return sum;
}
int main()
{
	int t,a,b;
	cin >> t;
	for (int i = 1 ; i <= t ; i++)
	{
		cin >> a >> b;
		printf("Case #%d: %d\n",i,getp(a,b));
	}
}