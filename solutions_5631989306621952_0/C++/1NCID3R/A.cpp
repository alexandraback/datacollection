#include <bits/stdc++.h>
using namespace std;

char buffer[1005];
int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		scanf("%s",buffer);
		deque<char> dq;
		dq.push_back(buffer[0]);
		for(int i=1; buffer[i]; i++)
		{
			if(buffer[i]>=dq.front())
				dq.push_front(buffer[i]);
			else
				dq.push_back(buffer[i]);
		}

		printf("Case #%d: ",cn);

		for(int i=0; i<dq.size(); i++)
			printf("%c",dq[i]);
		puts("");
	}
}