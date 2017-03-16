#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;


int main()
{
	std::ifstream file("A-large.in", std::ifstream::in);
	std::ofstream file2("out2.txt", std::ofstream::out);

	int nb;
	file >> nb;

	for(int i = 0; i < nb; ++i)
	{
		int a,b;
		file >> a;
		file >> b;
		vector<double> f(a);
		double chance = 1;
		vector<pair<double,double> > ch(a);
		vector<double> res(a);
		//int pow = 1;

		for(int j = 0; j < a; j++)
		{
			double tmp;
			file >> tmp;
			f[j] = tmp;
			chance *= f[j];
			ch[j].first = 1;
			ch[j].second = 1;
			//pow *= 10;
			if(j ==0)
			{
				ch[j].first *= f[j];
				ch[j].second =/* pow -*/1 - ch[j].first;
			}
			else
			{	
				ch[j].first = ch[j-1].first * f[j];
				ch[j].second = /*pow -*/1 - ch[j].first;
			}

			int win = ((b-a +1)+2*(a-(j+1)));
			int lose = ((b-a+1)+b+1+2*(a-(j+1)));
			res[j] = ((ch[j].first * win) + (ch[j].second * lose));// pow;
			
		}

		int backspace_right = 2 +b;
		int pure_back = a + b + 1;
	
		res.push_back(backspace_right);
		res.push_back(pure_back);

		vector<double>::iterator it = std::min_element(res.begin(), res.end());

	
		file2 << "Case #" << i + 1 << ": " << fixed << setprecision(6) << *it << endl;

	}
	
}