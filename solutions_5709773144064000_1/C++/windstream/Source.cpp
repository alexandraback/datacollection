#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream in ("B-large.in");
	ofstream out ("OUT.txt");

	int CASES; 
	in >> CASES;

	for (int i = 1; i <= CASES; i++)
	{
		double Cost, Increase, Win; 
		double ElaspedTime = 0.0;
		in >> Cost;
		in >> Increase;
		in >> Win;
		double RATE = 2.0;
		
		if (Win < Cost)
		{
			ElaspedTime = Win/RATE;
			out << "Case #" << i << ": " << setprecision(7) << fixed << ElaspedTime << endl;
			continue;
		}
		ElaspedTime = Cost/RATE;		
		
		while(1)
		{
		// CASE1
		double C1 = (Win-Cost)/RATE;
		double C2 = Win/(RATE+Increase);

		if (C1 <= C2)
		{
			ElaspedTime += C1;
			out << "Case #" << i << ": " << setprecision(7) << fixed << ElaspedTime << endl;
			break;
		}
		else 
		{
			RATE += Increase;
			ElaspedTime += Cost/RATE;
		}
		}
		
		
	}
	out.close();
	return 0;
}