// Google Code Jam 2012 
// Problem B 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <list> 
using namespace std; 

int main(int argc, char *argv[]) 
{ 
	if (argc < 3) 
	{ 
		cout << "[Usage] ProblemB input_file output_file" << endl; 
		return -1; 
	} 

	// Initialize problem variables 
	int numcases = 0; 
	list<int> scorelist; 

	// Open the input and outputfile  
	ifstream inputfile; 
	ofstream outfile; 
	string line; 
	inputfile.open(argv[1]); 
	outfile.open(argv[2]); 

	// Get the number of cases 
	inputfile >> numcases; 
	getline(inputfile, line); 

	// Read through the input 
	int count = 0; 
	while (inputfile.good()) 
	{ 
		count++; 

		// Get the number of levels 
		int numlevels = 0; 
		inputfile >> numlevels; 
		getline(inputfile, line); 
		
		// Get the number of stars required to complete each level 
		int *numstars1 = new int[numlevels]; 
		int *numstars2 = new int[numlevels]; 
		for (int k = 0; k < numlevels; k++) 
		{ 
			inputfile >> numstars1[k]; 
			inputfile >> numstars2[k]; 
			getline(inputfile, line); 
		} 
		if (!inputfile.good()) break; 

		// First compute the number of levels available with a given number of stars 
		// for both completing with one star and with two stars 
		int numlvls1[2002] = {0}; 
		int numlvls2[2002] = {0}; 
		list<int> lvls1[2002]; 
		list<int> lvls2[2002]; 
		for (int k = 0; k < numlevels; k++) 
		{ 
			int idx = numstars1[k]; 
			if ((idx < 0) || (idx >= 2002)) cout << "ERROR!" << endl; 
			numlvls1[idx]++; 
			lvls1[idx].push_back(k); 

			idx = numstars2[k]; 
			if ((idx < 0) || (idx >= 2002)) cout << "ERROR!" << endl; 
			numlvls2[idx]++; 
			lvls2[idx].push_back(k); 
		} 

		// Create a map that indicate whether we have earned one star, two stars 
		// or no stars from the level yet 
		int *starsearned = new int[numlevels]; 
		for (int k = 0; k < numlevels; k++) 
		{ 
			starsearned[k] = 0; 
		} 

		// Try to find the minimum number of games that need to be played 
		int mingames = 0; 
		int numstars = 0; 
		int numlevelsleft = numlevels; 
		bool solved = false; 
		bool finish = false; 
		while ((!solved) && (!finish)) 
		{ 
			//cout << "Number of levels left = " << numlevelsleft << endl; 

			// Find out if it is solved 
			if (numlevelsleft <= 0) 
			{ 
				solved = true; 
				break; 
			} 

			int starsgain = 0; 

			// Go through the list of 2 stars 
			for (int k = 0; k <= numstars; k++) 
			{
				if (!lvls2[k].empty()) 
				{ 
					list<int>::iterator i, toremove; 
					for (i = lvls2[k].begin(); (!starsgain) && (i != lvls2[k].end()); i++) 
					{ 

						int idx = *i; 
						if (starsearned[idx] == 0) 
						{ 
							// Earn two stars, remove the level from the lists 
							starsgain += 2; 
							numlevelsleft--; 
							mingames++; 
							starsearned[idx] = 2; 
							toremove = i; 
						} else if (starsearned[idx] == 1) { 
							// Earn one star, remove the level from the 2 stars list only 
							starsgain += 1; 
							mingames++; 
							starsearned[idx] = 2; 
							toremove = i; 
							numlevelsleft--; 
						} else { 
							// Stars already earned, no additonal new stars 
							// No need to update any lists 
						} 

					} 

					if (starsgain > 0) 
					{ 
						//cout << "Removing level #" << *toremove << " from level 2" << endl; 
						lvls2[k].erase(toremove); 
						break; 
					} 
				} 
			} 
			if (starsgain > 0) { 
				numstars += starsgain; 
				continue; 
			} 


			// Go through the list of 1 stars 
			starsgain = 0; 
			for (int k = 0; k <= numstars; k++) 
			{
				if (!lvls1[k].empty()) 
				{ 
					list<int>::iterator i, toremove; 
					for (i = lvls1[k].begin(); (!starsgain) && (i != lvls1[k].end()); i++) 
					{ 

						int idx = *i; 
						if (starsearned[idx] == 0) 
						{ 
							// Earn one star, remove the level from the lists 
							starsgain += 1; 
							mingames++; 
							starsearned[idx] = 1; 
							toremove = i; 
						} else { 
							// Stars already earned, no additonal new stars 
							// No need to update any lists 
						} 

					} 

					if (starsgain > 0) 
					{ 
						//cout << "Removing level #" << *toremove << " from level 1" << endl; 
						lvls1[k].erase(toremove); 
						break; 
					} 
				} 
			} 
			if (starsgain > 0) { 
				numstars += starsgain; 
				continue; 
			} 

			// Else it could not be solved 
			finish = true; 
			solved = false; 
			break; 

		} 


		stringstream s; 
		if (solved) 
		{ 
			s << "Case #" << count << ": " << mingames; 
			cout << "Case #" << count << ": " << mingames << endl; 
		} else { 
			s << "Case #" << count << ": Too Bad"; 
			cout << "Case #" << count << ": Too Bad" << endl; 
		} 
		
		outfile << s.str() << endl; 

		// Release any variables 
		if (numstars1) { 
			delete[] numstars1; 
			numstars1 = NULL; 
		} 
		if (numstars) { 
			delete[] numstars2; 
			numstars2 = NULL; 
		} 
		if (starsearned) { 
			delete[] starsearned; 
			starsearned = NULL; 
		} 

	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


