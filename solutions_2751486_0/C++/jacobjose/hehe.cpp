// hehe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "windows.h"
#include <set>
#include <map>

using namespace std;


typedef unsigned __int64 uint64_t;


std::set<char> check;

uint64_t getstatus(std::string name, int n, uint64_t count, int index) {
	if (index == name.size()) return count;
	unsigned int match = 0;
	bool done = false;
	int i = index;
	for (i = index; i < name.size(); i++) {
		if (check.find(name[i]) != check.end())
			match=0;
		else
			match++;
		if (match == n) {
			done = true;
			break;
		}
	}
	if (true == done) {
		if (name.size() > i)
			count += name.size()-i;
	}
	return getstatus(name, n, count, index+1);
}


int _tmain(int argc, _TCHAR* argv[])
{
	check.insert('a');
	check.insert('e');
	check.insert('i');
	check.insert('o');
	check.insert('u');
	unsigned int T = 0;
	cin >> T;
	for (int x = 0; x < T; ++x) {
		std::string name;
		cin >> name;
		unsigned int n = 0;
		cin >> n;
		cout << "Case #" << x+1 << ": " << getstatus(name, n, 0, 0) << std::endl;
	}


	return 0;
}

