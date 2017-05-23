#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

#define mp make_pair
#define pb push_back 
#define fi(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define ll long long
#define itt ::iterator it = 

ifstream in;
ofstream out;

int main()
{
	int n;

	in.open("input.in");
	out.open("output.txt");
	in >> n;
	for (int g = 1; g <= n; g++)
	{
		bool isMono = true;
		int count = 0;
		string s;
		in >> s;

		if (s[0] == '-') count++;
		//if (s[s.length()] == '+') count -= 2;

		fi(s.length())
		{
			if (i == 0) continue;
			if (s[i] == '-' && s[i - 1] == '+')
			{
				count += 2;
				isMono = false;
			}
		}

		/*if (isMono)
		{
			if (s[0] == '-') count = 1;
			else count = 0;
		}*/
		out << "Case #" << g << ": " << count << endl;
	}
	out.close();
	in.close();
	return 0;
}

