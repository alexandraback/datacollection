#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T,z = 1;
	scanf("%d",&T);
	getchar();
	while(T--)
	{	
		char c;
		deque<char> D;
		c = getchar();
		D.push_back(c);int i = 1;
		while((c = getchar()) != '\n')
		{
			if((int)c >= (int)D.front())
				D.push_front(c);
			else
				D.push_back(c);
		}

		int len = D.size();
		printf("Case #%d: ",z);
		for(int i = 0; i < len; ++i)
		{
			printf("%c",D.front());
			D.pop_front();
		}
		printf("\n");
		z++;
	}

	return 0;
}