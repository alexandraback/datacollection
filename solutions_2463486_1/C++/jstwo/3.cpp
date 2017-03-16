#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <gmp.h>
#include <assert.h>
#include <string.h>
bool validate_fair(const mpz_t v) {
	char buf[200];
	mpz_get_str(buf, 10, v);
	int len = strlen(buf);
	int half_len = (len +1 ) /2;
	for(int i =0; i < half_len;++i) {
		if(buf[i] != buf[len - 1 -i])
			return false;
	}
	return true;
}
template<int x, bool start_zero > class fair {
	public:
	static void gen(long long base, long long factor1, long  long factor2, const mpz_t min,  const mpz_t max, bool& term, long long& result) 
	{
		for(int i =(start_zero ? 0: 1) ; i <=9 && term ==false ;++i) {
			fair<x -2, true>::gen(base + i * factor2 + i * factor1, factor1/10 , factor2 * 10, min,  max, term, result);
		}
	}
};
mpz_t a, b ;
mpz_t min, max;

template <bool start_zero> class  fair<1, start_zero> {
	public:
	static void gen(long base, long factor1, long factor2, const mpz_t min,  const mpz_t max, bool& term, long long& result) 
	{
		for(int i =(start_zero ? 0: 1) ; i <=9 && term ==false ;++i) {
			long long value = base + i * factor1;
			mpz_set_si(a, value);
			mpz_mul(b, a, a);
			if(mpz_cmp(b ,  max) > 0)  {
				term = true;
				return;
			}
			if(mpz_cmp(b, min) < 0) {
				continue;
			}
			else if(validate_fair(b))
				result +=1;
		}
	}
};
template <bool start_zero> class fair<2, start_zero> {
	public:
	static void gen(long base, long factor1, long factor2, const mpz_t min,  const mpz_t max, bool& term, long long& result) 
	{
		for(int i =(start_zero ? 0: 1) ; i <=9 && term ==false;++i) {
			long long value = base + i * factor1  + i * factor2;
			mpz_set_si(a, value);
			mpz_mul(b, a, a);
			if(mpz_cmp(b ,  max) > 0)  {
				term = true;
				return;
			}
			if(mpz_cmp(b, min) < 0) {
				continue;
			}
			else if(validate_fair(b))
				result +=1;
		}
	}
};

void solve(int case_num, std::ifstream& input)
{
	std::cout << "Case #" << case_num << ": ";
	long long result =0;
	bool term= false;
	char buf[200];
	input >> buf;
	mpz_set_str(min, buf, 10);
	input >> buf;
	mpz_set_str(max, buf, 10);
	if (mpz_cmp_si (min, 0) == 0)
		result +=1;
	fair<1, false>::gen(0, 1, 1, min, max, term, result);
	fair<2, false>::gen(0, 10, 1, min, max, term, result);
	fair<3, false>::gen(0, 100, 1, min, max, term, result);
	fair<4, false>::gen(0, 1000, 1, min, max, term, result);
	fair<5, false>::gen(0, 10000, 1, min, max, term, result);
	fair<6, false>::gen(0, 100000, 1, min, max, term, result);
	fair<7, false>::gen(0, 1000000, 1, min, max, term, result);
	fair<8, false>::gen(0, 10000000ll, 1, min, max, term, result);
	fair<9, false>::gen(0, 100000000ll, 1, min, max, term, result);
	fair<10, false>::gen(0,1000000000ll, 1, min, max, term, result);
	fair<11, false>::gen(0,10000000000ll, 1, min, max, term, result);
	std::cout << result << "\n";
}
void init(int case_num) {
	mpz_init(min);
	mpz_init(max);
	mpz_init(a);
	mpz_init(b);
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}
	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	init(c);
	for(int i =1; i <=c;++i) {
		solve(i, in);
	}
	return 0;
}
