#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int t,l,p,count;
	char s[101],temp[101];
	int itr,i;

	cin>>t;
	for(itr=1;itr<=t;itr++)
	{
		cin>>s;
		strcpy(temp,s);
		l = strlen(s);
		p=l-1;
		count=0;
		while(p>=0)
		{
			while( p>=0 && s[p]=='+' )
				p--;
			if(p>=0 && s[p]=='-')
			{
				if(s[0]=='+')
				{
					for(i=0;s[i]=='+';i++)
						s[i]='-';
					count++;
				}
				for(i=0;i<=p;i++)
				{
					if(s[i]=='+')
						temp[p-i]='-';
					else
						temp[p-i]='+';
				}
				strcpy(s,temp);
				count++;
			}
		}
		printf("Case #%d: %d\n",itr,count);
	}

	return 0;
}