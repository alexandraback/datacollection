#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

char mul(char a, char b, bool &sign)
{
	// a,b \in {1,i,j,k}
	
	if (a == '1')	return b;
	if (b == '1')	return a;


	// a,b \in {i,j,k}
	if (a == 'i')
	{
		if (b == 'i')
		{
			sign = !sign; return '1';
		}
		else if (b == 'j')
		{
			return 'k';
		}
		else
		{
			sign = !sign; return 'j';
		}
	}
	else if (a == 'j')
	{
		if (b == 'i')
		{
			sign = !sign; return 'k';
		}
		else if (b == 'j')
		{
			sign = !sign; return '1';
		}
		else
		{
			return 'i';
		}
	}
	else  // a = k
	{
		if (b == 'i')
		{
			return 'j';
		}
		else if (b == 'j')
		{
			sign = !sign; return 'i';
		}
		else
		{
			sign = !sign; return '1';
		}

	}
}



int main()
{
	ofstream outfile("D:\\codejam\\2015\\Clarge.txt");
	ifstream infile("D:\\codejam\\2015\\testcase.txt");

	int T;

	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		long long L;
		long long X;
		string s;
		char totalprod = '1';
		char currentprod = '1';
		bool current_positive = true;
		bool total_positive = true;
		bool positive = true;
		char prod;
		string ans = "YES";


		infile >> L >> X >> s;

		// cout << s << endl;

		prod = s[0];
		for (int i = 1; i < L; i++)
			prod = mul(prod, s[i], positive);

		int Xmodfour = X % 4;
		
		
		for (int i = 0; i < Xmodfour; i++)
			totalprod = mul(totalprod, prod, total_positive);
		if (Xmodfour % 2)		// Xmodfour is odd
		{
			if (!positive)
				total_positive = !total_positive;
		}

		if ((totalprod != '1') || (total_positive))
			ans = "NO";
		else   // total product is -1
		{
			int index = 0;
			currentprod = s[index];
			while (index < min(4 * L, X*L - 1))
			{
				if (currentprod == 'i' && current_positive)
					break;
				else
				{
					index++;
					currentprod = mul(currentprod, s[index % L], current_positive);
				}
			}
			if (index == min(4*L, X*L-1))	{ ans = "NO"; }
			else  // s_1 * ... * s_index = i
			{
				
				int index2 = index + 1;
				currentprod = s[index2 % L];
				current_positive = true;

				while (index2 < min(X*L - 1, index + 4 * L))
				{
					if (currentprod == 'j' && current_positive)
						break;
					else
					{
						index2++;
						currentprod = mul(currentprod, s[index2 % L], current_positive);
					}
				}
				if (index2 == min(X*L - 1, index + 4 * L))	{ ans = "NO"; }
				
			}
			
		}
		outfile << "Case #" << casenum << ": "  << ans << endl;

	}

	infile.close();
	outfile.close();

	cin.get();
	return 0;
}