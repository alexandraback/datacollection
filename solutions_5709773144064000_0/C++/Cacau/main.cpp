#include "main.h"

//Apologies for the poor code structure quality

int main(int argc, char* argv[]){
	if (argc < 2)
		cout << "Don't forget to pass the name of the input file (with extension) as a parameter!" << endl;

	string filename = argv[1];
	vector<input> inputs;

	readInputs(filename, inputs);
	writeSolution(inputs);
	return 0;
}

string solve(input &inElem){
	stringstream ss;
	double cookiesPerSec = 2.0;

	vector<double> timeToFarm;
	vector<double> timeToWin;
	timeToFarm.push_back(inElem.C / cookiesPerSec);
	timeToWin.push_back(inElem.X / cookiesPerSec);

	int i = 0;
	do {
		cookiesPerSec += inElem.F;
		timeToWin.push_back(timeToFarm[i] + inElem.X / cookiesPerSec);

		timeToFarm.push_back(timeToFarm[i] + inElem.C / cookiesPerSec); //for next timeToWin
		i++;
	} while (timeToWin[i] < timeToWin[i - 1]);

	ss << fixed << setprecision(7) << timeToWin[timeToWin.size()-2];
	return ss.str();
}

void writeSolution(vector<input> &inputs){
	fstream ofile("test.ou", fstream::out);

	for (unsigned int i = 0; i < inputs.size(); i++){
		ofile << "Case #" << i+1 << ": " << solve(inputs[i]) << endl;
	}

	ofile.close();
}

void readInputs(string inputfile, vector<input> &inputs){
	fstream ifile(inputfile, fstream::in);
	if (!ifile.is_open()){
		cout << "Could not open file " << inputfile << "." << endl;
		exit(-1);
	}

	string line = "";
	do{
		getline(ifile, line);
	} while (line.length() <= 0);

	int numInputs = atoi(line.c_str());

	while (numInputs > 0){
		numInputs--;
		input curIn;

		getline(ifile, line);
		stringstream m1_ss(line);
		m1_ss >> curIn.C; m1_ss >> curIn.F; m1_ss >> curIn.X;
		
		inputs.push_back(curIn);
	}

	ifile.close();
}