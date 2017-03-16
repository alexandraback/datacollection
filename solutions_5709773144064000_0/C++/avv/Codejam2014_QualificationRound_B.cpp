#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include <iomanip>
#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F_S(vec, index, start) for (int index = start; index  < vec.size(); ++index)



int main(int argc, char* argv[])
{

	ofstream cout ("output.txt");
	ifstream cin("input.txt");

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		double C, F, X;		
		cin >> C >> F >> X;

		double currV = 2;
		double currX = X;	
		double sumV = 0;
		double c = 0;
		double time = 0;

		double timeC = 0;
		double timeV= 1;
		while (true)
		{
			if (currX - C < 0)
			{
				break;
			}
			sumV += currV;
			time += C / currV;
			//timeC = timeC * currV + C * timeV;
			//timeV = currV * timeV;
			c++;
			currX -= C;
			if (currX * (currV + F) > (currX + C) * currV)
			{
				currV += F;
				currX += C;
				continue;
			}
			
			//time += (c * C) / (sumV / c);
			break;
		}

		time += timeC / timeV + currX / currV;
		cout << "Case #" << t + 1 << ": " << std::fixed << std::setprecision(7)<< time << endl;
		
		

	}
	return 0;
}
