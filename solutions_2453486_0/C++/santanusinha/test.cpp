#include<iostream>

using namespace std;

enum Status {
	X_WON,
	O_WON,
	DRAW,
	UNFINISHED
};

enum Glyph {
	DOT=0x0,
	X=0x1,
	O=0x2,
	T=0x3,
};

Glyph toGlyph(char c) {
	switch(c) {
		case 'X':
			return X;
		case 'O':
			return O;
		case '.':
			return DOT;
		case 'T':
			return T;
	}
	return T;
}

char toChar(Glyph g) {
	switch(g) {
		case X:
			return 'X';
		case O:
			return 'O';
		case DOT:
			return '.';
		case T:
			return 'T';
	}
	return T;

}

Status analyze(Glyph (&board)[4][4]){
		bool unresolved = false;
		for(int row=0; row < 4; row++ ) {
			switch(board[row][0] & board[row][1] & board[row][2] & board[row][3]) {
				case X:
					return X_WON;	
				case O:
					return O_WON;
				case DOT:
				case T:
					unresolved = true;
			}
		}
		for(int col=0; col< 4; col++ ) {
			switch(board[0][col] & board[1][col] & board[2][col] & board[3][col]) {
				case X:
					return X_WON;	
				case O:
					return O_WON;	
				case DOT:
					unresolved = true;
			}
		}
		switch(board[0][0] & board[1][1] & board[2][2] & board[3][3]) {
			case X:
				return X_WON;
			case O:
				return O_WON;	
			case DOT:
				unresolved = true;
		}
		switch(board[0][3] & board[1][2] & board[2][1] & board[3][0]) {
			case X:
				return X_WON;	
			case O:
				return O_WON;	
			case DOT:
				unresolved = true;
		}
		bool filled = true;
		if(unresolved) {
			for(int row=0; row < 4; row++ ) {
				for(int col=0; col<4; col++ ) {
					 if(board[row][col]==DOT) {
						return UNFINISHED;
					}
				}
			}
		}
		return DRAW;
}



int main() {
	int numCases;
	cin>>numCases;
	for(int i = 1; i <= numCases; i++ ) {
		Glyph board[4][4];
		cin.clear();
		cin.ignore(1);
		for(int row=0; row < 4; row++ ) {
			std::string rowBuf;
			getline(cin,rowBuf);
			for(int col=0; col<4; col++ ) {
				board[row][col]=toGlyph(rowBuf.c_str()[col]);
			}
		}
		cout<<"Case #"<<i<<": ";
		switch(analyze(board)) {
			case X_WON: {
				cout<<"X won"<<endl;
				break;
			}
			case O_WON: {
				cout<<"O won"<<endl;
				break;
			}
			case DRAW: {
				cout<<"Draw"<<endl;
				break;
			}
			case UNFINISHED: {
				cout<<"Game has not completed"<<endl;
				break;
			}
		}
	}
	return 0;
}
	
