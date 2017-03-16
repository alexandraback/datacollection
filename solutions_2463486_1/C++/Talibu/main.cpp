#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_set>
#include<cmath>
#include<algorithm>

 #include <gmpxx.h>
 #include <gmp.h>

bool isPalin(const mpz_class N)
{
	const std::string S = N.get_str();
	for (unsigned int i=0; i<S.length()/2; i++)
		if (S[i]!=S[S.length()-1-i])
			return 0;
	return 1;
}

std::vector<mpz_class> VEC;


long long CNT = 0;
void test(std::string N, const unsigned int d, const int S)
{
	if (d==N.length()/2+N.length()%2)
	{
		mpz_class I(N);
		if (isPalin(I*I))
		{
			//std::cout << CNT++ << " " << N.length() << " " << N << "\n";
			VEC.push_back(I*I);
		}
		return ;
	}
	
	int LL = (d==0) ? 1 : 0;
	for (int i=LL; i<=3; i++)
		if (i*i+S<10)
		{
			N[d] = i+'0';
			N[N.length()-1-d] = i+'0';
			test(N, d+1, S+i*i);
		}
}

int doitIT(const mpz_class A, const mpz_class B)
{
	 auto AI = std::lower_bound(VEC.begin(), VEC.end(), A);
	while (*AI>=A)
		--AI;
	 auto BI = std::lower_bound(VEC.begin(), VEC.end(), B);
	while (*BI>B)
		--BI;
// 	std::cout << A << " " << B << " " << *AI << " " << *BI << "\n";
	return std::distance(AI, BI);
}


std::vector<long long> read()
{
	std::vector<long long> R;
	
	int T;
	std::cin >> T;
	for (int i=0; i<T; i++)
	{
		mpz_class A, B;
		std::cin >> A >> B;
		R.push_back(doitIT(A, B));
	}
	return R;
}

void output(const std::vector<long long>& R)
{
	for (unsigned int i=0; i<R.size(); i++)
	{
			std::cout << "Case #" << (i+1) << ": " << R[i] << "\n";
	}
}

int main(int argc, char* argv[])
{
	for (int l=1; l<=50; l++)
	{
		std::string S(l, 'X');
		test(S, 0, 0);
	}
	VEC.push_back(0);
	VEC.push_back(mpz_class("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
	std::sort(VEC.begin(), VEC.end());

	const auto R = read();
	output(R);
}
