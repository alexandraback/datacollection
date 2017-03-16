#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
	unsigned long long int a, b, k, casos, cont, i, j, c, inst = 1, aux;
	
	cin >> casos;
	while(casos--)
	{
		cin >> a >> b >> k;
		cont  = 0;
		
		if(a>b)
		{
			aux = b;
			b = a;
			a = aux;
		}
		
		if(k > b)
			cont = b*a;
		else
		{
			
			cont = k*a;
			
			 
		
			for(i=k; i<b; i++)
			{
				if(k>=a)
					cont += a;
				else
					cont += k;
				for(j=k; j<a; j++)
				{
					c = i & j;
					if( c < k)
						cont++;
				}
			}
		}
		
		cout << "Case #" << inst++ << ": " << cont << endl;
	}
	
	return 0;
}
