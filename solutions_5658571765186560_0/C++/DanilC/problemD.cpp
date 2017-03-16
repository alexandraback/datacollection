#include <exception>
#include <iostream>
#include <iomanip>

template<typename T>
void validate(T parameter, T min, T max) {
	if(parameter < min && parameter > max)
		throw std::exception("invalid parameter");
}

class Problem {
	int X, R, C;
	bool Xexists;
public:
	void read(std::istream& in) {
		in >> X >> R >> C;
		validate(X, 1, 20);
		validate(R, 1, 20);
		validate(C, 1, 20);
	}
	inline void solve() { Xexists = does_the_bad_one_exists(); }
	bool does_the_bad_one_exists() {
		if( (X > R && X > C) //long one
			|| X >= 7  // semi-circle
			|| (R * C) % X != 0 //anything
			) {
			return true;
		}
		if(X == 1 || X == 2) //just one possible piece and rest if fillable
			return false;
		if(R == 1 || C == 1 && X > 2) //something of width 2 couldn't be fit
			return true;
		if(X == 3)
			return false; //there are too few of 3-ominos...
		if(X == 4 && (C == 2 || R == 2))
			return true; //T-mino!! 
		if(X == 4)
			return false; //and 4-ominos... manuall check show that all few bad cases are covered above

		throw std::exception("do not know yet");
	}
	void print(std::ostream& out) {
		out << (Xexists? "RICHARD": "GABRIEL") << std::endl;
	}
};


int main(int argc, char** argv) {
	try {
		int T;
		std::cin >> T;
		validate(T, 1, 100);
		std::cout << std::setprecision(7) << std::fixed;

		for(int iT = 1; iT <= T; ++iT) {
			Problem p;
			p.read(std::cin);
			p.solve();
			std::cout << "Case #" << iT << ": ";
			p.print(std::cout);
		}

	}
	catch(std::exception& x) {
		std::cerr << "something went wrong: " << x.what();
	}
	return 0;
}