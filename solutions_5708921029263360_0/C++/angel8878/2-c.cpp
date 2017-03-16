#include<string>
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main(void)
{
	ifstream file;
	file.open("C-small-attempt2.in");
	ofstream output;
	output.open("result.out");

	int caseNo;
	file >> caseNo;

	for (int c = 1; c <= caseNo; c++)
	{
		int j, p, s, k;
		file >> j >> p >> s >> k;
		int cc, ccc, cccc;

		output << "Case #" << c << ": ";

		//int max = j * p * s;

		if (s <= k)
		{
			output << j*p*s << "\n";
			for (cc = 1; cc <= j; cc++)
			{
				for (ccc = 1; ccc <= p; ccc++)
				{
					for (cccc = 1; cccc <= s; cccc++)
					{
						output << cc << " " << ccc << " " << cccc << "\n";
					}
				}
			}
		}
		else if (p <= k)
		{
			output << j*p*k << "\n";
			for (cc = 1; cc <= j; cc++)
			{
				for (ccc = 1; ccc <= p; ccc++)
				{
					for (cccc = 1; cccc <= k; cccc++)
					{
						output << cc << " " << ccc << " " << cccc << "\n";
					}
				}
			}
		}
		else if (j <= k)
		{
			if ((p-k)*k > (p-k)*(s-k))
				output << j*k*k + (p - k)*(s-k) << "\n";
			else
				output << j*k*k + (p - k)*k << "\n";
			for (cc = 1; cc <= j; cc++)
			{
				for (ccc = 1; ccc <= k; ccc++)
				{
					for (cccc = 1; cccc <= k; cccc++)
					{
						output << cc << " " << ccc << " " << cccc << "\n";
					}
				}
				int count = 1;
				for (ccc = k + 1; ccc <= p; ccc++)
				{
					for (cccc = ccc; cccc <= s; cccc++)
					{
						output << cc << " " << ccc << " " << cccc << "\n";
						count++;
						if (count > k)
							break;
					}
				}
			}
		}
		else
		{
			output << j*p << "\n";
			int roll = 0;
			for (cc = 1; cc <= j; cc++)
			{
				for (ccc = 1; ccc <= p; ccc++)
				{
					if (roll + ccc <= s)
						output << cc << " " << ccc << " " << roll + ccc << "\n";
					else 
						output << cc << " " << ccc << " " << roll + ccc - s << "\n";
				}
				roll++;
			}
		}
	}
}