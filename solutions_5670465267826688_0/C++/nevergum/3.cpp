#include <fstream>
//#include <iostream>

class Quad {
public:
	Quad(int n) : num_(n) {}
	int num() const { return num_;}

private:
	int num_;
};

const static Quad QuadOne(0);
const static Quad QuadI(1);
const static Quad QuadJ(2);
const static Quad QuadK(3);
const static Quad QuadNeg(4);
const static Quad QuadNI(5);
const static Quad QuadNJ(6);
const static Quad QuadNK(7);

const static Quad* One= &QuadOne;
const static Quad* I = &QuadI;
const static Quad* J = &QuadJ;
const static Quad* K = &QuadK;
const static Quad* Neg = &QuadNeg;
const static Quad* NI = &QuadNI;
const static Quad* NJ = &QuadNJ;
const static Quad* NK = &QuadNK;


static const Quad* product[8][8] = { {One, I, J, K, Neg, NI, NJ ,NK},
							   {I, Neg, K, NJ, NI, One, NK, J},
							   {J, NK, Neg, I, NJ, K, One, NI},
							   {K, J, NI, Neg, NK, NJ, I, One},
							   {Neg, NI, NJ, NK, One, I, J, K},
							   {NI, One, NK, J, I, Neg, K, NJ},
							   {NJ, K, One, NI, J, NK, Neg, I},
							   {NK, NJ, I, One, K, J, NI, Neg}};
							   
const Quad* char2Quad(char c)
{
	return c == 'i' ? I : (c == 'j' ? J : K);
}

bool checkNeg(const Quad* p, long long n)
{
	return (p != One) && (p == Neg ? (n & 1) : ((n & 3) == 2));
}


long long first[8];
long long last[8];

long long firstI(const Quad* p, long long n, long long l)
{
	const Quad* p2 = product[p->num()][p->num()];
	const Quad* p3 = product[p->num()][p2->num()];
	
	const Quad* X = I;
	int x = X->num();
	
	long long ret = first[x];
	long long extra = 0;
	
	if (ret < 0 && n > 1) {
		const Quad* X1 = product[p3->num()][x];
		int x1 = X1->num();
		ret = first[x1];
		++extra;

		if (ret < 0 && n > 2) {
			const Quad* X2 = product[p3->num()][x1];
			int x2 = X2->num();
			ret = first[x2];
			++extra;
			
			if (ret < 0 && n > 3) {
				const Quad* X3 = product[p3->num()][x2];
				int x3 = X3->num();
				ret = first[x3];
				++extra;
			}			
		}
	}	
	return ret >= 0 ? ret + extra * l : -1;
}

long long lastK(const Quad* p, long long n, long long l)
{
	const Quad* X = product[p->num()][NK->num()];
	int x = X->num();
	
	long long ret = last[x];
	long long extra = 0;
	
	if (ret < 0 && n > 1) {
		const Quad* X1 = product[p->num()][x];
		int x1 = X1->num();
		ret = last[x1];
		++extra;
		
		if (ret < 0 && n > 2) {
			const Quad* X2 = product[p->num()][x1];
			int x2 = X2->num();
			ret = last[x2];
			++extra;

			if (ret < 0 && n > 3) {
				const Quad* X3 = product[p->num()][x2];
				int x3 = X3->num();
				ret = last[x3];
				++extra;
				
			}
		}
	}
	return ret >= 0? ret + (n - extra - 1) * l : -1;
}

void
init()
{
	for (int i = 0; i < 8; ++i) {
		first[i] = last[i] = -1;
	}
}

int main()
{
	std::ifstream ifile("ifile");
	std::ofstream ofile("ofile");
	
	
	int T = 0;
	ifile >> T;
	
	for (int icase = 1; icase <= T; ++icase) {
		
		long long L = 0;
		long long X = 0;
		ifile >> L >> X;
		
		init();
		const Quad* p = One;

		for (long long i = 0; i < L; ++i) {
			
			char c;
			ifile >> c;
		
			const Quad* q = char2Quad(c);
			p = product[p->num()][q->num()];			
			
			int x = p->num();
			last[x] = i+1;
			if (first[x] < 0) {
				first[x] = i+1;
			}
//std::cout << p->num() << ' ';
		}

//std::cout << std::endl;
//for (int i = 0; i < 8; ++i) {
//std::cout << first[i] << ' ' << last[i] << std::endl;
//}
		
		bool ret = checkNeg(p, X);
		if (ret) {
			long long fi = firstI(p, X, L);
			ret = fi > 0;
			if (ret) {
				long long lk = lastK(p, X, L);
				ret = lk > fi;
				
//std::cout << "First I " << fi << ' ' << " LastK " << lk << std::endl;
			}
		}
				
		ofile << "Case #" << icase << ": " << (ret ? "YES" : "NO") << std::endl;
		
//system("Pause");
	}
}
