//
//  main.cpp
//  Google Code Jam 2013
//
//  Created by Kristopher Giesing on 4/12/13.
//  Copyright (c) 2013 Kristopher Giesing. All rights reserved.
//

#include <iostream>
#include <fstream>

class Lawn {
public:
	Lawn(int nRows, int nCols);
	~Lawn();
	
	inline int get(int row, int col) { return mLawnHeights[row*mNumCols + col]; }
	inline void put(int row, int col, int value) { mLawnHeights[row*mNumCols + col] = value; }
	
	int maxInRow(int row);
	int maxInCol(int col);
	bool analyze();
	
private:
	int mNumRows;
	int mNumCols;
	int *mLawnHeights;
};

Lawn::Lawn(int nRows, int nCols)
: mNumRows(nRows),
  mNumCols(nCols),
  mLawnHeights(new int[nRows*nCols])
{
}

Lawn::~Lawn()
{
	delete [] mLawnHeights;
}

int
Lawn::maxInRow(int row)
{
	int result = 0;
	for (int i = 0; i < mNumCols; i++) {
		result = std::max(result, this->get(row, i));
	}
	return result;
}

int
Lawn::maxInCol(int col)
{
	int result = 0;
	for (int i = 0; i < mNumRows; i++) {
		result = std::max(result, this->get(i, col));
	}
	return result;
}

bool
Lawn::analyze()
{
	// Find max grass height in each row
	int maxInRows[mNumRows];
	for (int row = 0; row < mNumRows; row++) {
		maxInRows[row] = maxInRow(row);
	}
	// Find max grass height in each col
	int maxInCols[mNumCols];
	for (int col = 0; col < mNumCols; col++) {
		maxInCols[col] = maxInCol(col);
	}
	
	for (int row = 0; row < mNumRows; row++) {
		for (int col = 0; col < mNumCols; col++) {
			int height = this->get(row, col);
			if (height < maxInRows[row] && height < maxInCols[col]) {
				//std::cout << "Found assumption violation at " << row << "," << col << "\n";
				//std::cout << "Height: " << height << "\n";
				//std::cout << "Max in row: " << maxInRows[row] << "\n";
				//std::cout << "Max in col: " << maxInCols[col] << "\n";
				return false;
			}
		}
	}
	return true;
}

int main(int argc, const char * argv[])
{
	std::ifstream input(argv[1]);
	int nTests;
	input >> nTests;
	for (int i = 0; i < nTests; i++) {
		int nRows, nCols;
		input >> nRows;
		input >> nCols;
		Lawn lawn(nRows, nCols);
		//std::cout << "\n";
		for (int row = 0; row < nRows; row++) {
			for (int col = 0; col < nCols; col++) {
				int height;
				input >> height;
				//std::cout << height << " ";
				lawn.put(row, col, height);
			}
			//std::cout << "\n";
		}
		bool possible = lawn.analyze();
		std::cout << "Case #" << (i+1) << ": ";
		std::cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}
