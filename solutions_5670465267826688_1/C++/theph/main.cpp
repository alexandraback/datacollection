#include <fstream>
#include <iostream>
#include <vector>

//quat^4 == 1;
//quat^2 = +-1;
//X = 10^16

struct quaternion
{
	short int real;
	short int i;
	short int j;
	short int k;
};

quaternion quaternion_multiply(const quaternion& first, const quaternion& second)
{
	quaternion answer;
	answer.real = first.real * second.real - first.i * second.i - first.j * second.j - first.k * second.k;
	answer.i = first.real * second.i + first.i * second.real + first.j * second.k - first.k * second.j;
	answer.j = first.real * second.j - first.i * second.k + first.j * second.real + first.k * second.i;
	answer.k = first.real * second.k + first.i * second.j - first.j * second.i + first.k * second.real;
	return answer;
}

quaternion evaluate_P(const std::vector<quaternion>& P)
{
	quaternion answer;
	answer.real = 1;
	answer.i = 0;
	answer.j = 0;
	answer.k = 0;
	
	for(std::vector<quaternion>::const_iterator it = P.begin(); it < P.end(); ++it)
		answer = quaternion_multiply(answer, *it);
		
	return answer;
}

void solve_case()
{
	unsigned long long L;
	unsigned long long X;
	std::cin >> L;
	std::cin >> X;
	
	std::vector<quaternion> P(L);
	for(unsigned long i = 0; i < L; ++i)
	{
		P[i].real = 0;
		P[i].i = 0;
		P[i].j = 0;
		P[i].k = 0;
		char temp;
		std::cin >> temp;
		switch(temp)
		{
			case 'i':
				P[i].i = 1;
				break;
			case 'j':
				P[i].j = 1;
				break;
			case 'k':
				P[i].k = 1;
				break;
		}
	}
	
	quaternion P_value = evaluate_P(P);
	

	if( P_value.real == 1)
	{
		std::cout << "NO";
		return;
	}
	
	unsigned long long iterator = 0;
	// separate i
	quaternion temp = P[0];
	while(temp.i != 1)
	{
		++iterator;
		temp = quaternion_multiply(temp, P[iterator % L]);
		if(iterator > 4 * L)
		{
			std::cout << "NO";
			return;
		}
	}

	++iterator;
	// separate j
	temp = P[iterator % L];
	while(temp.j != 1)
	{
		++iterator;
		temp = quaternion_multiply(temp, P[iterator % L]);
		if(iterator > 8 * L)
		{
			std::cout << "NO";
			return;
		}
	}

	++iterator;
	// separate k
	temp = P[iterator % L];
	while(temp.k != 1)
	{
		++iterator;
		temp = quaternion_multiply(temp, P[iterator % L]);
		if(iterator > 12 * L)
		{
			std::cout << "NO";
			return;
		}
	}

	if((iterator + 1) % L)
	{
		++iterator;
		// evaluate the rest
		temp = P[iterator % L];
		while( (iterator + 1) % L )
		{
			++iterator;
			temp = quaternion_multiply(temp, P[iterator % L]);
		}
	}
	else
	{
		temp.real = 1;
		temp.i = 0;
		temp.j = 0;
		temp.k = 0;
	}

	if(((iterator + 1) / L) > X)
	{
		std::cout << "NO";
		return;
	}	

	for(int i = 0; i < ((X - ((iterator + 1) / L)) % 4); ++i)
		temp = quaternion_multiply(temp, P_value);
	if(temp.real == 1)
		std::cout << "YES";
	else
		std::cout << "NO";
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("C-large.in", "r", stdin);		//input file
	freopen ("C-large.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}