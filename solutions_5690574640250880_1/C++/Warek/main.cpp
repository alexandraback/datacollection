#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <vector>

void markAlmostMines(int rows, int cols, std::vector < std::vector <char> > &board)
{
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			if (board[i][j]=='.'){
				if ( (i-1)>=0 && (j-1)>=0 && board[i-1][j-1]=='*') board[i][j]='a';
				if ( (i-1)>=0 && board[i-1][j]=='*') board[i][j]='a';
				if ( (i-1)>=0 && (j+1) < cols && board[i-1][j+1]=='*') board[i][j]='a';
				if ( (j-1)>=0 && board[i][j-1]=='*') board[i][j]='a';
				if ( (j+1) < cols && board[i][j+1]=='*') board[i][j]='a';
				if ( (i+1) < rows && (j-1)>=0 && board[i+1][j-1]=='*') board[i][j]='a';
				if ( (i+1) < rows && (j+1) < cols && board[i+1][j+1]=='*') board[i][j]='a';
				if ( (i+1) < rows && board[i+1][j]=='*') board[i][j]='a';
			}
		}
	}
}

bool isPossibleToSolve(int rows, int cols, std::vector < std::vector<char> > &board)
{
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			if (board[i][j]=='a'){
				if ( (i-1)>=0 && (j-1)>=0 && board[i-1][j-1]=='.') continue;
				if ( (i-1)>=0 && board[i-1][j]=='.') continue;
				if ( (i-1)>=0 && (j+1) < cols && board[i-1][j+1]=='.') continue;
				if ( (j-1)>=0 && board[i][j-1]=='.') continue;
				if ( (j+1) < cols && board[i][j+1]=='.') continue;
				if ( (i+1) < rows && (j-1)>=0 && board[i+1][j-1]=='.') continue;
				if ( (i+1) < rows && (j+1) < cols && board[i+1][j+1]=='.') continue;
				if ( (i+1) < rows && board[i+1][j]=='.') continue;
				return false;
			}
		}
	}
	return true;
}

void addSolution(int rows, int cols, std::vector < std::vector<char> > &board)
{
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			if (board[i][j]=='.'){
				board[i][j]='c';
				return;
			}
		}
	}
}

void unmarkAlmostMines(int rows, int cols, std::vector < std::vector<char> > &board)
{
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			if (board[i][j]=='a'){
				board[i][j]='.';
			}
		}
	}
}
void tryRowFill(int mines, int rows, int cols, std::vector < std::vector<char> > &board, int startrow, int startcol);

void tryColFill(int mines, int rows, int cols, std::vector < std::vector<char> > &board, int startrow, int startcol)
{
	for (int i=startrow;i<rows;i++){
		board[i][startcol]='*';
		mines--;
		if (mines==0){
			return;
		}
	}
	tryRowFill(mines,rows,cols,board,startrow,startcol+1);
}
void tryRowFill(int mines, int rows, int cols, std::vector < std::vector<char> > &board, int startrow, int startcol)
{
	if (mines==0) return;
	int completeRows=mines / cols;
	int mod=mines % cols;
	int l=0;

	if (startrow!=rows-3 && startrow!=rows-2 && startrow!=rows-1){
		if (completeRows>0){
			completeRows--;
			mines-=cols;
			for (int i=startcol;i<cols;i++){
				board[startrow][i]='*';
			}
			tryRowFill(mines,rows,cols,board,startrow+1,0);
		} else {
			int c=startcol;
			while (mines>0){
				board[startrow][c]='*';
				c++;
				mines--;
				if (c==cols-2) break;
			}
			tryRowFill(mines,rows,cols,board,startrow+1,0);
		}
		return;
	}
	if (((rows-startrow)-mines >= 2) || (rows-startrow)-mines <= 0){
		tryColFill(mines,rows,cols,board,startrow,startcol);
		return;
	}

	if (((cols-startcol)-mines >= 2) || (cols-startcol)-mines <= 0){
		int c=startcol;
		for (int i=0;i<mines;i++){
			board[startrow][c]='*';
			c++;
		}
		mines=0;
		return;
	}
	else{
		tryColFill(mines,rows,cols,board,startrow,startcol);
	}
}

int main(int argc, char *argv[])
{
	std::ifstream read("C-large.in");
	std::ofstream write("C-large.out");
	//std::ifstream read("input.txt");
	//std::ofstream write("output.txt");
	int num=0;
	read >> num;
	int rows,cols,mines;
	for (int i=0;i<num;i++)
	{
		read >> rows >> cols >> mines;
		// more or equal mines as array
		if (mines>=rows*cols)
		{
			write << "Case #" << i+1 << ":" << std::endl;
			write << "Impossible" << std::endl;
			continue;
		}
		std::vector < std::vector<char> > board(rows, std::vector<char>(cols));

		// 1 left position remains
		if (mines+1==rows*cols)
		{
			for (int i=0;i<rows;i++)
				for (int j=0;j<cols;j++)
					board[i][j]='*';
			board[rows-1][cols-1]='c';
			write << "Case #" << i+1 << ":" << std::endl;
			for (int i=0;i<rows;i++){
				for (int j=0;j<cols;j++){
					write << board[i][j];
				}
				write << std::endl;
			}
			continue;
		}

		// plain board
		for (int i=0;i<rows;i++)
			for (int j=0;j<cols;j++)
				board[i][j]='.';

		tryRowFill(mines,rows,cols,board,0,0);
		markAlmostMines(rows,cols,board);
		if (isPossibleToSolve(rows,cols,board)){
			addSolution(rows,cols,board);
			unmarkAlmostMines(rows,cols,board);
			write << "Case #" << i+1 << ":" << std::endl;
			for (int i=0;i<rows;i++){
				for (int j=0;j<cols;j++){
					write << board[i][j];
				}
				write << std::endl;
			}
			continue;
		} else{
			write << "Case #" << i+1 << ":" << std::endl;
			write << "Impossible" << std::endl;
			continue;
		}		
	}
	return 0;
}

