#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105

using namespace std;

char str[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%s",&str);
		int cnt=0,bef=-1;
		int n=strlen(str);
		for(int i=0;i<n;i++)
		{
			int v=str[i]=='+'?1:-1;
			if(i==0||bef!=v) cnt++;
			bef=v;
		}
		if(bef==1) cnt--;
		printf("%d\n",cnt);
	}
	return 0;
}
