#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, i, j, k, n, c, d, x, y;
	
	cin >> t;
	for (k=0; k<t; k++) {
		cin >> x >> y;
		cout << "Case #" << k+1 << ": " ;

		if (x > 0) 
			for (i=0; i<x; i++)	
				cout << "WE";
		if (x < 0) 
			for (i=0; i<(-1*x); i++)	
				cout << "EW";
		if (y > 0) 
			for (i=0; i<y; i++)	
				cout << "SN";
		if (y < 0) 
			for (i=0; i<(-1*y); i++)	
				cout << "NS";
		
		
		cout << endl;
	}	
	return 0;
}
