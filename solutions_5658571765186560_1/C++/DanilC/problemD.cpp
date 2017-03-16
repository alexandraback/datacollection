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
		if((R * C) % X != 0) //anything
			return true;
		if(X >= 7)  // semi-circle with anything outside
			return true;
		if(X > R && X > C) //long one
			return true;
		if(X == 1 || X == 2) //just one possible piece and rest if fillable
			return false;
		if(R == 1 || C == 1) //something of width 2 couldn't be fit
			return true;
		if(X == 3)
			return false; //there are too few of 3-ominos...
		if(X == 4) {
			if(C == 2 || R == 2)
				return true; //T-mino!! 
			return false; //manuall check show that all few bad cases are covered above
		}
		if(X == 5) {
			if(C == 2 || R == 2)
				return true; //W
			if(C * R == 15) //i.e. 3x5
				return true; //same W
			//3x10 fillable
			//4x5 fillable
			//everything else has one of 2 above + some easily fillable space
			return false;
		}
		if(X == 6) {
			if(C == 2 || R == 2)
				return true; //W + something
			if(C == 3 || R == 3)
				return true; // ....
			                 //   .   3x + 2 space not fillable with 6minos
							 //   .
			//otherwise there is box 4x6 inside that can hold nicely any nasty 6mino
			return false;
		}
		//hm, program looks stupid... somewhy manual check was easier
		throw std::exception("all cases should be covered");
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