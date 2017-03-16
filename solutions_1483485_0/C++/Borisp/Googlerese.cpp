#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	string inputs[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string outputs[] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
	map<char, char> m;
	m['z'] = 'q';
	m['q'] = 'z';
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < inputs[i].size(); k++)
		{
			m[inputs[i][k]] = outputs[i][k];
		}
	}
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	string str;
	getline(cin, str);
	for (int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			str[i] = m[str[i]];
		}
		cout << str << endl;
	}
	return 0;
}
