///#include <tchar.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

struct Case{
	int r, c, m;
	int empty_num = -1;
	bool reversed = false;
	vector<vector<char>> solution;

	void Impossible(ostream& os)
	{
		os << "Impossible";
	}

	int EmptyNum()
	{
		if (empty_num == -1)
			empty_num = r * c - m;
		return empty_num;
	}

	void Solve(ostream& os) {
		reversed = false;
		if (EmptyNum() == 1)
			Solution(1, 1, os);
		else if (min(r, c) == 1)
			Solve1(os);
		else if (EmptyNum() < 4)
			Impossible(os);
 		else
			Solve234(os);		
	}

	void Solve1(ostream& os)
	{
		if (EmptyNum() < 2 && m > 0)
			Impossible(os);
		else {
			InitSolution();
			for (int i = r * c - m; i < r * c; ++i) {
				SetMine(r == 1 ? 0 : i, c == 1 ? 0 : i);
			}
			OutSolution(os);
// 			os << 'c';
// 			for (int i = 1; i < r * c; ++i) {
// 				if (c == 1)
// 					os << endl;
// 				if (i < r * c - m)
// 					os << '.';
// 				else
// 					os << '*';
// 			}
		}
	}

	void Solve234(ostream& os)
	{
		if (r > c) {
			swap(r, c);
			reversed = true;
		}
		else
			reversed = false;

		for (int empty_rows = 2; empty_rows <= r; ++empty_rows) {
			int empty_cols = EmptyCols(empty_rows);
			if (empty_cols == 0)
				continue;
			if (empty_rows > empty_cols)
				break;
			if (TrySolution(empty_rows, empty_cols, os))
				return;
		}
		Impossible(os);		
	}

	bool TrySolution(int empty_rows, int empty_cols, ostream& os)
	{
		if (empty_rows == 2) {
			if (empty_num % 2 == 1)
				return false;
			Solution(empty_rows, empty_cols, os);
		} else if (empty_rows == 3) {
			if (empty_num == 5 || empty_num == 7)
				return false;
			Solution(empty_rows, empty_cols, os);			
		} else {
			Solution(empty_rows, empty_cols, os);
		}

		return true;
	}

	void Solution(int empty_rows, int empty_cols, ostream& os)
	{
		InitMines(empty_rows, empty_cols);
		int additional_mines = empty_rows * empty_cols - EmptyNum();
		if (additional_mines > 0) {
			SetMinesRow(empty_rows - 1, 0, min(additional_mines, empty_cols - 2));
			if (additional_mines == empty_cols - 1)
				SetMine(empty_rows - 2, 0);
		}
		OutSolution(os);
	}

	void InitMines(int empty_rows, int empty_cols)
	{
		for (int row = 0; row < r; ++row)
		for (int col = 0; col < c; ++col)
			if (row >= empty_rows || col >= empty_cols)
				SetMine(row, col);
	}

	void SetMinesRow(int row, int col1, int col_num)
	{
		for (int col = col1; col < col1 + col_num; ++col)
			SetMine(row, col);
	}

	void SetMine(int row, int col)
	{
		InitSolution();
		if (reversed)
			swap(row, col);
		solution[row][col] = '*';
	}

	void InitSolution()
	{
		if (solution.empty()) {
			solution.resize(reversed ? c : r);
			for (auto& row: solution)
				row.resize(reversed ? r : c, '.');
		}
	}

	void OutSolution(ostream& os)
	{
		InitSolution();
		solution[0][0] = 'c';
		for (size_t row_ind = 0; row_ind < solution.size(); ++row_ind) {
			const auto& row = solution[solution.size() - 1 - row_ind];
			for (size_t col_ind = 0; col_ind < row.size(); ++col_ind) {
				char cell = row[col_ind];
				os << cell;
			}
			if (row_ind < solution.size() - 1)
				os << endl;
		}
		CheckSolution();
	}

	int EmptyCols(int empty_rows)
	{
		if (empty_rows > r)
			return 0;

		int
			empty_cols = EmptyNum() / empty_rows;
		if (EmptyNum() % empty_rows != 0)
			++empty_cols;
		return empty_cols > c ? 0 : empty_cols;
	}

	void CheckSolution()
	{		
#ifdef _DEBUG
		while (true)
		{
			int update_count = 0;
			for (int row = 0; row < solution.size(); ++row)
			for (int col = 0; col < solution[row].size(); ++col) {
				char cell = solution[row][col];
				if (cell == 'c' || cell == '0') {
					for (int rowdiff = -1; rowdiff <= 1; ++rowdiff){
						int row2 = row + rowdiff;
						if (row2 >= 0 && row2 < solution.size()){
							for (int coldiff = -1; coldiff <= 1; ++coldiff) {							
								int col2 = col + coldiff;
								if (col2 >= 0 && col2 < solution[row].size())
								{
									if (solution[row2][col2] == '.' || solution[row2][col2] == 'c' ){
										solution[row2][col2] = CalcNeighbourMines(row2, col2) + '0';
										++update_count;
									}
								}
							}
						}
					}
				}
			}

			if (update_count == 0)
				break;
		}

		for (int row = 0; row < solution.size(); ++row)
		for (int col = 0; col < solution[row].size(); ++col) {
			char cell = solution[row][col];
			assert(cell != '.');
		}
#endif // _DEBUG
	}

#ifdef _DEBUG
	int CalcNeighbourMines(int row, int col)
	{
		int count = 0;

		for (int rowdiff = -1; rowdiff <= 1; ++rowdiff) {
			int row2 = row + rowdiff;
			if (row2 >= 0 && row2 < solution.size()) {
				for (int coldiff = -1; coldiff <= 1; ++coldiff) {				
					int col2 = col + coldiff;
					if ((rowdiff != 0 || coldiff != 0)
						&& col2 >= 0 && col2 < solution[row].size())
					{
						if (solution[row2][col2] == '*')
							++count;
					}
				}
			}
		}

		return count;
	}
#endif // _DEBUG


// 	void Solution3(int empty_rows, int empty_cols, ostream& os)
// 	{
// 	}
};


struct Input{
	vector<Case> cases;

	Input(){
//		ifstream ifs("i");
//		assert(!ifs.bad());

		int case_num;
		cin >> case_num;
		for (int i = 0; i < case_num; ++i)
		{
			Case cas;
			cin >> cas.r >> cas.c >> cas.m;
			cases.push_back(cas);
		}
	}
};


int main()
{
	Input inp;
	
//	ofstream ofs("o.txt");	
	for (size_t i = 0; i < inp.cases.size(); ++i)
	{
		cout << "Case #" << (i+1) << ": " << endl;
		inp.cases[i].Solve(cout);
		if (i < inp.cases.size() - 1)
			cout << endl;
	}

//	cin.get();

	return 0;
}
