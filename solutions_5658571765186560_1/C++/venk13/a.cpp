#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

int main()
{
	freopen("D-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		if(r*c%x!=0||x>2*min(r,c)||x>max(r,c))
		{
			printf("RICHARD\n");
			continue;
		}
		if(min(r,c)==1||x<=2)
		{
			printf("GABRIEL\n");
			continue;
		}
		if(x>=7)
		{
			printf("RICHARD\n");
			continue;
		}
		if(r>=6&&c>=6)
		{
			printf("GABRIEL\n");
			continue;
		}
		if(min(r,c)+min(r,c)-1>x)
		{
			printf("GABRIEL\n");
			continue;
		}
		int rem=x-(min(r,c)+min(r,c)-1);
		if(min(r,c)==2)
		{
			if(rem>=2)
			{
				printf("RICHARD\n");
				continue;
			}
			if(rem==0)
			{
				bool gabri=false;
				for(int left=0;left<=max(r,c)-2;++left)
					if(r*c-left*2-3>0&&left*2%3==0&&(r*c-left*2-3)%3==0)
						gabri=true;
				printf("%s\n",(gabri?"GABRIEL":"RICHARD"));
				continue;
			}
			if(max(r,c)>2)
			{
				printf("RICHARD\n");
				continue;
			}
			printf("GABRIEL\n");
			continue;
		}
		//min(r,c)==3
		bool gabri=false;
		for(int left=0;left<=max(r,c)-3;++left)
			if(r*c-left*3-2-5>0&&(left*3+2-rem)%5==0&&(r*c-left*3-2-5)%5==0)
				gabri=true;
		printf("%s\n",(gabri?"GABRIEL":"RICHARD"));
	}
    return 0;
}