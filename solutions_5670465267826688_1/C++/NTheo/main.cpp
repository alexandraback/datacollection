//Theophile Dalens 2015

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Q
{
public:
	char v;
	int s;
	Q operator*(const Q &q)
	{
		Q w;
		w.s = s*q.s;
		switch (v)
		{
		case 0:
			w.v = q.v;
			break;
		case 1:
			switch (q.v)
			{
			case 0:
				w.v = 1;
				break;
			case 1:
				w.v = 0;
				w.s = -w.s;
				break;
			case 2:
				w.v = 3;
				break;
			case 3:
				w.v = 2;
				w.s = -w.s;
				break;
			}
			break;
		case 2:
			switch (q.v)
			{
			case 0:
				w.v = 2;
				break;
			case 1:
				w.v = 3;
				w.s = -w.s;
				break;
			case 2:
				w.v = 0;
				w.s = -w.s;
				break;
			case 3:
				w.v = 1;
				break;
			}
			break;
		case 3:
			switch (q.v)
			{
			case 0:
				w.v = 3;
				break;
			case 1:
				w.v = 2;
				break;
			case 2:
				w.v = 1;
				w.s = -w.s;
				break;
			case 3:
				w.v = 0;
				w.s = -w.s;
				break;
			}
			break;
		}
		return w;
	}
	Q(){}
	Q(char c)
	{
		switch(c)
		{
		case '1':
			v = 0;
			break;
		case 'i':
			v = 1;
			break;
		case 'j':
			v = 2;
			break;
		case 'k':
			v = 3;
			break;
		}
		s = 1;
	}
};


int main(int, char**)
{
	std::ifstream input("C-large.in");
	std::ofstream output("C-large.out");
	int T;
	input >> T;
	for (int t = 0; t < T; t++)
	{
		output << "CASE #" << (t + 1) << ": ";
		int L;
		long long X;
		std::string s;
		input >> L >> X;
		int x = (X>12) ? (20 + (X % 4)) : X;
		input >> s;
		std::vector<Q> cumProd;
		cumProd.reserve(x*L);
		cumProd.push_back(Q(s[0]));
		for (int l = 1; l < L; l++)
			cumProd.push_back(cumProd.back() * Q(s[l]));
		for (int rep = 1; rep < x; rep++)
			for (int l = 0; l < L; l++)
				cumProd.push_back(cumProd.back() * Q(s[l]));
		int fi = -1;
		if (cumProd.back().v != 0 || cumProd.back().s != -1)
		{
			output << "NO" << std::endl;
			continue;
		}
		for (int fif = 0; fif < x*L; fif++)
		{
			if (cumProd[fif].v == 1 && cumProd[fif].s == 1)
			{
				fi = fif;
				break;
			}
		}
		if (fi < 0)
		{
			output << "NO" << std::endl;
			continue;
		}
		int lj = -1;
		for (int ljf = x*L - 1; ljf > fi; ljf--)
		{
			if (cumProd[ljf].v == 3 && cumProd[ljf].s == 1)
			{
				lj = ljf;
				break;
			}
		}
		if (lj < 0)
		{
			output << "NO" << std::endl;
			continue;
		}
		output << "YES" << std::endl;
	}
	return 0;
}