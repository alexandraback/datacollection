#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("b11.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	char a[5001];
	
	for(int z=1;z<=t;z++)
	{
	    int k=0;
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>0)
		{
			while(x--)
			{
				a[k++] = 'W';
				a[k++] = 'E';
			}
		}
		else if(x<0)
		{
			while(x++)
			{
				a[k++] = 'E';
				a[k++] = 'W';
			}
		}
		if(y>0)
		{
			while(y--)
			{
				a[k++] = 'S';
				a[k++] = 'N';
			}
		}
		else if(y<0)
		{
			while(y++)
			{
				a[k++] = 'N';
				a[k++] = 'S';
			}
		}
        a[k] = '\0';
        printf("Case #%d: %s\n",z,a);
	}
	return 0;
}