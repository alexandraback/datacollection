// CodeJam2015_1B.cpp : Defines the entry point for the console application.
//

#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>
#include <iomanip>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)





void rec(vector<int>& data, vector<bool>& num, int pos, int sum)
{
	
	if (sum >= num.size()) return;
	if (num[sum]) return;
	
	if (sum != 0) num[sum] = true;



	for (int i = pos; i < data.size(); ++i)
	{
		int newSum = sum + data[i];
		rec(data, num, i + 1, newSum);
	}
}

int main(int argc, char* argv[])
{
	int T; 
	fstream cin("input.txt");
	fstream cout("out.txt", fstream::out);
	cin >> T;
	

	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;

		int c,d,v;
		cin >> c >> d >> v;
		
		vector<int> data(d);
		vector<bool> num(v + 1, false);
		F2(i, data)
		{
			cin >> data[i];
		}

		rec(data, num, 0, 0);
		int res = 0;
		if(!num[1])
		{
			data.push_back(1);
			res++;
			F2(i, num) num[i] = false;
			rec(data, num, 0, 0);
		}

		

		bool exit = false;
		while (!exit)
		{
			exit = true;
			for (int i = 0; i < num.size() - 1; ++i)
			{
				if (num[i] && !num[i + 1])
				{
					if (exit)
					{
						res++;
					}
					exit = false;
					data.push_back(i + 1);	
				}
			}
			F2(i, num) num[i] = false;
			rec(data, num, 0, 0);
		}
		
		cout <<  "Case #" << t + 1 << ": " << (res) << endl;
	}
	return 0;
}