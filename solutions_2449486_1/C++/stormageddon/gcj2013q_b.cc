#include <iostream>
#include <vector>

using namespace std;

// LawnWorks returns true if the Lawn can be mowed in this manner
bool LawnWorks(const vector<vector<int> >& lawn,
		       const vector<int>& rowHeight,
		       const vector<int>& columnHeight) {
	for (int rowNum = 0; rowNum < static_cast<int>(lawn.size()); rowNum++)
		for (int columnNum = 0; columnNum < static_cast<int>(lawn.at(rowNum).size()); columnNum++) {
			int grass = lawn.at(rowNum).at(columnNum);
			if (grass < rowHeight.at(rowNum) && grass < columnHeight.at(columnNum))
				return false;
		}
	return true;
}
int main() {
	int cases = 0;
	cin >> cases;
	for (int caseNum = 1; caseNum <= cases; caseNum++) {
		cout << "Case #" << caseNum << ": ";
		int rows = 0;
		cin >> rows;
		int columns = 0;
		cin >> columns;
		vector<vector<int> > lawn;
		vector<int> rowHeight(rows, 0); // maximum height found in this row
		vector<int> columnHeight(columns, 0); // maximum height found in this column
		for (int rowNum = 0; rowNum < rows; rowNum++) {
			lawn.push_back(vector<int>());
			for (int columnNum = 0; columnNum < columns; columnNum++) {
				int grass = 0; // Height of the grass at this block
				cin >> grass;
				lawn.at(rowNum).push_back(grass);
				if (grass > rowHeight.at(rowNum))
					rowHeight.at(rowNum) = grass;
				if (grass > columnHeight.at(columnNum))
					columnHeight.at(columnNum) = grass;
			}
		}
		if (LawnWorks(lawn, rowHeight, columnHeight))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
