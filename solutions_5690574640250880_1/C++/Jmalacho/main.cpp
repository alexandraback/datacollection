#include <limits>
#include <fstream>
#include <iostream>
using std::endl;
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

std::ofstream gLogger("./log");

typedef vector<string> Board;

class Minesweeper {
public:
  Minesweeper( const char * filename ) : mInFile(filename)  {
    gLogger << "Minesweeper contructed with: " << filename << endl;
  }
  void Load() {
    mInFile >> mNumTestCases;
    gLogger << "Number of testcases: " << mNumTestCases << endl;

    int tmpItem;
    for (int testCaseIdx=0; testCaseIdx < mNumTestCases; ++testCaseIdx) {
       gLogger << " Loading testcase: " << testCaseIdx+1 << endl;
       mInFile >> mRows;
       mInFile >> mCols;
       mInFile >> mNumMines;
       std::cout << "Case #" << testCaseIdx +1 << ": ";
       std::cout << endl;
       this->SolveCurrentProblem();
    }
  }

  void GenerateBoard(unsigned int boardnum) {
    
    for (int mine_row=mRows-1; mine_row>=0; --mine_row) {
      for (int mine_col=mCols-1; mine_col>=0; --mine_col){
	mBoard[mine_row][mine_col]='.';
      }
    }
    mBoard[0][0]='c';
   for (int mine_row=mRows-1; mine_row>=0; --mine_row) {
      for (int mine_col=mCols-1; mine_col>=0; --mine_col){
	if (boardnum%2) mBoard[mine_row][mine_col]='*';
	boardnum>>=1;
	
      }
    }
  }
  
  void SolveCurrentProblem() {
    //Prepare board
    mBoard.clear();
    string tmpString(mCols,'.');
    for (int row_idx=0; row_idx<mRows; ++row_idx)
      mBoard.push_back(tmpString);
    unsigned int max_board_num;
    if (mNumMines >64) {
      std::cout << "Impossible\n"; 
      gLogger << "  Too Many Mines";
      return;
    }
     if ( mRows * mCols > 65 ) {
       std::cout << "Impossible\n"; 
       return;
     } else {
       max_board_num = (1 << mRows * mCols) -1;
     }
     for (unsigned int boardnum=0; boardnum <= max_board_num; ++boardnum) {
       if ( __builtin_popcount(boardnum) != mNumMines ) continue;
       //gLogger << "   Teseting Board: " << boardnum << " of " << max_board_num << endl; 
       this->GenerateBoard(boardnum);
       mTestBoard=mBoard;
       if (Validate()) {
	BOOST_FOREACH( string row, mBoard) {
            std::cout << row << endl;
        }
        return;
       }
     }    
     std::cout << "Impossible\n"; 
     gLogger << "  Exhausted Boards";
  }
  
  int GetNumMines( int row, int col) {
    int numMines=0;
    for (int col_idx=col-1; col_idx <= col +1; ++col_idx) {
      if (col_idx < 0) continue;
      if (col_idx >= mCols) continue;
      for (int row_idx=row-1; row_idx <= row+1; ++ row_idx) {
        if (row_idx < 0) continue;
        if (row_idx >= mRows) continue;
	if (row_idx==row && col_idx==col) continue;
        if (mTestBoard[row_idx][col_idx]=='*') numMines++;
      }
    }
    return numMines;
  }
  
  void Click( int row, int col) {
    //gLogger << "Clicked called on (" << row << ", " << col << ")\n";
    if (col < 0) return;
    if (row < 0) return;
    if (col >= mCols) return;
    if (row >= mRows) return;
    int numMines;
    switch(mTestBoard[row][col]) {
      case '.':
      case 'c':
        numMines=GetNumMines(row,col);
	mTestBoard[row][col]=boost::lexical_cast<char>(numMines);
	if (numMines==0) {
	  for (int col_idx=col-1; col_idx <= col +1; ++col_idx) {
	    if (col_idx < 0) continue;
	    if (col_idx >= mCols) continue;
	    for (int row_idx=row-1; row_idx <= row+1; ++ row_idx) {
	      if (row_idx < 0) continue;
	      if (row_idx >= mRows) continue;
	      if (row_idx==row && col_idx==col) continue;
	      Click(row_idx,col_idx);
	    }
	  }
	}
	break;
      default:
	return;
    }
  }
  
  bool Validate() {
    mTestBoard=mBoard;
    Click(0,0);    
    BOOST_FOREACH( string row, mTestBoard) {
      if (row.find('.') != string::npos) {
	return false;
      }
    }
    return true;
  }
private:
  Minesweeper();
  std::ifstream mInFile;
  int mNumTestCases;
  
  int mRows;
  int mCols;
  int mNumMines;
  typedef vector<string> Board;
  Board mBoard;
  Board mTestBoard;
};

void cleanup() {
  gLogger.close();
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    std::cerr << "No file given\n";
    return 1;
  } else {
    atexit(&cleanup);
    Minesweeper problem(argv[1]);
    problem.Load();
  }
  return 0;
}