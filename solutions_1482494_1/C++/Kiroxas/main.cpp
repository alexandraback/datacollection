#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

bool finish(vector<pair<bool,bool> >&b)
{
	for(int i = 0; i < b.size();++i)
	{
		if(b[i].second == false) return false;
	}
	return true;
}


int main()
{
	std::ifstream file("B-large.in", std::ifstream::in);
	std::ofstream file2("out2.txt", std::ofstream::out);

	int nb;
	file >> nb;

	for(int i = 0; i < nb; ++i)
	{
		int a;
		bool bo =true;
		file >> a;
		vector<pair<int,int> >f(a);
		vector<pair<bool,bool> >b(a,pair<bool,bool>(false,false));
		for(int j = 0; j< a; ++j)
		{
			file >> f[j].first;
			file >> f[j].second;
		}
		int current_stars = 0;
		int cpt = 0;
		while(!finish(b))
		{
			for(int j = 0; j < a; ++j)
			{
				if(( f[j].second <= current_stars) && (!b[j].first))
				{
					current_stars += 2;
					b[j].first = true;
					b[j].second = true;
					cpt++;
					goto end;
				}
			}

			for(int j = 0; j < a; ++j)
			{
				if(( f[j].second <= current_stars) && (!b[j].second))
				{
					current_stars += 1;
					b[j].second = true;
					cpt++;
					goto end;
				}
			}
			int ind = -1;
			int tmp = -1;
			for(int j = 0; j < a; ++j)
			{
				if(( f[j].first <= current_stars) && (!b[j].first) && (f[j].second > tmp))
				{
					ind = j;
					tmp = f[j].second;
				}
			}
			if(ind != -1)
			{
				current_stars += 1;
					b[ind].first = true;
					cpt++;
					goto end;
			}
			bo = false;
			file2 << "Case #" << i + 1 << ": " << "Too Bad" << endl;
			break;
end :
			continue;
		}
		if(bo)
		file2 << "Case #" << i + 1 << ": " << cpt << endl;

		cout << i << endl;
	}
	
}