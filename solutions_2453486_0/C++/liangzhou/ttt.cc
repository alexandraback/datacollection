#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace codejam {

enum Status { XWIN, OWIN, DRAW, NOT_FINISH };
enum Flag {X, O, T, EMPTY};

// board is a 4 by 4 array
Status JudgeBoard(int **board) {  
  // check four rows
  for (int i = 0; i < 4; i++) {
    int flag = board[i][0];
    if (flag == EMPTY) continue;
    if (flag == T && board[i][1] != EMPTY) flag = board[i][1];
    int idx = 1;
    while (idx < 4 && (board[i][idx] == flag || board[i][idx] == T)) { idx++; }
    if (idx == 4) {
      switch (flag) {
        case X:
          return XWIN;
        case O:
          return OWIN;
      }
    }
  }
  // check four colums
  for (int i = 0; i < 4; i++) {
    int flag = board[0][i];
    if (flag == EMPTY) continue;
    if (flag == T && board[1][i] != EMPTY) {
      flag = board[1][i];
    }
    int idx = 1;
    while (idx < 4 && (board[idx][i] == flag || board[idx][i] == T)) { idx++; }
    if (idx == 4) {
      switch (flag) {
        case X:
          return XWIN;
        case O:
          return OWIN;
      }
    }
  }
  // check one diagnal
  int flag = board[0][0];
  if (flag != EMPTY) {
  if (flag == T && board[1][1] != EMPTY) {
    flag = board[1][1];
  }
  int idx = 1;
  while (idx < 4 && (board[idx][idx] == flag || board[idx][idx] == T)) idx++;
  if (idx == 4) {
      switch (flag) {
        case X:
          return XWIN;
        case O:
          return OWIN;
      }
  } 
  }
  // check another diagnoal
  flag = board[0][3];
  if (flag != EMPTY) {
  if (flag == T && board[1][2] != EMPTY) {
    flag = board[1][2];
  }
  int idx = 1;
  while (idx <4 && (board[idx][3-idx] == flag || board[idx][3-idx] == T)) idx++;
  if (idx == 4) {
      switch (flag) {
        case X:
          return XWIN;
        case O:
          return OWIN;
      }
  }     
  }

  // check draw
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == EMPTY) return NOT_FINISH;
    }
  }  

  // DRAW
  return DRAW;
}

void FillBoard(int **board, std::ifstream &ifs) {
  for (int i = 0; i < 4; i++) {
    std::string tmp;
    std::getline(ifs, tmp); 
    std::istringstream iss(tmp);
    for (int j = 0; j < 4; j++) {
      switch (tmp[j]) {
       case 'X':
        board[i][j] = X;
        break;
       case 'O':
        board[i][j] = O;
        break;
       case 'T':
        board[i][j] = T;
        break;
       case '.':
        board[i][j] = EMPTY;
       default:
        break;
      } // switch
    } // for j
  } // for i
  return;
}

void WriteOutput(int case_num, Status s, std::ofstream &ofs,
        std::vector<std::string> &cache) {
  ofs << "Case #" << case_num << ": " << cache[s] << std::endl;
}

} // namespace codejame

// read in two parameters, the first one is the input file name
// the second one is the output file name
int main(int argc, char *argv[]) {
  using namespace std;
  using namespace codejam;

  ifstream ifs(argv[1], ifstream::in);
  ofstream ofs(argv[2]); 
  
  vector<string> cache;

  cache.push_back("X won");
  cache.push_back("O won");
  cache.push_back("Draw");
  cache.push_back("Game has not completed");

  string buff;
  getline(ifs, buff);
  istringstream iss(buff);
  int **board = new int *[4];
  for (int i = 0; i < 4; i++) board[i] = new int[4];

  int case_count = 0;
  iss >> case_count; 

  int i = 0;
  while (i < case_count) {
    // read four lines
    FillBoard(board, ifs); 
    WriteOutput(i+1, JudgeBoard(board), ofs, cache);
    // Skip one line. 
    getline(ifs, buff);
    i++;  // move to next test case;
  } 

  ofs.flush();
  ifs.close();
  ofs.close();
  // free memory of board 
  for (int i = 0; i < 4; i++) delete [] board[i];
  delete [] board;
  return 0;
}
