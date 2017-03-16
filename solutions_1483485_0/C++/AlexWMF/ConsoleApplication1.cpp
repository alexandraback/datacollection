// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>


using std::cout;
using std::endl;
using std::string;
using std::map;
using std::cin;
static string abc;
static map<char, char> replacements;

string repl(const string& s)
{
	string rez;
	for (unsigned i = 0; i < s.length(); ++i)
	{
		rez += replacements[s[i]];
	}
	return rez;
}

void makeAbc()
{
	char c = 'a';

	while (true)
	{
		if (c > 'z')
			break;
		abc += c;
		++c;
	}
}

void diff(const string& a, const string& b)
{
	for (unsigned i = 0; i < a.length(); ++i)
	{
		cout << b[i] - a[i] << ' ';
	}
	cout << endl;
}

void initRepl(const string&dec, const string enc)
{
	for (unsigned i = 0; i < dec.length(); ++i)
	{
		replacements[dec[i]] = enc[i];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	makeAbc();

	const string a0 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	const string a1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	const string a2 = "de kr kd eoya kw aej tysr re ujdr lkgc jvzq";


	const string b0 = "our language is impossible to understand";
	const string b1 = "there are twenty six factorial possibilities";
	const string b2 = "so it is okay if you want to just give upqz";

	initRepl(a0, b0);
	initRepl(a1, b1);
	initRepl(a2, b2);

	unsigned count(0);
	cin >> count;
	string s;
	unsigned i = 0;
	while (true)
	{
		std::getline(cin, s);
		if (s.empty())
			continue;

		cout << "Case #" << i + 1 << ": " << repl(s) << endl;
		++i;
		if (i >= count)
			break;
	}


	return 0;
}

