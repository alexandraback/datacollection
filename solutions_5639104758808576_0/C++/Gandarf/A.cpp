#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
using namespace std;

int testn;
int smax;
string s;

int main()
{
	//ifstream in("input.txt");
	ifstream in("A-small-attempt0.in");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		in >> smax;
		in >> s;

		int needFriend = 0;
		int clapping = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (clapping < i) {
				clapping++;
				needFriend++;
			}
			clapping += (s[i] - '0');
		}
			
		out << "Case #" << test << ": " << needFriend << endl;
	}

	in.close();
	out.close();
	return 0;
}