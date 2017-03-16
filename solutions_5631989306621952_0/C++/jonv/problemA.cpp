//#include <stdio.h>
#include <iostream>
#include <string>
#define ll long long
using namespace std;

//typedef vector<int> vi;


int main()
{
	int T, nt;
	cin >> T;
	nt = 0;
	while(nt < T)
	{
		string word;
		cin >> word;
		//vector<char> vchar(word.begin(), word.end());
		string res(1,word.at(0));
		//cout << res << endl;
		int N = word.size();
		int i = 0;
		for (string::iterator it = word.begin(); it != word.end(); ++it)
		{
			if (i > 0) {
				if (*it >= res[0])
					res = *it + res;
				else
					res = res + *it;
			}
			i++;
		}
		nt++;
		cout << "Case #" << nt << ": " << res << endl;
	}
}