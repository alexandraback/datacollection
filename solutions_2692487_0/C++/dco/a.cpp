#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

typedef unsigned long long mote_size;

int ops(mote_size armins_mote, mote_size *motes, int n_motes)
{
	int r = 0;
	for (int i = 0; i < n_motes; ++i)
		if (armins_mote <= motes[i])
		{
			int rr_del = n_motes - i;
			int rr_add = ops(armins_mote + armins_mote - 1, motes + i, n_motes - i) + 1;
			r += std::min(rr_add, rr_del);
			break;
		}
		else armins_mote += motes[i];
	return r;
}

int main()
{
	int test_cases;
	{
		std::string s;
		std::getline(std::cin, s);
		std::istringstream ss(s);
		ss >> test_cases;
	}

	for (int i = 0; i < test_cases; ++i)
	{
		mote_size armins_mote;
		int n_motes;
		{
			std::string s;
			std::getline(std::cin, s);
			std::istringstream ss(s);
			ss >> armins_mote >> n_motes;
		}

		mote_size motes[100];
		{
			std::string s;
			std::getline(std::cin, s);
			std::istringstream ss(s);
			std::copy_n(std::istream_iterator<mote_size>(ss), n_motes, motes);
		}

		int r = 0;
		if (armins_mote > 1)
		{
			std::sort(motes, motes + n_motes);
			r += ops(armins_mote, motes, n_motes);
		}
		else r = n_motes;

		std::cout << "Case #" << i + 1 << ": " << r << std::endl;
	}
}
