#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream input("A-large.in");
ofstream output("output.txt");
//下标表示害羞指数
//数组元素表示害羞指数对应的人数

int main()
{
	int T; input >> T;
	string str;
	int smax;
	int store[1001];
	int DaoHuoSuo;
	int count;
	int currentyaoqing;
	for (int i = 1; i <= T; i++)
	{
		count = 0;
		input >> smax;
		input >> str;
		for (int j = 0; j <= smax; j++)
			store[j] = str[j] - '0';
		DaoHuoSuo = store[0];
		for (int k = 1; k <= smax; k++)
		{
			if (store[k] == 0)
				continue;
			if (DaoHuoSuo < k)
			{
				currentyaoqing = k - DaoHuoSuo;
				count += currentyaoqing;
				DaoHuoSuo += currentyaoqing;
			}
			DaoHuoSuo += store[k];
		}
		output << "Case #" << i << ": " << count << endl;
	}
	return 0;
}