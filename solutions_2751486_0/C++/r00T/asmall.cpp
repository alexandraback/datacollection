#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
using namespace std;

typedef long long int L;
typedef unsigned long long int U;


main()
{
	int tc;
	cin>>tc;
	for(int t = 1;t<=tc;t++)
	{
		int k = 1,c=0;
		string str;
		int n;
		cin>>str>>n;
		int l = str.length();
		
		for(int i = 0;i<l;i++)
		{
			for(int j = 1;j<=(l-i);j++)
			{
					string str1 = str.substr(i,j);
					int m = 0,x=0;
					for(int k = 0;k<str1.length();k++)
					{
						if(str1[k] != 'a' && str1[k] != 'e' && str1[k] != 'i' && str1[k] != 'o' && str1[k] != 'u')
							x++;
						else
							x = 0;
						m = max(m,x);
						if(m >= n)
							break;
					}
					if(m >= n)
					{
						//cout<<str1<<endl;
						c++;					
					}
				
			}
		}
		printf("Case #%d: %d\n", t,c);
	}
}
