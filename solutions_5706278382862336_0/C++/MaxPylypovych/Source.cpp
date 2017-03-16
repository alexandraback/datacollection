#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;


typedef unsigned int uint;
typedef unsigned long long ullong;

vector<ullong> powers;



ullong gcd(ullong a, ullong b)
{
	ullong c;
	while (a != 0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void reduce(ullong& p, ullong& q)
{
	ullong x = gcd(p, q);
	p = p / x;
	q = q / x;
}


int main()
{
	ofstream output;
//	ifstream input;
//	input.open("input.txt");
	output.open("output.txt");

	FILE *fp;
	fp = fopen("input.txt", "r");



	uint T;
//	input >> T;
	fscanf(fp, "%i", &T);
	ullong P,Q;
	bool res;
	
	
	for (ullong i = 1; i <= 1099511627776; i *= 2)
	{
		powers.push_back(i);
	}



	int ans = 0;
	char c;

	for (uint t = 0; t < T;++t)
	{
		res = 1;
		ans = 0;
//		input >> P >> c >> Q;
		fscanf(fp, "%llu%c%llu", &P, &c, &Q);

		reduce(P, Q);

		if (find(powers.begin(), powers.end(), Q) == powers.end())
		{
			res = 0;
		}
		else
		{
			long double x=P, y=Q;
			
			while (P / Q < 0.5)
			{
				Q /= 2;
				++ans;
			}
		}








		output << "Case #" << t + 1 << ": ";

		if (!res)
			output << "impossible";
		else
			output << ans;

		output << "\n";


	}




//	input.close();
	output.close();
	//	system("pause");
	return 0;
}
