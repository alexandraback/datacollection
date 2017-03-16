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

	vector<vector<char>> matrix;
	matrix.resize(inElem.R);
	for (unsigned int i = 0; i < matrix.size(); i++)
		matrix[i].resize(inElem.C);

	int numFreeCells = inElem.R*inElem.C - inElem.M; //The number of cells that need to be cleared
	//aka, the area we can expand from the click position
	bool solFound = false;
	
	for (unsigned int i = 0; i < matrix.size() && !solFound; i++)
		for (unsigned int j = 0; j < matrix[i].size() && !solFound; j++)
			solFound = clearMatrix(matrix, i, j, numFreeCells);

	if (!solFound)
		ss << "Impossible" << endl;
	else{
		for each (auto row in matrix)
		{
			for each (auto column in row)
			{
				ss << column;
			}
			ss << endl;
		}
	}

	return ss.str();
}
bool clearMatrix(vector<vector<char>> &matrix, int row, int column, int numFreeCellsLeft){
	for (unsigned int i = 0; i < matrix.size(); i++)
		for (unsigned int j = 0; j < matrix[i].size(); j++)
			matrix[i][j] = '*';

	int numCurrentBombs = matrix.size()*matrix[0].size();

	matrix[row][column] = '.';
	numFreeCellsLeft--;

	queue<pair<int,int>> neighbours;
	stack<vector<vector<char>>> previousMatrixes;
	stack<int> previousNumFreeCellsLeft;
	stack<queue<pair<int, int>>> previousNeighbours;

	neighbours.push(pair<int, int>(row, column));


	while (numFreeCellsLeft > 0 && !neighbours.empty()){
		previousNeighbours.push(neighbours);
		previousMatrixes.push(matrix);
		previousNumFreeCellsLeft.push(numFreeCellsLeft);

		pair<int, int> currentPos = neighbours.front();
		neighbours.pop();

		clearNeighbours(neighbours, currentPos.first, currentPos.second, matrix, numFreeCellsLeft);
		while (neighbours.empty() && numFreeCellsLeft > 0 && !previousMatrixes.empty()){
			matrix = previousMatrixes.top(); previousMatrixes.pop();
			numFreeCellsLeft = previousNumFreeCellsLeft.top(); previousNumFreeCellsLeft.pop();
			neighbours = previousNeighbours.top(); previousNeighbours.pop();
			neighbours.pop();
		}
	}

	matrix[row][column] = 'c';
	return numFreeCellsLeft==0;
}

void clearNeighbours(queue<pair<int, int>> &neighbours, int row, int column, vector<vector<char>> &matrix, int &numFreeCellsLeft){
	pair<int, int> positions[8] = { pair<int, int>(row - 1, column - 1), pair<int, int>(row - 1, column), pair<int, int>(row - 1, column + 1), 
									pair<int, int>(row, column - 1), pair<int, int>(row, column + 1),
									pair<int, int>(row + 1, column - 1), pair<int, int>(row + 1, column), pair<int, int>(row + 1, column + 1),
									};
	int r = matrix.size();
	int c = matrix[0].size();
	int surroundingBombCount = 0;
	for (int i = 0; i < 8; i++){
		if (positions[i].first >= 0 && positions[i].first < r
			&& positions[i].second >= 0 && positions[i].second < c){
			if (matrix[positions[i].first][positions[i].second] == '*'){
				surroundingBombCount++;
			}
		}
	}

	if (surroundingBombCount > numFreeCellsLeft) //cannot consider this one a 0
		return;

	for (int i = 0; i < 8; i++){
		if (positions[i].first >= 0 && positions[i].first < r
			&& positions[i].second >= 0 && positions[i].second < c){
			if (matrix[positions[i].first][positions[i].second] == '*'){
				neighbours.push(positions[i]);
				numFreeCellsLeft--;
				matrix[positions[i].first][positions[i].second] = '.';
			}
		}
	}
}

void writeSolution(vector<input> &inputs){
	fstream ofile("test.ou", fstream::out);

	for (unsigned int i = 0; i < inputs.size(); i++){
		ofile << "Case #" << i+1 << ":" << endl << solve(inputs[i]);
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
		m1_ss >> curIn.R; m1_ss >> curIn.C; m1_ss >> curIn.M;
		
		inputs.push_back(curIn);
	}

	ifile.close();
}