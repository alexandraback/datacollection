#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define WRITE

void output()
{
	static int cc = 1;
	printf("Case #%d: ", cc++);
}
int two[1000];
void gao()
{
	two[0] = 1;
	for(int i = 1; i < 1000; i ++)
		two[i] = two[i - 1] * 2;
}
int main() 
{
	#ifdef WRITE
	freopen("A--small-attempt1.in","r",stdin);
	freopen("result","w",stdout);
	#endif
	int _;
	cin>>_;
	int a,b;
	gao();
	while(_--)
	{
		scanf("%d/%d",&a,&b);
		int temp = __gcd(a,b);
		if(temp != 0)
		{
			a /= temp;
			b /= temp;
		}
		temp = b;
		bool flag = true;
		while(temp != 1)
		{
			if (temp % 2 != 0)
			{
				flag = false;
				break;
			}	
			temp >>= 1;
		}
		int cnt = 0;
		int idx = -1;
		for (int i = 0; i < 100; i ++)
		{
			if(two[i] == a)
			{
				idx = i;
				break;	
			}
			if(two[i] > a)
			{
				idx = i - 1;
				break;
			}
		}
		b /= two[idx];
		while(b != 1)
		{
			if (b % 2 != 0)
			{
				flag = false;
				break;
			}	
			cnt ++;
			b >>= 1;
		}
		output();
		if(!flag)puts("impossible");
		else cout<<cnt<<endl;
	}
}