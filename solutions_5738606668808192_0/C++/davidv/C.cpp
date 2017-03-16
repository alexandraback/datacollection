/* Uses the GNU Multiprecision library available at gmplib.org */
/*  also available as package in most linux distributions */
#include <bits/stdc++.h>
#include <gmp.h>

using namespace std;

void pollardRho(mpz_t res, mpz_t num) {
	gmp_randstate_t rng;
	gmp_randinit_default(rng);
	
	mpz_t x, y;
	mpz_init(x);
	mpz_init(y);
	
	mpz_urandomm(x, rng, num);
	mpz_set(y,x);
	
	while (true) {
		mpz_addmul_ui(x,x,1);
		mpz_mod(x,x,num);
		
		mpz_addmul_ui(y,y,1);
		mpz_mod(y,y,num);
		mpz_addmul_ui(y,y,1);
		mpz_mod(y,y,num);
		
		if (mpz_cmp(x,y) < 0)
			mpz_sub(res, y, x);
		else
			mpz_sub(res, x, y);
		
		mpz_gcd(res,res,num);
		
		if (mpz_cmp(res,num) == 0) {
			mpz_urandomm(x,rng,num);
			mpz_set(y,x);
		}
		else if (mpz_cmp_ui(res, 1) != 0) {
			mpz_clear(x);
			mpz_clear(y);
			return;
		}
	}
}

void doCase(int t)
{
	cout << "Case #" << t << ":" << endl;
	int N, J;
	cin >> N >> J;
	
	// upper bound for what to investigate
	mpz_t lim;
	mpz_init(lim);
	mpz_ui_pow_ui(lim, 2, N);
	
	// lowest candidate
	mpz_t start;
	mpz_init(start);
	mpz_ui_pow_ui(start, 2, N-1);
	mpz_add_ui(start, start, 1);
	
	// temporary
	mpz_t temp, temp2;
	mpz_init(temp);
	mpz_init(temp2);
	
	// Buffer for easy base conversions
	vector<char> buffer(N+2);
	
	// Buffer for output to iostreams
	vector<char> buffer2(N+2);
	
	int count = 0;
	
	for (/*do nothing*/; mpz_cmp(start, lim) < 0; mpz_add_ui(start, start, 2)) {
		if (mpz_probab_prime_p(start, 20) != 0) continue;
		
		mpz_get_str(&buffer[0], 2, start);
		
		bool isCandid = true;
		for (int b=3; b<=10 && isCandid; b++)
		{
			mpz_set_str(temp, &buffer[0], b);
			if (mpz_probab_prime_p(temp, 20) != 0) isCandid = false;
		}
		
		if (!isCandid) continue;
		
		cout << &buffer[0];
		cout.flush();
		
		pollardRho(temp, start);
		mpz_get_str(&buffer2[0], 10, temp);
		cout << " " << &buffer2[0];
		cout.flush();
		
		for (int b=3; b<=10; b++) {
			mpz_set_str(temp, &buffer[0], b);
			pollardRho(temp2, temp);
			mpz_get_str(&buffer2[0], 10, temp2);
			cout << " " << &buffer2[0];
			cout.flush();
		}
		cout << endl;
		
		count++;
		if (count == J) break;
	}
	
	mpz_clear(start);
	mpz_clear(lim);
	mpz_clear(temp);
	mpz_clear(temp2);
}

int main()
{
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
