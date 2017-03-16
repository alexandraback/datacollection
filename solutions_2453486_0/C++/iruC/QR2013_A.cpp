// iruC curi.yun@gmail.com

#include <iostream>
#include <fstream>

enum GAME_STATUS
{
	NOT_COMPLETE,
	DRAW,
	X_WON,
	O_WON
};


inline bool fourInARow( char comparison, char one, char two, char three, char four )
{
	return ( one == 'T' || one == comparison ) &&
	       ( two == 'T' || two == comparison ) &&
	       ( three == 'T' || three == comparison ) &&
	       ( four == 'T' || four == comparison );
}

inline bool hasEmptySquare( char row1[], char row2[], char row3[], char row4[] )
{
	for( int col = 0; col < 4; ++col )
	{
		if( row1[col] == '.' ) return true;
		if( row2[col] == '.' ) return true;
		if( row3[col] == '.' ) return true;
		if( row4[col] == '.' ) return true;
	}
	return false;
}

GAME_STATUS getWinner( char row1[], char row2[], char row3[], char row4[] )
{
	bool xWon = fourInARow('X', row1[0], row1[1], row1[2], row1[3]);
	if( !xWon ) xWon = fourInARow('X', row2[0], row2[1], row2[2], row2[3]);
	if( !xWon ) xWon = fourInARow('X', row3[0], row3[1], row3[2], row3[3]);
	if( !xWon ) xWon = fourInARow('X', row4[0], row4[1], row4[2], row4[3]);
	if( !xWon ) xWon = fourInARow('X', row1[0], row2[0], row3[0], row4[0]);
	if( !xWon ) xWon = fourInARow('X', row1[1], row2[1], row3[1], row4[1]);
	if( !xWon ) xWon = fourInARow('X', row1[2], row2[2], row3[2], row4[2]);
	if( !xWon ) xWon = fourInARow('X', row1[3], row2[3], row3[3], row4[3]);
	if( !xWon ) xWon = fourInARow('X', row1[0], row2[1], row3[2], row4[3]);
	if( !xWon ) xWon = fourInARow('X', row1[3], row2[2], row3[1], row4[0]);

	if( xWon ) return X_WON;

	bool oWon = fourInARow('O', row1[0], row1[1], row1[2], row1[3]);
	if( !oWon ) oWon = fourInARow('O', row2[0], row2[1], row2[2], row2[3]);
	if( !oWon ) oWon = fourInARow('O', row3[0], row3[1], row3[2], row3[3]);
	if( !oWon ) oWon = fourInARow('O', row4[0], row4[1], row4[2], row4[3]);
	if( !oWon ) oWon = fourInARow('O', row1[0], row2[0], row3[0], row4[0]);
	if( !oWon ) oWon = fourInARow('O', row1[1], row2[1], row3[1], row4[1]);
	if( !oWon ) oWon = fourInARow('O', row1[2], row2[2], row3[2], row4[2]);
	if( !oWon ) oWon = fourInARow('O', row1[3], row2[3], row3[3], row4[3]);
	if( !oWon ) oWon = fourInARow('O', row1[0], row2[1], row3[2], row4[3]);
	if( !oWon ) oWon = fourInARow('O', row1[3], row2[2], row3[1], row4[0]);

	if( oWon ) return O_WON;

	return hasEmptySquare(row1, row2, row3, row4)
		? NOT_COMPLETE
		: DRAW;
}

// Skipping all sanity-checking on parameters and input file....
int main( int argc, char** argv )
{
	char dummy[10];
	char buf1[10], buf2[10], buf3[10], buf4[10];
	int testCases;
	std::ifstream inFile(argv[1], std::ifstream::in);

	inFile >> testCases;
	inFile.getline(dummy, sizeof(dummy));

	for( int i = 0; i < testCases; ++i )
	{
		inFile.getline(buf1, sizeof(buf1));
		inFile.getline(buf2, sizeof(buf2));
		inFile.getline(buf3, sizeof(buf3));
		inFile.getline(buf4, sizeof(buf4));

		// Empty line separating test cases
		inFile.getline(dummy, sizeof(dummy));

		std::cout << "Case #" << (i+1) << ": ";
		GAME_STATUS winner = getWinner(buf1, buf2, buf3, buf4);
		switch( winner )
		{
		case NOT_COMPLETE:
			std::cout << "Game has not completed" << std::endl;
			break;
		case DRAW:
			std::cout << "Draw" << std::endl;
			break;
		case X_WON:
			std::cout << "X won" << std::endl;
			break;
		case O_WON:
			std::cout << "O won" << std::endl;
			break;
		}
	}

	inFile.close();

}
