#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
using namespace std;

int testn;
int L;
long long int X;
string s;
int arr[3];

string reduced;
string table[4][4] = {"1", "i", "j", "k",
					"i", "-1", "k", "-j",
					"j", "-k", "-1", "i",
					"k", "j", "-i", "-1"};

int GetNum(char c)
{
	if (c == '1') return 0;
	else if (c == 'i') return 1;
	else if (c == 'j') return 2;
	else if (c == 'k') return 3;
}

string Calc(char c)
{
	int minusCnt = 0;
	if (reduced[0] == '-') {
		minusCnt++;
		reduced = reduced.substr(1);
	}
	char r = reduced[0];

	string val = table[GetNum(r)][GetNum(c)];

	if (val[0] == '-') {
		minusCnt++;
		val = val.substr(1);
	}

	if (minusCnt == 1)
		val = "-" + val;

	return val;
}

int main()
{
	//ifstream in("input.txt");
	ifstream in("C-small-attempt0.in");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		in >> L >> X;
		in >> s;

		// init
		reduced = s[0];
		arr[0] = arr[1] = arr[2] = 0;

		for (int i = 0; i < s.size(); ++i)
			arr[ s[i] - 'i' ] = 1;
		int alnum = arr[0] + arr[1] + arr[2];

		if (alnum <= 1)
			out << "Case #" << test << ": NO" << endl;

		else 
		{
			for (int i = 1; i < s.size(); ++i)
				reduced = Calc(s[i]);

			bool negative = (reduced[0] == '-');
			if (negative)
				reduced = reduced.substr(1);

			if (reduced != "1") {
				if (X % 2 == 0) {
					reduced = "-1";
					if (X % 4 == 0)
						reduced = "1";
				}
				else {
					out << "Case #" << test << ": NO" << endl;
					continue;
				}
			}
			
			if (X % 2 == 0 && negative)
				negative = false;
			
			if (negative) {
				if (reduced[0] == '-')
					reduced = reduced.substr(1);
				else
					reduced = "-" + reduced;
			}
			
			if (reduced == "-1")
				out << "Case #" << test << ": YES" << endl;
			else
				out << "Case #" << test << ": NO" << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}