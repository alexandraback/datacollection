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

	inElem.naomiBlocks.sort();
	inElem.kenBlocks.sort();

	ss << maxDeceitfulWar(inElem) << " " << maxWar(inElem);

	return ss.str();
}

int maxDeceitfulWar(input inElem){
	int score = 0;

	while (!inElem.naomiBlocks.empty()){
		if (inElem.naomiBlocks.front() < inElem.kenBlocks.front()){
			inElem.naomiBlocks.pop_front();
			inElem.kenBlocks.pop_back();
		}
		else
		{
			score++;
			double naomiVal = inElem.naomiBlocks.front();
			inElem.naomiBlocks.pop_front();
			for (list<double>::reverse_iterator it = inElem.kenBlocks.rbegin(); it != inElem.kenBlocks.rend(); it++){
				if (*it < naomiVal){
					inElem.kenBlocks.remove(*it);
					break;			
				}
			}
		}
	}



	return score;
}

int maxWar(input inElem){
	int score = 0;
	list<double>::reverse_iterator naomiChoice;
	list<double>::reverse_iterator kenChoice;
	for (list<double>::reverse_iterator it = inElem.naomiBlocks.rbegin(); it != inElem.naomiBlocks.rend(); it++){
		naomiChoice = it;
		bool assigned = false;
		for (list<double>::reverse_iterator it2 = inElem.kenBlocks.rbegin(); it2 != inElem.kenBlocks.rend(); it2++){
			if (*it2 > *naomiChoice){
				kenChoice = it2;
				assigned = true;
			}
			else{
				if (!assigned){
					kenChoice = inElem.kenBlocks.rend();
					kenChoice--;
				}
				break;
			}
		}

		if (*naomiChoice > *kenChoice)
			score++;

		inElem.kenBlocks.remove(*kenChoice);
	}
	return score;
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
		m1_ss >> curIn.numBlocks;

		double curValue;
		getline(ifile, line);
		m1_ss.clear(); m1_ss.str(line);
		for (int i = 0; i < curIn.numBlocks; i++){
			m1_ss >> curValue;
			curIn.naomiBlocks.push_back(curValue);
		}

		getline(ifile, line);
		m1_ss.clear(); m1_ss.str(line);
		for (int i = 0; i < curIn.numBlocks; i++){
			m1_ss >> curValue;
			curIn.kenBlocks.push_back(curValue);
		}

		
		inputs.push_back(curIn);
	}

	ifile.close();
}