#include <iostream>
#include <string>
//#include <Cmath>
#include <algorithm>
//#include <sstream>
#include <fstream>
//#include <vector>

using namespace std;

int main()
{
	ofstream output;
	output.open ("output01.in");
	
	int T, n, L, ans, count, Max;
	char voc[] = {'a','i','u','e','o'};
	string str, sub;
	bool cons;
	
	cin >> T;
	
	for (int i=0; i< T; ++i)
	{
		cin >> str >> n;
		ans = 0;
		for (int j=0; j< str.length(); ++j)
		{
			for (int k = 1; k <= str.length()-j; ++k)
			{
				sub = str.substr(j,k);
				count = 0;
				Max=0;
				for (int l = 0; l < sub.length(); ++l)
				{
					cons = true;
					for (int m = 0; m < 5; ++m)
					{
						if( sub[l] == voc[m] )
						{
						  cons = false;
						  break;
						}
					}
					if (cons) ++count;
					else count = 0;
					Max = max (Max, count);
					if (Max>=n) break;
				}
				if (Max>=n) ++ans;
			}
		}
		
		output << "Case #"<<i+1<<": "<<ans<< endl;
	}
	output.close();
	return 0;
}