#include <iostream>
#include <limits>

struct board{
	char d[4][4];
	char win() const;
};

// loop-free
bool ok(char a, char b, char c, char d){
	if(a=='.' || b=='.' || c=='.' || d=='.')
		return false;
	if(a=='T')
		return b==c && c==d;
	else if(b=='T')
		return a==c && c==d;
	else if(c=='T')
		return a==b && b==d;
	else if(d=='T')
		return a==b && b==c;
	else
		return a==b && b==c && c==d;
}

char board::win() const {
	for(std::size_t i=0; i<4; ++i){
		if(ok(d[i][0], d[i][1], d[i][2], d[i][3]))
			return d[i][0]=='T'?d[i][1]:d[i][0];
		if(ok(d[0][i], d[1][i], d[2][i], d[3][i]))
			return d[0][i]=='T'?d[1][i]:d[0][i];
	}
	if(ok(d[0][0], d[1][1], d[2][2], d[3][3]))
		return d[0][0]=='T'?d[1][1]:d[0][0];
	if(ok(d[3][0], d[2][1], d[1][2], d[0][3]))
		return d[3][0]=='T'?d[2][1]:d[3][0];

	for(std::size_t i=0; i<4; ++i)
		for(std::size_t j=0; j<4; ++j)
			if(d[i][j]=='.')
				return '.';
	return 'D';
}

std::istream &operator>>(std::istream &in, board &rhs){
	for(std::size_t y=0; y<4; ++y){
		for(std::size_t x=0; x<4; ++x)
			in >> rhs.d[y][x];
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return in;
}

int main(){
	std::size_t T;
	std::cin >> T;
	for(std::size_t t=1; t<=T; ++t){
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		board b;
		std::cin >> b;
		std::cout << "Case #" << t << ": ";
		switch(b.win()){
			case 'X':
				std::cout << "X won";
				break;
			case 'O':
				std::cout << "O won";
				break;
			case 'D':
				std::cout << "Draw";
				break;
			case '.':
				std::cout << "Game has not completed";
		}
		std::cout << "\n";
	}
}
