#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
	unsigned int a, b, k, casos, cont, i, j, c, inst = 1;
	
	cin >> casos;
	while(casos--)
	{
		cin >> a >> b >> k;
		
		cont  = 0;
		for(i=0; i<a; i++)
		{
			for(j=0; j<b; j++)
			{
				c = i & j;
				if( c < k)
					cont++;
			}
		}
		
		cout << "Case #" << inst++ << ": " << cont << endl;
	}
	
	return 0;
}
