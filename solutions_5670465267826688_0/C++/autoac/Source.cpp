#include <iostream>
 #include <algorithm>
#include <set>
 #include <vector>
#include<fstream>
using namespace std;
int table[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
char s[10005];
bool k[10005] ;

int main()
{

	//ifstream file1("sample.txt");
	ifstream file1("C-small-attempt2.in");
	ofstream file2("oop.txt");
	int T,w=0;
	file1 >> T;
	for (int t = 1; t <= T;t++)
	{
		memset(k, 0, sizeof(k));
		int total, mul; bool ans = 1;
		file1 >> total >> mul;
		for (int i = 1; i <= total; i++)
		{
			file1 >> s[i];
			
		}
		int end = total*mul;
		for (int i = total + 1; i <= end; i++)
		{
			s[i] = s[i - total];
			
		}
		
		bool sign = 1; int cur = 1;
		
		for (int i = end; i;i--)
		{
			int y;
			if (s[i] == '1')
				y = 1;
			else if (s[i] == 'i')
				y = 2;
			else if (s[i] == 'j')
				y = 3;
			else
				y = 4;
			int temp = table[y][cur];
		
			sign = !((temp > 0) ^ sign);
			cur = abs(temp);
			if (sign&&(cur == 4))
				k[i] = 1;
		}sign = 1; cur = 1;
		for (int i = 1; i <= end&&ans;i++)
		{
			int y;
			if (s[i] == '1')
				y = 1;
			else if (s[i] == 'i')
				y = 2;
			else if (s[i] == 'j')
				y = 3;
			else
				y = 4;
			int temp = table[cur][y];

			sign =!( (temp > 0) ^ sign);
			cur = abs(temp);
			if (sign&&(cur ==2))
			{
				int res = 1;bool si = 1;
				for (int m = i + 1; m <= end;m++)
				{
					int yy;
					if (s[m] == '1')
						yy = 1;
					else if (s[m] == 'i')
						yy = 2;
					else if (s[m] == 'j')
						yy = 3;
					else
						yy = 4;
					int tem = table[res][yy];
					si =!( (tem > 0) ^ si);
					res = abs(tem);
					if (si&&(res == 3)&&k[m+1])
					{
						//file2 << i << ' ' << m << endl; w++;
						ans = 0; 
			
						break;
					}
				}
			}
		}
		file2 << "Case #" << t << ": ";
		if (!ans)
			file2 << "YES\n";
		else
			file2 << "NO\n";
		
	}
	return 0;
}