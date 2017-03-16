#include<iostream
#include<vector>

namespace codejam
{
	bool is_Pallindrome(unsigned long long x)
	{
		unsigned long long res = x;
		unsigned long long che = 0;
		while(res > 0)
		{
			che = che*10 + res%10;
			res = res/10;
		}
		return che == x;
	}

	void fairandsquare_small()
	{
		int cases;
		std::cin>>cases;

		std::vector<int> pallindromic_squares;
		for(int i = 1; i <= 100000; i++)
		{
			int sqrt = std::pow(i,0.5);
			if(sqrt*sqrt != i)
				continue;
			if(is_Pallindrome(i) && is_Pallindrome(sqrt))
				pallindromic_squares.push_back(i);
		}

		for(int cs = 1; cs <= cases; cs++)
		{
			unsigned long long a, b;
			std::cin>>a>>b;
			int i = 0;
			while(pallindromic_squares[i] < a)
				i++;
			//if(i) i--;
			int count = 0;
			while(pallindromic_squares[i] <= b)
			{
				std::cout<<pallindromic_squares[i]<<"\t";
				count++;
				i++;
			}
			std::cout<<"Case #"<<cs<<": "<<count<<std::endl;
		}
	}
}

int main()
{

	

	codejam::fairandsquare_small();

	return 0;
}
