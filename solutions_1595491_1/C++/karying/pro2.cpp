#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("ans.out");

	int t , n , s , p;
	int data[150];
	int ans = 0;
	int remain[150][2];
	int isuse[150];
	int temp;
	while (input>>t)
	{
		for (int i = 0;i<t;i++)
		{
			ans = 0;
			input>>n>>s>>p;
			memset(isuse , 0 ,sizeof(isuse));
			memset(remain , 0 ,sizeof(remain));
			for (int j =0;j<n;j++)
			{
				input>>data[j];
				if (data[j] == 0)
				{
					remain[j][0]=remain[j][1]=0;
					continue;
				}
				
				temp = data[j]%3;
				isuse[j] = 0;
				if (temp == 0)
				{
					remain[j][0] = data[j]/3;
					remain[j][1] = data[j]/3+1;
				}
				else if (temp == 1)
				{
					remain[j][0] = data[j]/3+1;
					remain[j][1] = data[j]/3+1;
				}
				else if (temp == 2)
				{
					remain[j][0] = data[j]/3+1;
					remain[j][1] = data[j]/3+2;
				}
			}
			for (int j =0;j<n;j++)
			{
				if ((remain[j][1]>=p) && (remain[j][0] < p) && (ans < s))
				{
					isuse[j] = 1;
					ans ++;
				}
			}
			for (int j =0;j<n;j++)
			{
				if ((remain[j][0] >= p) && (isuse[j] == 0))
				{
					isuse[j] = 1;
					ans ++;
				}
			}
			output<<"Case #"<<i+1<<": "<<ans<<endl;
		}
		
	}
	return 1;
}
