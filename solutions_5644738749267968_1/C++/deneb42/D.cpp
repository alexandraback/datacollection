#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void readMasses(ifstream &in, list<double> &listGreater, list<double> &listLower, int N)
{
	list<double>::iterator it;
	double tmp;

	for(int j=0; j<N; ++j)
	{
		in >> tmp;

		it = listGreater.begin();
		while(it != listGreater.end() && *it > tmp)
			it++;
		listGreater.insert(it, tmp);

		it = listLower.begin();
		while(it != listLower.end() && *it < tmp)
			it++;
		listLower.insert(it, tmp);
	}
}

int main()
{
	string name("D-large.in");
	ifstream in;
	ofstream out;
	int nbCases = 0; // size of the sets loaded

	int N;
	list<double> massNG, massNL, massKG, massKL;

	// Variables end -------------------------------------------------------------------------

	in.open(name.c_str());
	out.open(name.replace(name.rfind('.') + 1, string::npos, "out").c_str()); // flux opening

	if(!(in.is_open() && out.is_open()))
	{
		cerr << "> one of the file could not be loaded" << endl;
	}

	in >> nbCases; // getting case number

	for(int i=1;i<=nbCases;i++)
	{
		int nbPtsDW = 0, nbPtsW = 0;

		in >> N;
		massNG.clear();
		massNL.clear();
		massKG.clear();
		massKL.clear();

		readMasses(in, massNG, massNL, N);
		readMasses(in, massKG, massKL, N);

		/*cout << "reinit ok" << endl;
		for(list<double>::const_iterator it = massN.begin(); it != massN.end(); it++)
			cout << *it << " ";
		cout << endl;*/

		while(massNG.size() > 0) // iterator that can be used for all the lists
		{
			list<double>::iterator it = massKL.end();
			double tmp = massNG.front();

			massNG.pop_front();
			it--;

			// strat : putting my biggest in order to burn down his lowest.

			if(*it < tmp) // there is no mass bigger than Naomi's
			{
				massKL.pop_front();
				nbPtsW++;
			}
			else // removing ken's mass that is bigger
			{
				for(it = massKL.begin(); it != massKL.end(); it++)
				{
					if(*it > tmp) // we have the first superior mass
					{
						massKL.erase(it);
						break;
					}
				}
			}

			it = massNL.end(); // highest
			tmp = massKG.back(); // ken's lowest

			massKG.pop_back();
			it--;

			//strat : putting the lowest number > his lowest if possible, else, putting my lowest and loosing.

			if(*it < tmp) // there is no mass bigger than ken's
			{
				massNL.pop_front();
				// can no more make points
			}
			else
			{
				nbPtsDW++;
				for(it = massNL.begin(); it != massNL.end(); it++)
				{
					if(*it > tmp) // we have the first superior mass
					{
						massNL.erase(it);
						break;
					}
				}
			}

		}

		out << "Case #" << i << ": " << nbPtsDW  << " " << nbPtsW << endl; // starts at 1
	}

    in.close();
    out.close();
    cout << "Appuyez sur ENTER pour continuer" << endl;
    cin.get();
    return 0;
}
