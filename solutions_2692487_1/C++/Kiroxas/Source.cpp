#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <functional>

using namespace std;

int grow(std::vector<long long>::iterator first, std::vector<long long>::iterator last, long long size)
{
	unsigned int cpt = 0;

	for(;first != last; ++first)
	{
		while(size <= *first)
		{
			size += size -1;
			++cpt;
		}
		size += *first;
	}

	return cpt;
}

int main()
{
	std::ifstream file("A-large.in", std::ifstream::in);
	std::ofstream file2("out.txt", std::ofstream::out);

	int nb;
	file >> nb;

	for(int i = 0; i < nb; ++i)
	{
		long long my_mote, nb_mote;

		file >> my_mote;
		file >> nb_mote;
		std::vector<long long> motes(nb_mote);

		for(unsigned int j = 0; j < nb_mote; ++j)
		{
			file >> motes[j];
		}

		sort(motes.begin(),motes.end(), std::less<long long>());
		long long res = 0;

		if(my_mote == 1)
		{
			res = motes.size();
		}
		else
		{

		long long eat_all = grow(motes.begin(),motes.end(),my_mote);

		for(std::vector<long long>::iterator it = motes.begin(), end = motes.end(); it != end; ++it)
		{
			if(*it < my_mote)
			{
				my_mote += *it; // Size will increase
				if(my_mote > *(end -1)) break;
			}
				 
			else
			{
				if(eat_all > end - it)
				{
					res += end - it;
					break;
				}
				else
				{
				//should we increase or not
					long long tmp = my_mote;
					long long cpt = 0;

					while(tmp <= *it)
					{
						tmp += tmp -1;
						++cpt;
					}

					my_mote = tmp + *it;
					res += cpt; 
					eat_all -= cpt;
				}
			
			}
		}
		}

		file2 << "Case #" << i + 1 << ": " << res << std::endl;
	}
}