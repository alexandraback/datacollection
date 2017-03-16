#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int TEST_CASES;
/*
int main()
{
    cin >> TEST_CASES;
    for (int c = 0; c < TEST_CASES; c++)
    {
		long long int i=1;
		long long int r,t, somma = 0;
		cin >> r >> t;
		if (r < 1000000)
		{
			i = (2*r - 1 + sqrt((2*r-1)*(2*r-1)+8*t))/4;
			cout << "Case #" << c+1 << ": "<< i << endl ;
		}
		else
		{
			while (somma <= t)
			{
				somma += 2*r + 4*i - 3;
				i++;
			}
			cout << "Case #" << c+1 << ": "<< i-2 << endl ;
		}
    }
    return 0;
}*/

int main()
{
    cin >> TEST_CASES;
    for (int c = 0; c < TEST_CASES; c++)
    {
		long long int i=1,ris;
		long long int r,t, somma = 0;
		cin >> r >> t;
		long long int intervallo = 1;
		while (intervallo > 0)
		{
			ris = 2*i*i + (2*r-1)*i;
			//cout << i << " - " << intervallo << " - " << ris << endl;
			if (ris < t)
			{
				intervallo*=2;
				i += intervallo;
				
			}
			if (ris > t)
			{
				intervallo/=2;
				if (intervallo > 0)
					i -= intervallo;
				
			}
			if (ris == t)
			{
				i= i+1;
				break;
			}
		}
		cout << "Case #" << c+1 << ": "<< i-1 << endl ;
		
    }
    return 0;
}
