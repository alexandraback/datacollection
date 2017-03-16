#include <fstream>
//This standard library handles files
#include <sstream>
//This standard library handles stringstreams, useful generalisations of strings
#include <iostream>
//Standard library for talking to the user
using namespace std;

double runcookie(double C, double F, double X)
{
	double timebefore, timeafter, inc = 2.0, time = 0;
	//timebefore stores how long it would take to get X cookies before buying a farm
	//timeafter stores how long it would take to get X cookies after having bought that farm
	//inc stores how many cookies per second one gets
	//time is a running tally of how much time has passed
	while (true)
	{
		timebefore = time + X / inc;
		time += C / inc;
		inc += F;
		timeafter = time + X / inc;
		if (timebefore < timeafter)
			return timebefore;
	}
}

int main()
{
	fstream filein, fileout;
	int T, i;
	double C, F, X, seconds;
	string s;
	cout << "Please type name of input file: ";
	cin >> s;
	filein.open(s.c_str(), fstream::in);
	cout << "Please type name of output file: ";
	cin >> s;
	fileout.open(s.c_str(), fstream::out);
	fileout.precision(7);
	filein >> T;									//gets number of cases
	for (i = 0; i < T; i++)
	{
		//loops for each case
		fileout << "Case #" << (i + 1) << ": ";		//starts building output file
		filein >> C;								//gets values of each case
		filein >> F;
		filein >> X;
		seconds = runcookie(C, F, X);				//figures out the minimum number of seconds
		fileout << fixed << seconds << endl;
	}
	filein.close();
	fileout.close();
	return 0;
}
