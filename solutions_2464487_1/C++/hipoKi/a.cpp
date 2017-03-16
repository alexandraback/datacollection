#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("a-l.in","r",stdin);
	freopen("a-l.out","w",stdout);
	
	int t;
	cin >> t;
	
	for(int s = 0; s < t; s++)
	{
	
		long long int r, t;
		cin >> r >> t;
		long double dr = r;
		long double dt = t;
		long double a = 2;
		long double b = 2 * dr - 1;
		long double c = dt * -1;
		long double rad = sqrt(pow(b, 2) - 4 * a * c);
		long double res = (-1 * b + rad)/ (2 * a);
		/*while(true)
		{
			i++;
			int res = 2 * i * i + (2 * r - 1) * i;
			cout << i << ": " << res << endl;
			if(res > t)
				break;
		}*/
		
		long double paint = 2 * pow(res, 2) + (2 * r - 1) * res;
		long double diff = (paint - dt);
		if(diff < 0)
			diff *= -1;
		long double tolerancia = 1.0e-10;
		
		if(paint > dt && tolerancia < diff)
			res = res - 1;
		if(res < 0)
			res = 0;
	
		cout << "Case #" << s+1 << ": " << (int)floor(res) << endl;
	}
	
	return 0;
	
}
