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
	long long N;
	long long Say;
public:
	static long long nines[];
public:
	static long long reverse(long long i) {
		long long r = 0;
		while(i > 0) {
			r = 10*r + i%10;
			i = i/10;
		}
		return r;
	}
	void read(std::istream& in) {
		in >> N;
		validate(N, 1ll, 100000000000001ll);
	}
	static int pow10(int i) { int r = 1; while(i > 0) { --i; r*= 10; } return r; }
	static void solveall() {
		nines[0] = 0;
		nines[1] = 9;
		for(int n = 2; n <= 14; ++n) {
			long long r = nines[n-1] + 1;//first get enough digits
			int h1 = n/2;
			int h2 = n - h1;
			r += pow10(h1) - 1;
			r += pow10(h2) - 1;
			nines[n] = r;
		}
	}
	void solve() {
		if(N%10 == 0) {
			--N;
			solve();
			Say++;
			return;
		}

		int length = 0;
		for(long long i = N; i > 0; i/=10) ++length;
		if(1 == length) {
			Say = N;
			return;
		}
		long long Say1 = nines[length-1] + 1;//get enough digits
		long long Say2 = Say1;

		{//way1
			long long h1 = N % pow10(length/2);
			long long h2 = reverse(N - h1);

			Say1 += h1;
			Say1 += h2;
			if(h2 == 1) Say1--;//no need to turn
		}
		if(length%2 == 1) {//way2
			long long h1 = N % pow10( (length+1) /2);
			long long h2 = reverse(N - h1);
			
			Say2 += h1;
			Say2 += h2;
			if(h2 == 1) Say2--;//no need to turn
			Say = std::min(Say1, Say2);
		}
		else {
			Say = Say1;
		}
	}
	void print(std::ostream& out) {
		out << Say;
	}
};

long long Problem::nines[15];

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