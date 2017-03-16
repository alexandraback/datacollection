#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string Answer(int x, int y)
{
	string ans = "";

	int absx = abs(x);
	int absy = abs(y);
	int tempx = 0;
	int tempy = 0;
	if(absx < absy)
	{
		int i = 1;
		int j = 1;
		for(i=1; i < 10000; ++i)
		{
			if(absx > tempx)
			{
				tempx += i;
				ans += "E";
			}
			else
			{
				break;
			}
		}
		for(j=i; j < 10000; ++j)
		{
			if(absy > tempy)
			{
				tempy += j;
				ans += "N";
			}
			else
			{
				break;
			}
		}

		for(int k = 1; k <= tempx - absx; ++k)
		{
			ans += "EW";
		}
		for(int m = 1; m <= tempy - absy; ++m)
		{
			ans += "NS";
		}
	}
	else
	{
		int i = 1;
		int j = 1;
		for(j=1; j < 10000; ++j)
		{
			if(absy > tempy)
			{
				tempy += j;
				ans += "N";
			}
			else
			{
				break;
			}
		}
		for(i=j; i < 10000; ++i)
		{
			if(absx > tempx)
			{
				tempx += i;
				ans += "E";
			}
			else
			{
				break;
			}
		}

		for(int k = 1; k <= tempx - absx; ++k)
		{
			ans += "EW";
		}
		for(int m = 1; m <= tempy - absy; ++m)
		{
			ans += "NS";
		}
	}
	
	if(x<0)
	{
		for(int i=0; i<ans.length();++i)
		{
			if(ans[i] == 'E')
			{
				ans[i] = 'W';
			}
			else if(ans[i] == 'W')
			{
				ans[i] = 'E';
			}
		}
	}

	if(y<0)
	{
		for(int i=0; i<ans.length();++i)
		{
			if(ans[i] == 'N')
			{
				ans[i] = 'S';
			}
			else if(ans[i] == 'S')
			{
				ans[i] = 'N';
			}
		}
	}

	return ans;
}

int main()
{
	int probNum = 0;
	// Problem Num
	cin >> probNum;

	for(int i = 1; i <= probNum; ++i)
	{
		int x=0,y=0;
		cin >> x >> y;
		cout << "Case #" << i << ": " << Answer(x,y) << endl;
	}
}