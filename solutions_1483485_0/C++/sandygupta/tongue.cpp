#include<stdio.h>
#include<iostream>

using namespace std;

char a[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'} ;


int main()
{
	int t ;
	int l ; 
	int i ; 
	int total = 1;
	string str ; 
	scanf("%d",&t);
	getchar();

	while(t--)
	{
		getline(cin , str);
		l = str.length();
		for(i = 0 ; i < l ; i++)
		{
			if(str[i] != ' ')
			{
				str[i] = a[str[i] - 97] ; 
			}
		}
		cout << "Case #" << total << ":" << " " << str << endl ; 
		total ++ ; 
		 
	}
	return 0;
}
