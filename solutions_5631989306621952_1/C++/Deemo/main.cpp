#include<stdio.h>
#include<string.h>
#include<math.h>
#include<list>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int T;
	char input[10000];
	deque<char> S;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%s",input);
		int len = strlen(input);
		S.push_front(input[0]);
		char pivot = input[0];
		for(int i=1;i<len;i++)
		{
			if(input[i]<pivot)
				S.push_back(input[i]);
			if(input[i]>=pivot)
			{
				S.push_front(input[i]);
				pivot = input[i];
			}
		}
		printf("Case #%d: ",i+1);
		while(!S.empty())
		{
			printf("%c",S.front());
			S.pop_front();
		}
		printf("\n");
	}
	return 0;
}