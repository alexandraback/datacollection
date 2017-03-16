#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	ifstream file("B-small-attempt5.in");
	ofstream ofile("res.out");
	int tests;
	file >> tests;

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);

	for(int i =0; i < tests; ++i)
	{
		double keyboardL, length, tWlength;
		std::string keyboard, target;

		file >> keyboardL;
		file >> tWlength;
		file >> length;

		file >> keyboard;
		file >> target;

		//std::sort(keyboard.begin(),keyboard.end());
		bool cant = false;
		for(auto& c : target)
		{
			if(std::find(keyboard.begin(), keyboard.end(),c) == keyboard.end())
			{
				cant = true;
				break;
			}
		}

		double res = 0.0;
		
		if(!cant)
		{

			//let's find repetitions
			int smallest_sub = target.size();
			auto it = target.begin();
			while(it != target.end())
			{
				auto it2 = std::find(it+1,target.end(),*target.begin());
				bool good = true;
				if(it2 != target.end())
				{
					auto tmp = it2;
					auto tmp_b = it;
					good = true;
					
					while(++tmp != target.end())
					{
						++tmp_b;
						if(*tmp_b != *tmp) 
						{
							good = false;
							break;
						}
					}
					if(good)
					{
						smallest_sub = std::distance(it2,target.end());
						break;
					}
				}
				it = it2; 
			}
			
			//int banana_to_bring = length - tWlength + 1;
			int real_banana = (length - (tWlength - smallest_sub)) / smallest_sub;
			//real_banana += (length - tWlength * real_banana) / smallest_sub;

			double chance_to_type_word = 1.0;
			double chance_to_type_subword = 1.0;
			for(auto c : target)
			{
				auto coun = std::count(keyboard.begin(),keyboard.end(),c);
				chance_to_type_word *= (coun / keyboardL);
			}
			for(auto it = target.end() - smallest_sub; it != target.end(); ++it)
			{
				auto coun = std::count(keyboard.begin(),keyboard.end(),*it);
				chance_to_type_subword *= ((double)coun / keyboardL);
			}
			double chance_sub = chance_to_type_subword * (real_banana - 1);
			double chance = chance_to_type_word  + chance_sub ;
			res = real_banana - chance;
		}


		ofile << "Case #" << i + 1 << ": " << res << endl;
	}


	return 0;
}
