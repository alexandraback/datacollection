#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string name("B-large");
	ifstream in;
	ofstream out;
	int nbCases = 0; // size of the sets loaded

	double C, F, X;

	// Variables end -------------------------------------------------------------------------

	in.open((name + ".in").c_str());
	out.open((name + ".out").c_str()); // flux opening
	out.setf( std::ios::fixed, std:: ios::floatfield );
	out.precision(7);

	if(!(in.is_open() && out.is_open()))
	{
		cerr << "> one of the file could not be loaded" << endl;
	}

	in >> nbCases; // getting case number

	for(int i=1;i<=nbCases;i++)
	{
		in >> C >> F >> X;

		double timeTaken = 0;
		double cookiesPerSec = 2, nbCookies = 0;
		double timeTillFactory;
		double timeTillCompletion;
		double newTimeTillCompletion;
		bool cont;

		do
		{
			cont = false;
			timeTillFactory = C / cookiesPerSec;
			timeTillCompletion = X / cookiesPerSec;
			newTimeTillCompletion = X / (cookiesPerSec + F);

			if(timeTillFactory + newTimeTillCompletion < timeTillCompletion)
			{
				timeTaken+= timeTillFactory;
				cookiesPerSec+= F;
				cont = true;
			}
		}while(cont);

		timeTaken+= timeTillCompletion;

		out << "Case #" << i << ": " << timeTaken << endl; // starts at 1
	}

    in.close();
    out.close();
    cout << "Appuyez sur ENTER pour continuer" << endl;
    cin.get();
    return 0;
}
