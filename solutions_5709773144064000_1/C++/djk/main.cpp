#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	unsigned int count = 0;
	cin >> count;
	
	for (unsigned int i = 0; i < count; ++i)
	{
		double
			c = 0.0,
			f = 0.0,
			x = 0.0;
		
		cin >> c >> f >> x;
		
		double
			cps = 2.0,
			delay = 0.0,
			time = x / 2.0;
		
		while (true)
		{
			double newtime = x / cps + delay;
			
			if (newtime > time)
				break;
			
			delay += c / cps;
			cps += f;
			time = newtime;
		}
		
		cout << "Case #" << (i + 1) << ": " << fixed << setprecision(7) << time << endl;
	}

	return 0;
}
