#include <iostream>
using namespace std;

#define OO 1
#define XX 2
#define TT 3

int play[4][4] ;
int T, nCase = 1 ;

void input()
{
	char line[10] ;
	for ( int i=0;i<4;++i ) {
		cin >> line ;
		for ( int j=0;j<4;++j ) {
			switch(line[j]){
				case 'O': play[i][j] = OO ; break;
				case 'X': play[i][j] = XX ; break;
				case 'T': play[i][j] = TT ; break;
				default: play[i][j] = 0 ; break;
			}
		}
	}
}

bool test(int c)
{
	if ( (play[0][0]&c) && (play[0][1]&c) && (play[0][2]&c) && (play[0][3]&c) ) return true;
	if ( (play[1][0]&c) && (play[1][1]&c) && (play[1][2]&c) && (play[1][3]&c) ) return true;
	if ( (play[2][0]&c) && (play[2][1]&c) && (play[2][2]&c) && (play[2][3]&c) ) return true;
	if ( (play[3][0]&c) && (play[3][1]&c) && (play[3][2]&c) && (play[3][3]&c) ) return true;

	if ( (play[0][0]&c) && (play[1][0]&c) && (play[2][0]&c) && (play[3][0]&c) ) return true;
	if ( (play[0][1]&c) && (play[1][1]&c) && (play[2][1]&c) && (play[3][1]&c) ) return true;
	if ( (play[0][2]&c) && (play[1][2]&c) && (play[2][2]&c) && (play[3][2]&c) ) return true;
	if ( (play[0][3]&c) && (play[1][3]&c) && (play[2][3]&c) && (play[3][3]&c) ) return true;
	
	if ( (play[0][0]&c) && (play[1][1]&c) && (play[2][2]&c) && (play[3][3]&c) ) return true;
	if ( (play[0][3]&c) && (play[1][2]&c) && (play[2][1]&c) && (play[3][0]&c) ) return true;

	return false ;
}

bool empty()
{
	if ( !play[0][0] || !play[0][1] || !play[0][2] || !play[0][3] ) return true;
	if ( !play[1][0] || !play[1][1] || !play[1][2] || !play[1][3] ) return true;
	if ( !play[2][0] || !play[2][1] || !play[2][2] || !play[2][3] ) return true;
	if ( !play[3][0] || !play[3][1] || !play[3][2] || !play[3][3] ) return true;

	return false ;
}

#define O_WIN 0
#define X_WIN 1
#define DRAW 2
#define NOTOVER 3

int judge()
{
	if ( test(OO) ) return O_WIN;
	if ( test(XX) ) return X_WIN;
	if ( empty() ) return NOTOVER;
	return DRAW;
}

const char* msg[4] =
{
	"O won",
	"X won",
	"Draw",
	"Game has not completed"
};

int main()
{
	cin >> T ;
	while(T--){
		input();
		cout << "Case #"<<nCase++<<": "<<msg[judge()] <<endl;
	}
	return 0;
}