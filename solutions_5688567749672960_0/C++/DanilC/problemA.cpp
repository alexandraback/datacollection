#include <exception>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

template<typename T>
void validate(T parameter, T min, T max) {
	if(parameter < min && parameter > max)
		throw std::exception("invalid parameter");
}

class Problem {
	int N;
	int Say;
	static const int max = 1000000;
	static int All[max+1];
public:
	static int reverse(int i) {
		int r = 0;
		while(i > 0) {
			r = 10*r + i%10;
			i = i/10;
		}
		return r;
	}
	static void solveall() {
		All[0] = 0;
		for(int i = 1; i <= max; ++i) All[i] = i;//fill with something valid
		for(int i = 1; i <= max; ++i) {
			if(All[i-1] + 1 < All[i]) 
				All[i] = All[i-1] + 1;

			int r = reverse(i);
			if(All[r] > All[i] + 1) {
				All[r] = All[i] + 1;
			}
		}
	}
	void read(std::istream& in) {
		in >> N;
		validate(N, 1, 1000000);
	}
	void solve() {
		Say = All[N];
	}
	void print(std::ostream& out) {
		out << Say;
	}
};

int Problem::All[Problem::max+1];


int main(int argc, char** argv) {
	std::istream* in = &std::cin;
	std::ostream* out = &std::cout;
	if(argc > 1) {
		in = new std::ifstream(argv[1]);

		std::string fout(argv[1]);
		int ext = fout.rfind('.');
		fout = fout.substr(0, ext);
		fout += ".out";
		out = new std::ofstream(fout);
	}

	Problem::solveall();

	try {
		int T;
		(*in) >> T;
		validate(T, 1, 100);
		(*out) << std::setprecision(7) << std::fixed;

		for(int iT = 1; iT <= T; ++iT) {
			Problem p;
			p.read(*in);
			p.solve();
			(*out) << "Case #" << iT << ": ";
			p.print(*out);
			(*out) << std::endl;
		}

	}
	catch(std::exception& x) {
		std::cerr << "something went wrong: " << x.what();
	}
	catch(...) {
		std::cerr << "unknown exception";
	}
	return 0;
}