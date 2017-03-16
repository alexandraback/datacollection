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

	long long next_pallindrome(unsigned long long x, bool oddlength)
	{
		static int base = 10;
		long long res = x;
		if(oddlength)
			x = x/base;
		while(x > 0)
		{
			res = base * res + x % base;
			x = x/base;
		}
		return res;
	}

	void fairandsquare_large()
	{
		int cases;
		std::cin>>cases;
		std::set<long long> pallindromic_squares;
		long long x = 1;
		for(;x < 100000000;x++)
		{
			long long p = next_pallindrome(x,true);
			if(p < 0)
				break;
			int temp = p%10;
			if(temp == 2 || temp == 3 || temp == 7 || temp == 8 || temp == 0)
				continue;
			long long sqrt = std::pow(p,0.5);
			temp = sqrt%10;
			if(temp == 0 || temp > 3)
				continue;
			if(sqrt*sqrt == p && is_Pallindrome(sqrt))
				pallindromic_squares.insert(p);
		}
		x = 1;
		for(;x < 100000000;x++)
		{
			long long p = next_pallindrome(x,false);
			if(p < 0)
				break;
			int temp = p%10;
			if(temp == 2 || temp == 3 || temp == 7 || temp == 8 || temp == 0)
				continue;
			long long sqrt = std::pow(p,0.5);
			temp = sqrt%10;
			if(temp == 0 || temp > 3)
				continue;
			if(sqrt*sqrt == p && is_Pallindrome(sqrt))
				pallindromic_squares.insert(p);
		}
		//std::cout<<pallindromic_squares.size();
		long long* arr = new long long[pallindromic_squares.size()];
		int i = 0;
		for(std::set<long long>::iterator it = pallindromic_squares.begin(); it != pallindromic_squares.end(); it++,i++)
			arr[i] = (*it);

		for(int cs = 1; cs <= cases; cs++)
		{
			unsigned long long a,b;
			std::cin>>a>>b;
			int i = 0;
			while(arr[i] < a)
				i++;
			int count = 0;
			while(arr[i] <= b)
			{
				count++;
				i++;
			}
			std::cout<<"Case #"<<cs<<": "<<count<<std::endl;
		}
	}
}

int main()
{

	

	codejam::fairandsquare_large();

	return 0;
}
