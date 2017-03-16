#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int n;
	int x,y;
	ifstream ist("input1.in");
	ofstream ost("output1.in");
	ist>>n;
	for (int i = 1;i<=n;i++)
	{
		ist >>x >>y;
		int xx = 0;
		string  ans = "";
		int yy = 0;
		int steps = 1;
		if (x > 0) 
		{	while (xx + steps <=x) {xx += steps;steps++;ans += 'E';}
				if (xx!=x)
					for (int i1 = xx+1;i1<=x;i1++)
					{ans += "WE";steps+=2;}
		}
		if (x < 0) 
		{	while (xx - steps >=x) {xx -= steps;steps++;ans += 'W';}
				if (xx!=x)
					for (int i1 = xx-1;i1>=x;i1--)
						{ans += "EW";steps+=2;}
		}
		if (y > 0)
		{
			while (yy + steps <=y) {yy += steps;steps++;ans += 'N';}
				if (yy!=y)
					for (int i1 = yy+1;i1<=y;i1++)
					{ans += "SN";steps+=2;}
		}
		if (y < 0)
		{
			while (yy - steps >=y) {yy -= steps;steps++;ans += 'S';}
				if (yy!=y)
					for (int i1 = yy-1;i1>=y;i1--)
					{ans += "NS";steps+=2;}
		}
		ost<<"Case #"<<i<<": "<<ans<<endl;
	}
	ist.close();
	ost.close();
}