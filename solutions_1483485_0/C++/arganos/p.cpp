/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

fstream out;

int main()
{
	fstream in("in.txt", ios_base::in);
	out.open("out.txt", ios_base::out);

	int t;
	char map[27] = "yhesocvxduiglbkrztnwjpfmaq", buf[10000];
		
	in >> t;
	in.getline(buf, 10);
	for (int i = 0; i < t; i++) {
		in.getline(buf, 1000);
		
		int j = 0;
		while (buf[j]) {
			if (buf[j] != ' ')
				buf[j] = map[buf[j]-'a'];
			j++;
		}
		cout << "Case #" << i+1 << ": " << buf << endl;
	}
	
	
	return 0;
}

