#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned long long ull;

ull diff(string s1, string s2)
{
	ull x1 = stoull(s1);
	ull x2 = stoull(s2);
	if (x1 > x2)
		return x1 - x2;
	else
		return x2 - x1;
}

pair<string, string> solve(string c, string j)
{
	if (c == j && c.length()==1&&c=="?")
		return make_pair("0", "0");

	if (c == j && c.length() == 1 && c != "?")
		return make_pair(c, j);

	if (c[0] != '?'&&j[0] != '?')
	{
		if (c[0] == j[0])
		{
			pair<string, string> res = solve(c.substr(1, c.length() - 1), j.substr(1, j.length() - 1));
			res.first = c[0] + res.first;
			res.second = j[0] + res.second;
			return res;
		}
		else
		{
			if (c[0] < j[0])
			{
				for (int i = 1; i < c.length(); ++i)
				{
					if (c[i] == '?')
						c[i] = '9';
					if (j[i] == '?')
						j[i] = '0';
				}
			}
			else
			{
				for (int i = 1; i < c.length(); ++i)
				{
					if (c[i] == '?')
						c[i] = '0';
					if (j[i] == '?')
						j[i] = '9';
				}
			}
			return make_pair(c, j);
		}
	}
	else if (c[0] == '?' && j[0] == '?')
	{
		ull di = ULLONG_MAX;
		int index;
		pair<string, string> res[3];
		res[0] = solve('0' + c.substr(1, c.length() - 1), '0' + j.substr(1, j.length() - 1));
		res[1] = solve('0' + c.substr(1, c.length() - 1), '1' + j.substr(1, j.length() - 1));
		res[2] = solve('1' + c.substr(1, c.length() - 1), '0' + j.substr(1, j.length() - 1));

		for (int i = 0; i<3; ++i)
		{
			if (di > diff(res[i].first, res[i].second))
			{
				index = i;
				di = diff(res[i].first, res[i].second);
			}
			else if (di == diff(res[i].first, res[i].second))
			{
				if (res[i].first < res[index].first)
				{
					index = i;
				}
				else if (res[i].first == res[index].first)
				{
					if (res[i].second < res[index].second)
					{
						index = i;
					}
				}
			}
		}

		pair<string, string> ress = res[index];
		/*if (index!=2)
			ress.first = '0' + ress.first;
		else
			ress.first = '1' + ress.first;

		if (index != 1)
			ress.second = '0' + ress.second;
		else
			ress.second = '1' + ress.second;*/
		return ress;

	}
	else if (c[0] == '?')
	{
		ull di = ULLONG_MAX;
		int index = 0;
		pair<string, string> res[3];
		res[0] = solve(j[0] + c.substr(1, c.length() - 1), j);
		di = diff(res[0].first, res[0].second);

		if (j[0] > '0')
		{
			res[1] = solve(((char)(j[0] - 1)) + c.substr(1, c.length() - 1), j);
			ull di1 = diff(res[1].first, res[1].second);

			if (di1 < di)
			{
				di = di1;
				index = 1;
			}
			else if (di1 == di)
			{
				if (res[1].first < res[index].first)
				{
					index = 1;
				}
				else if (res[1].first == res[index].first)
				{
					if (res[1].second < res[index].second)
					{
						index = 1;
					}
				}
			}
		}

		if (j[0] < '9')
		{
			res[2] = solve(((char)(j[0] + 1)) + c.substr(1, c.length() - 1), j);
			ull di1 = diff(res[2].first, res[2].second);

			if (di1 < di)
			{
				di = di1;
				index = 2;
			}
			else if (di1 == di)
			{
				if (res[2].first < res[index].first)
				{
					index = 2;
				}
				else if (res[2].first == res[index].first)
				{
					if (res[2].second < res[index].second)
					{
						index = 2;
					}
				}
			}
		}
		

		return res[index];
	}
	else //j[0]=='?'
	{

		ull di = ULLONG_MAX;
		int index = 0;
		pair<string, string> res[3];
		res[0] = solve(c, c[0] + j.substr(1, c.length() - 1));
		di = diff(res[0].first, res[0].second);

		if (c[0] > '0')
		{
			res[1] = solve(c, ((char)(c[0] - 1)) + j.substr(1, c.length() - 1));
			ull di1 = diff(res[1].first, res[1].second);

			if (di1 < di)
			{
				di = di1;
				index = 1;
			}
			else if (di1 == di)
			{
				if (res[1].first < res[index].first)
				{
					index = 1;
				}
				else if (res[1].first == res[index].first)
				{
					if (res[1].second < res[index].second)
					{
						index = 1;
					}
				}
			}
		}

		if (c[0] < '9')
		{
			res[2] = solve(c, ((char)(c[0] + 1)) + j.substr(1, c.length() - 1));
			ull di1 = diff(res[2].first, res[2].second);

			if (di1 < di)
			{
				di = di1;
				index = 2;
			}
			else if (di1 == di)
			{
				if (res[2].first < res[index].first)
				{
					index = 2;
				}
				else if (res[2].first == res[index].first)
				{
					if (res[2].second < res[index].second)
					{
						index = 2;
					}
				}
			}
		}


		return res[index];
	}
}


int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	//	FILE * input;
	//	input = fopen("input.txt","r");

	int T;

	//	fread(&n, sizeof(int), 1, input);cout<<n<<endl; char cc=getchar();

	input >> T;// cout<<n<<endl;
	//cin >> T;

	string C,J, Cans,Jans;

	int n;

	//string ans;
	int len;
	for (int t = 0; t < T; ++t)
	{
		input >> C >> J;

		Cans = C;
		Jans = J;

		len = C.length();

		/*for (int i = 0; i < len; ++i)
		{
			if (C[)
		}*/

		//if (C[0] == J[0] && C[0] == '?')
			//Cans[0] = Jans[0] = '0';

		pair<string, string> res = solve(C, J);
		

		output << "Case #" << t + 1 << ": ";
		output << res.first << ' ' << res.second;

		output << endl;

		//cout << ans;

	}
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
