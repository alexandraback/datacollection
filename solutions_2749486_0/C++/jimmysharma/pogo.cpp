#include<iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int T, c=1;
	ofstream myfile;
	myfile.open ("3B-small.out");
	scanf("%d", &T);
	while(T--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		char d;
		string ans="";

		int i = 1;

		while(x || y)
		{
			if(abs(x) > abs(y))
			{
				if(abs(x)-i >= 0)
				{
					if(x > 0)
					{
						x -= i;
						ans.push_back('E');
					}
					else
					{
						x += i;
						ans.push_back('W');
					}
				}
				else
				{
					if(x > 0)
					{
						x += i;
						ans.push_back('W');
					}
					else
					{
						x -= i;
						ans.push_back('E');
					}
				}
			}
			else if(y != 0)
			{

				if(abs(y)-i >= 0)
				{
					if(y > 0)
					{
						y -= i;
						ans.push_back('N');
					}
					else
					{
						y += i;
						ans.push_back('S');
					}
				}
				else
				{
					if(y > 0)
					{
						y += i;
						ans.push_back('S');
					}
					else
					{
						y -= i;
						ans.push_back('N');
					}
				}
			}
			cout << "i = " << i << " x = " << x << " y = " << y << " ans = " << ans << endl;
			//scanf("%c", &d);
			i++;
		}




		myfile << "Case #"<< c << ": " << ans << endl;
		cout << "Case #"<< c << ": " << ans << endl;
		c++;
	}
	return 0;
}
