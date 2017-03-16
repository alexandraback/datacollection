#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//************************
//****   MINE_BOARD   ****
//************************

class MineBoard
{
public:
       MineBoard(int ,int ,int );
       void examineBoard();
       void printMessage(int ,ostream & = std::cout) const;
       void validate(int k) const
        {
          int m=0;
          for (int i=0;i<R;i++){
              for (int j=0;j<C;j++){
                  if (board[i][j]=='*') m++;
              }
          }
          if (M != m){
                cerr << "Test case #" << k << "  error\n"
                     << "M: " << M << "  " << "m: " << m << endl;
          }    
        }
private:
        const int R;
        const int C;
        const int M;
        vector<vector<char> > board;
        bool possible;
        void printBoard(ostream & = std::cout) const;
        void fillBoard(int );
};

MineBoard::MineBoard(int r,int c,int m):R(r),C(c),M(m),possible(false)
{
  board = vector<vector<char> >(R);
  for (int i=0;i<R;i++) board[i] = vector<char>(C);
  for (int i=0;i<R;i++){
      for (int j=0;j<C;j++) board[i][j] = '*';
  }
}

void MineBoard::examineBoard()
{
  int L = R*C-M;
  int N = R>C?C:R;
  
  if (M==0 || N==1 || L==1){ possible=true; fillBoard(L); } 
  else if (N == 2){ possible=(L>3 && !(L%2)); if (possible) fillBoard(L); }
  else{
       possible = !(L<4 || L==5 || L==7);
       if (possible){
          if (L == 4) { board[0][1]='.'; board[1][0]='.'; board[1][1]='.'; }
          else{
               int i,j;
               for (i=0;i<R;i++){
                   if (L >= 3){
                      for (j=0;j<3;j++) board[i][j] = '.';
                      L -= 3;
                   }else if (L){
                         board[i][0]='.'; board[i][1]='.';
                         if (L == 1) board[i-1][2]='*'; 
                         L = 0;
                         break;
                   }
               }
               for (j=3;j<C;j++){
                   for (i=0;i<R;i++){
                       if (--L == -1){
                           if (i == 1) { board[1][j]='.'; board[R-1][j-1]='*'; }
                           j=C; break;
                       }
                       board[i][j] = '.';
                       //printBoard(); cout << endl; system("pause");
                   }
               } 
          }
          board[0][0] = 'c';
       }
  }
  
}

void MineBoard::fillBoard(int L)
{
  int k = 0;
  if (R>C){
  for (int i=0;i<R;i++){
      for (int j=0;j<C;j++){
          k++;
          board[i][j]='.';
          if (k == L){ board[0][0]='c'; return; }
      }
  }
  }
  else{
       for (int i=0;i<C;i++){
           for (int j=0;j<R;j++){
               k++;
               board[j][i]='.';
               if (k == L){ board[0][0]='c'; return; }
           }
       }
  }
}

void MineBoard::printMessage(int k,ostream &out) const
{
     /*
  out << "Case #" << k << ": " << " R=" << R << "  C=" << C << "  M=" << M << "  " << "L=" << R*C-M << endl;
  if (possible) validate(k);
  else out << "Impossible";
  out << endl;
  printBoard(out);*/
  out << "Case #" << k << ":\n";
  if (possible) printBoard(out);
  else out << "Impossible";

}

void MineBoard::printBoard(ostream &out) const
{
  for (int i=0;i<R;i++){
      for (int j=0;j<C;j++) out << board[i][j];
      if (i != R-1) out << endl;
  }
}


//*******************
//*****  MAIN   *****
//*******************

int main()
{
  ifstream input("C-large.in");
  if (!input) exit(1);
  ofstream output("out.txt");
  if (!output) exit(1);
  
  int T,R,C,M;
  
  input >> T;
  
  for (int k=1;k<=T;k++){
      input >> R >> C >> M;
      MineBoard mb(R,C,M);
      mb.examineBoard();
      mb.printMessage(k,output);
      output << endl;
  }
  
  scanf("%*c");
  return 0;
}
