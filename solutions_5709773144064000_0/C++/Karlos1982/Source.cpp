//program cookie clicker alpha
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
//#include <map>
#include <algorithm>
//#include <InfInt.h> //bignum library
#include <tokenizer.hpp>  //split function to tokenize strings according to delimiters
//#include <factorial.hpp>

using namespace std;

//method that returns the waiting time until you obtain X cookies, given a rate of Y cookies per second
inline double waiting(double cookies, double cps) {
	return cookies / cps;
}

//this method solves the problem
string solve(vector<string> lines) {
	vector<string> tokens = split(lines[0]);
	string solution = "";
	string buffer;

	/**
	* BODY of SOLVE method
	*/
	double cost = stod(tokens[0]); //cost of a cookie
	double rate = stod(tokens[1]); //rate of cookie
	double goal = stod(tokens[2]); //cookies to achieve
	double time = 0.0; //time it takes to reach the goal
	double current_rate = 2;
	double besttime = goal / current_rate; //estimation of best time
	bool betterfound;
	double aux;
	double slowstart = 0.0;
	double slow = 0.0;
	double best_current_rate = current_rate;
	do {
		betterfound = false;
		aux = time + slowstart + waiting(cost, current_rate) + waiting(goal, current_rate + rate);
		if (aux	< besttime) {
			besttime = aux;
			time += waiting(cost, current_rate);
			current_rate += rate;
			betterfound = true;
			best_current_rate = current_rate;
		}
		//test if buying more than one farm would eventually get a better time
		if (betterfound == false) {
			if (slow==0.0) slow = aux - besttime; //initializes only the first time
			//second chance
			if (slow >= (aux - besttime)||((time+slowstart)<besttime)) {
				slow = aux - besttime;
				slowstart += waiting(cost, current_rate);
				current_rate += rate;
				betterfound = true;
			}
		}
	} while (betterfound);
	time += waiting(goal, best_current_rate);
	besttime = time;

	
	stringstream ss;
	ss.precision(9);
	ss << time;
	ss >> solution;
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
			vector<string> lines;
			lines.push_back(line);
			//work with the input file one line each time
			myoutfile << "Case #" << (++count) << ": " << solve(lines) << '\n';
			//cout << line << '\n';
		}
		myfile.close();
		myoutfile.close();
	}
	else cout << "Unable to open file\n";
	return 0;
}