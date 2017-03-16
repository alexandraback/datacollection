#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("password.in");
	ofstream out("password.out");
	int T;
	in >> T;
	for (int C = 0; C < T; C++)
	{
		int typed, passLen;
		double prob[100020], cume[100020];
		in >> typed >> passLen;
		for (int i = 0; i < typed; i++)
		{
			double a;
			in >> a;
			prob[i] = a;
			if (i > 0)
				cume[i] = a * cume[i - 1];
			else
				cume[i] = a;
		}
		//calculate for just type
		double ifType = cume[typed - 1] * (passLen - typed + 1) + (1 - cume[typed - 1]) * (passLen - typed + 1 + passLen + 1);
		//if press enter
		double ifEnter = passLen + 2;
		double smallest = min(ifType, ifEnter);
		for (int i = 1; i < typed; i++)
		{
			//lets say you press backspace i times
			//you need to get the first typed - i chars right
			//you have i + i + (passLen - typed) + 1 keystrokes
			//else you have that + passLen + 1 keystrokes
			double ifBack = cume[typed - i - 1] * (i + i + passLen - typed + 1) + (1 - cume[typed - i - 1]) * (i + i + passLen - typed + 1 + passLen + 1);
			smallest = min(smallest, ifBack);
		}
		out.precision(6);
		out << fixed << "Case #" << C + 1 << ": " << smallest << "\n";
	}
}
