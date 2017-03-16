#include <bits/stdc++.h>
using namespace std;

char buffer[1000];

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		scanf("%s",buffer);

		int cnt = 0;
		char ch = buffer[0];
		for(int i=1; buffer[i]; i++)
		{
			if(ch!=buffer[i])
			{
				cnt++;
				ch = buffer[i];
			}
		}

		if(ch=='-')
			cnt++;

		printf("Case #%d: %d\n",cn,cnt);
	}
}