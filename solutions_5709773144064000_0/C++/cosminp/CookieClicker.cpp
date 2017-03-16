#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


double solve(double C, double F, double X)
{
	double 	R 			= 2.0;
	double 	farmTime 	= 0.0;
	double 	bestTime 	= X / R;
	double  totalTime 	= X/R;
	bool 	canImprove 	= true;

	while (canImprove)
	{
		farmTime 	+= C/R;
		R			+= F;
		totalTime 	 = farmTime + X/R;

		canImprove = false;
		if (totalTime <= bestTime)
		{
			bestTime = totalTime;
			canImprove = true;
		}
	}

	return bestTime;
}


int main()
{
	fstream		f, g;
	int			T;
	double 		C, F, X;

	f.open("in.txt", ios::in);
	g.open("out.txt", ios:: out);

	f >> T;

	for (int test = 1; test <= T; test++)
	{
		f >> C >> F >> X;
		g << fixed << setprecision(7) << "Case #" << test << ": " << solve(C, F, X) << endl;
	}

	f.close();
	g.close();

	return 0;
}
