#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
bool from_string(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&)) {
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

template <typename T>
string tostr(const T& t) { 
	ostringstream os; os<<t; 
	return os.str();
} 

int _tmain(int argc, _TCHAR* argv[])
{
  string line,cell;
  vector<vector<string>> m;
  //ifstream in ("C-small-attempt1.in");
  ifstream in ("C-large.in");
  //ifstream in ("sample.in");
  if (in.is_open())
  {
    while ( getline (in ,line) )
    {
        stringstream lineStream(line);
		vector<string> tmp;
        while( getline( lineStream, cell, ' ' ) ) {
			tmp.push_back(cell);
		}
		m.push_back(tmp);
    }
    in.close();
  }
  
  ofstream out;
  out.open("codejam.out");

  int no_cases;
  from_string<int>(no_cases, m[0][0], std::dec);
  for (int c=0;c<no_cases;c++) {
	  out << "Case #" << c+1 << ":\n";
	  int rows, cols, mines;
	  from_string<int>(rows, m[c+1][0], std::dec);
	  from_string<int>(cols, m[c+1][1], std::dec);
	  from_string<int>(mines, m[c+1][2], std::dec);
	  int empty=rows*cols-mines;
	  bool solved=false;

	  //init board
	  vector<vector<char>> board;
	  board.resize(rows);
	  for (int i=0;i<rows;i++) {
		  board[i].resize(cols);
		  for (int j=0;j<cols;j++) {
			  board[i][j]='*';
		  }
	  }
	  board[0][0]='c';

	  //one empty cell - do nothing
	  if (empty==1) {
		  solved=true;
	  } else {

	  //1 row || 1 col - trivial solve
	  if (rows==1) {
		  for (int i=1;i<empty;i++) {
			  board[0][i]='.';
		  }
		  solved=true;
	  } else if (cols==1) {
		  for (int i=1;i<empty;i++) {
			  board[i][0]='.';
		  }
		  solved=true;

	  } else if (empty==4) {
		  //special case: 2x2
		  board[0][1]='.';
		  board[1][0]='.';
		  board[1][1]='.';
		  solved=true;
	  } else {

	  //non-trival solve
	  //out << empty << " empty cells.\n";
	  solved=false;
	  bool flipped=false;
	  int e_rows=1000;
	  int e_cols=1000;
	  int extra_mines=0;
	  bool extra_extra_mine=false;

	  for (int i=2;((i<empty/2) && (!solved));i++) {
		int r=empty%i;
		extra_extra_mine=false;
		switch (r) {
		case 0:
			//out << i << "*" << (empty/i) << "\n";
			e_rows=i;
			e_cols=(empty/i);
			extra_mines=0;
			break;
		case 1:
			e_rows=i;
			e_cols=(empty/i)+1;
			extra_mines=i-r;
			if ((e_rows>3) && (e_cols>3) && (extra_mines>2)) {
				extra_extra_mine=true;
				extra_mines--;
				//out << "e_rows=" << e_rows << " e_cols=" << e_cols << " extra_mines=" << extra_mines << "\n";
			} else {
				e_rows=1000;
				e_cols=1000;
			}
			
			break;
		default:
			//out << i << "*" << (empty/i)+1 << "-" << i-r << "\n";
			e_rows=i;
			e_cols=(empty/i)+1;
			extra_mines=i-r;
			break;
		}
		if ((e_rows<=rows) && (e_cols<=cols)) {
			solved=true;
			flipped=false;
			//out << e_cols << "-" << extra_mines << "*" << e_rows << "\n";
		} else {
			if ((e_rows<=cols) && (e_cols<=rows)) {
				solved=true;
				flipped=true;
				int tmp=e_cols;
				e_cols=e_rows;
				e_rows=tmp;
				//out << e_rows << "*" << e_cols << "-" << extra_mines << "\n";
			}
		}
		}
		if (solved) {
			for (int i=0;i<e_rows;i++) {
				for (int j=0;j<e_cols;j++) {
					if ((i+j)!=0) board[i][j]='.';
				}
			}
			if ((extra_mines>0) && (flipped)) {
				for (int i=e_cols-extra_mines;i<e_cols;i++) {
					board[e_rows-1][i]='*';
				}
				if (extra_extra_mine) {
					board[e_rows-2][e_cols-1]='*';
				}
			}
			if ((extra_mines>0) && (!flipped)) {
				for (int i=e_rows-extra_mines;i<e_rows;i++) {
					board[i][e_cols-1]='*';
				}
				if (extra_extra_mine) {
					board[e_rows-1][e_cols-2]='*';
				}

			}
		}
	  }
	  }

	  //output
	  if (!solved) {
		  out << "Impossible\n";
	  } else {
		for (int i=0;i<board.size();i++) {
		  for (int j=0;j<board[i].size();j++) {
			  out << board[i][j];
		  }
		  out << "\n";
		}
	  }
  }
  out.close();
  return 0;
}

