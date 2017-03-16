#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
//#define DEBUG

const int BUFSIZE = 2 * 1024 * 1024;

int  processOneCase(ifstream &ifs)
{
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	string str;
	int len;
	iss >> str>> len;

	vector<int> vec;
	vector<int> pos;
	int start = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'a' ||
			str[i] == 'e' ||
			str[i] == 'i' ||
			str[i] == 'o' ||
			str[i] == 'u')	
		{
			if (i - start >= len)
			{
				vec.push_back(i - start);
				pos.push_back(start);
			}
			start = i+1;
		}
	}
	if (str.size() - start >= len)
	{
		vec.push_back(str.size() - start);
		pos.push_back(start);
	}

	int count = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		int right = (i == vec.size() - 1) ? str.size() : pos[i+1] + len - 1;
		int right2 = right - (pos[i] + vec[i] );
		int len2 = vec[i] - len + 1;
//		cout << vec[i] << ' ' << pos[i] <<  ' ' << right <<  ' ' << right2 <<  ' ' << len2 << endl;
		count += (vec[i] - len + 1) * (right - vec[i]);
		count += len2 * (len2 + 1) / 2;
		count += pos[i] * right2;
	}

	return count;
}

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	int lines = atoi(buf);

	for (int i = 0; i < lines; i++)
	{   
		int result = processOneCase(ifs); 
		cout << "Case #" << (i+1) << ": " << result  << endl;
	}   
	return 0;
}
