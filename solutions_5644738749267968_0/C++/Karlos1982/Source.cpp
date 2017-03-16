//program deceitful war
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#include <math.h>
#include <list>
#include <algorithm>
#include <tokenizer.hpp>  //split function to tokenize strings according to delimiters

using namespace std;

//kenstones = list<double> in ascending ordered
double ken_strategy(list<double> &kenstones, double naomitold, bool simulate=false) {
	for (auto i = kenstones.begin(); i!=kenstones.end();++i) {
		if (naomitold < (*i)) {
			double play = (*i);
			if (!simulate) kenstones.erase(i);
			return play; //return smaller stone that is better than naomi
		}
	}
	double play = kenstones.front();
	if (!simulate) kenstones.pop_front();
	return play; //if no one is better, return the smaller stone
}

double naomi_deceit_strategy(list<double> &kenstones, list<double> &naomistones) {
	double naomi_smaller = naomistones.front();
	if (naomistones.size() == 1) return naomi_smaller;
	if (naomi_smaller > kenstones.back()) {
		return naomistones.front();
	}
	double lie = 0.0;
	if (naomi_smaller < kenstones.front()) {
		auto it = kenstones.rbegin();
		++it;
		lie = (kenstones.back() + (*it)) / 2; //say your stone weights optimally
	}
	else {
		lie = naomi_smaller + naomistones.back()+kenstones.back(); //biggest, non-repeated weight
	}

	return lie;
}

//this method solves the problem
string solve(vector<string> linesA, vector<string> linesB, int size) {
	list <double> naomi;
	list < double> ken;
	string solution = "";
	int kenscore = 0;
	int naomiscore = 0;
	int kennaivescore = 0;
	int naominaivescore = 0;

	for (register int i = 0; i < size; ++i) {
		naomi.push_back(stod(linesA[i]));
		ken.push_back(stod(linesB[i]));
	}
	naomi.sort(); //sort in ascending order
	ken.sort(); //sort in ascending order

	list<double> naominaive(naomi.begin(),naomi.end());
	list<double> kennaive(ken.begin(),ken.end());

	/**
	* BODY of SOLVE method
	*/
	stringstream ss;

	//naomi plays deceit war
	for (int i = 0; i<size; i++) {
		double told = naomi_deceit_strategy(ken,naomi); //naomi deceit war strategy
		double chosennaomi = naomi.front();
		naomi.pop_front();
		double chosenken = ken_strategy(ken, told);
	
		(chosenken > chosennaomi) ? kenscore++ : naomiscore++;
	}

	//naomi plays war game
	for (int i = 0; i<size; i++) {
		double chosenn = naominaive.back(); //naomi war strategy
		naominaive.pop_back();
		double chosenk = ken_strategy(kennaive, chosenn);

		(chosenk > chosenn) ? kennaivescore++ : naominaivescore++;
	}
	ss << naomiscore << " " << naominaivescore;
	return ss.str();

	return solution;
}

int main(int argc, char* argv[]) {
	string in, temp, line;
	if (argc<2 || argc>3) {
		cout << "Please use <app> <infile> <outfile>" << '\n';
		return 0;
	}
	in = argv[1];
	string out = (argc == 3) ? argv[2] : "out.txt";
	
	//reading input file
	ifstream myfile(in);
	ofstream myoutfile(out);
	if (myfile.is_open()&&myoutfile.is_open())
	{
		//read first line, with number of problems to solve
		getline(myfile, line);
		int times = stoi(line); //number of use cases
		int count = 0;
		//solve X problems
		while (count<times) {
			getline(myfile, line);
			int tiles = stoi(line);
			getline(myfile, line);
			vector<string> naomi=split(line);
			getline(myfile, line);
			vector<string> ken = split(line);
			//work with the input file one line each time
			myoutfile << "Case #" << (++count) << ": " << solve(naomi,ken,tiles) << '\n';
			//cout << line << '\n';
		}
		myfile.close();
		myoutfile.close();
	}
	else cout << "Unable to open file\n";
	return 0;
}