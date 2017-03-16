#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	std::ifstream file("A-small-attempt1 (1).in", std::ifstream::in);
	std::ofstream file2("out.txt", std::ofstream::out);

	int nb;
	file >> nb;

	for(int i = 0; i < nb; ++i)
	{
		int nb_participants;

		file >> nb_participants;

		vector<int> notes(nb_participants);
		int x = 0;
		for(int j =0; j< nb_participants; ++j)
		{
			file >> notes[j];
			x += notes[j];
		}
		vector<double>res(nb_participants);
		int total = 2*x;
		double objectif = (double)(total) / (double)nb_participants;
		int cpt = 0;
		vector<bool> done(nb_participants,false);

		for(int j =0; j< nb_participants; ++j)
		{
			if(notes[j] < objectif)
				cpt++;
			else 
			{
				total -= notes[j];
				done[j] = true;
			}
		}

		objectif = (double)total / (double)cpt;

		for(int j = 0; j <  nb_participants; ++j)
		{
			if(done[j] == true)
				res[j] = 0;

			else
			{
			   res[j] = (objectif - notes[j]) / x;
			}
		}

		file2 << "Case #" << i + 1 << ": " << fixed << setprecision(5);
		for(int j = 0; j <  nb_participants; ++j)
		{
			file2 << res[j]*100 << " ";
		}
			
		file2 << endl;
	}


}