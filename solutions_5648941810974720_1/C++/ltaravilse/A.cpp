#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),e.end()

string numbers(vector<int> vec)
{
	string st = "";
	forn(i,10)
	forn(j,vec[i])
		st += ('0'+i);
	return st;
}

int main()
{
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
		string st;
		cin >> st;
		vector<int> cant(26,0);
		forn(i,st.size())
			cant[st[i]-'A']++;
		vector<int> vec(10,0);
		vec[0] = cant['Z'-'A'];
		cant['Z'-'A'] -= vec[0];
		cant['E'-'A'] -= vec[0];
		cant['R'-'A'] -= vec[0];
		cant['O'-'A'] -= vec[0];
		vec[6] = cant['X'-'A'];
		cant['S'-'A'] -= vec[6];
		cant['I'-'A'] -= vec[6];
		cant['X'-'A'] -= vec[6];
		vec[2] = cant['W'-'A'];
		cant['T'-'A'] -= vec[2];
		cant['W'-'A'] -= vec[2];
		cant['O'-'A'] -= vec[2];
		vec[4] = cant['U'-'A'];
		cant['F'-'A'] -= vec[4];
		cant['O'-'A'] -= vec[4];
		cant['U'-'A'] -= vec[4];
		cant['R'-'A'] -= vec[4];
		vec[3] = cant['R'-'A'];
		cant['T'-'A'] -= vec[3];
		cant['H'-'A'] -= vec[3];
		cant['R'-'A'] -= vec[3];
		cant['E'-'A'] -= vec[3];
		cant['E'-'A'] -= vec[3];
		vec[8] = cant['H'-'A'];
		cant['E'-'A'] -= vec[8];
		cant['I'-'A'] -= vec[8];
		cant['G'-'A'] -= vec[8];
		cant['T'-'A'] -= vec[8];
		cant['H'-'A'] -= vec[8];
		vec[1] = cant['O'-'A'];
		cant['O'-'A'] -= vec[1];
		cant['N'-'A'] -= vec[1];
		cant['E'-'A'] -= vec[1];
		vec[7] = cant['S'-'A'];
		cant['S'-'A'] -= vec[7];
		cant['E'-'A'] -= vec[7];
		cant['V'-'A'] -= vec[7];
		cant['E'-'A'] -= vec[7];
		cant['N'-'A'] -= vec[7];
		vec[5] = cant['F'-'A'];
		cant['F'-'A'] -= vec[5];
		cant['I'-'A'] -= vec[5];
		cant['V'-'A'] -= vec[5];
		cant['E'-'A'] -= vec[5];
		vec[9] = cant['I'-'A'];
		cant['N'-'A'] -= vec[9];
		cant['I'-'A'] -= vec[9];
		cant['N'-'A'] -= vec[9];
		cant['E'-'A'] -= vec[9];
		cout << "Case #"<<casito <<": "<< numbers(vec) <<endl;
	}
}