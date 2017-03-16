#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int warScore(vector<double> naomi, vector<double> ken){
	int points = 0;
	int n = 0; int m = 0;
	while(n < naomi.size() && m < ken.size()){
		if(naomi.at(n) > ken.at(m)) m++;
		else{
			n++;
			m++;
		}
	}
	points = m - n;
	return points;
}

int naomiWar(vector<double> naomi, vector<double> ken){
	int points = 0;
	int n = naomi.size()-1; int m = ken.size()-1;
	while(n >= 0 && m >= 0){
		if(naomi.at(n) > ken.at(m)){
			n--;
			m--;
			points++;
		}
		else{
			m--;
		}
	}
	return points;
}

int main(){
	ifstream fin ("D-large.in");
	ofstream fout ("D-large.out");

	int T; fin >> T;
	for(int t = 0; t < T; t++){
		fout << "Case #" << t+1 << ": ";
		vector<double> naomi;
		vector<double> ken;
		int N; fin >> N;
		
		for(int n = 0; n < N; n++){
			double weight; fin >> weight;
			naomi.push_back(weight);
		}
		for(int n = 0; n < N; n++){
			double weight; fin >> weight;
			ken.push_back(weight);
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());

		fout << naomiWar(naomi, ken) << " " << warScore(naomi, ken) << endl;
	}

	return 0;
}

/*
0.9 0.5 0.1
0.6 0.4 0.3



*/