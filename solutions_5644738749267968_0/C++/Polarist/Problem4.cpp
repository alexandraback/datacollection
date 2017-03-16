#include "Problem4.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <assert.h>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

ifstream in("problem4.in");
ofstream out("problem4.out");

// assume in is sorted from lowest to highest
bool nextHighest(vector<double>& in, double val, int &outindex, double &out){
	for (int i = 0; i < in.size(); i++){
		if (in[i]>val){
			outindex = i;
			out = in[i];
			return true;
		}
	}
	return false;
}

int deceitfulWar(int numBlocks, vector<double> &_naomi, vector<double> &_ken){
	int naomiscore=0, kenscore=0;
	vector<double> naomi(_naomi);
	vector<double> ken(_ken);

	int ansindex;
	double ans;

	for (auto& n : naomi){
		// if naomi's lowest is going to lose, then force out ken's highest
		if (n < ken.front()){
			// remove item and resort
			ken.pop_back();
			sort(ken.begin(), ken.end());
			kenscore++;
		}
		else {
			// remove lowest
			ken.erase(ken.begin());
			sort(ken.begin(), ken.end());

			naomiscore++;
		}
	}

	return naomiscore;
}

int war(int numBlocks, vector<double> &_naomi, vector<double> &_ken){
	int naomiscore=0, kenscore =0;
	vector<double> naomi(_naomi);
	vector<double> ken(_ken);

	int ansindex;
	double ans;
	for (auto& n : naomi){
		if (nextHighest(ken, n, ansindex, ans)){
			// remove item and resort
			ken.erase(ken.begin() + ansindex);
			sort(ken.begin(), ken.end());

			kenscore++;
		} else {
			// remove lowest
			ken.erase(ken.begin());
			sort(ken.begin(), ken.end());

			naomiscore++;
		}
	}
	return naomiscore;
}




int main(int argc, char ** argv){
	int count = 0;
	in >> count;

	vector<double> naomi;
	vector<double> ken;

	int numBlocks;
	for (int i = 0; i < count; i++){
		// Get inputs
		in >> numBlocks;

		naomi.clear();
		ken.clear();

		//naomi.resize(numBlocks);
		//ken.resize(numBlocks);

		double input;
		for (int j = 0; j < numBlocks; j++){
			in >> input;
			naomi.push_back(input);
		}
		for (int j = 0; j < numBlocks; j++){
			in >> input;
			ken.push_back(input);
		}

		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());

		auto answer1 = deceitfulWar(numBlocks, naomi, ken);
		auto answer2 = war(numBlocks, naomi, ken);

		out << fixed;
		out << "Case #" << i + 1 << ": " << answer1 << " " << answer2 << endl;
	}


	return 0;
}