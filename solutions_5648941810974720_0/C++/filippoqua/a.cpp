#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

const double PI = 3.1415926535;

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int quantita[26],t,quantita2[10];
	string s;
	in >> t;
	for(int i=0; i<t; i++)
	{
		for(int j=0; j<26; j++)
			quantita[j] = 0;
		for(int j =0; j<10; j++)
			quantita2[j] = 0;
		in >> s;
		for(int j=0; j<(int)s.length(); j++)
			quantita[s[j]-'A']++;
		// Z -> Zero
		quantita2[0] = quantita['Z'-'A'];
		for(int j=0; j<quantita2[0]; j++)
		{
			quantita['Z'-'A']--;
			quantita['E'-'A']--;
			quantita['R'-'A']--;
			quantita['O'-'A']--;
		}
		// W -> Two
		quantita2[2] = quantita['W'-'A'];
		for(int j=0; j<quantita2[2]; j++)
		{
			quantita['T'-'A']--;
			quantita['W'-'A']--;
			quantita['O'-'A']--;
		}
		// U -> Four
		quantita2[4] = quantita['U'-'A'];
		for(int j=0; j<quantita2[4]; j++)
		{
			quantita['F'-'A']--;
			quantita['O'-'A']--;
			quantita['U'-'A']--;
			quantita['R'-'A']--;
		}
		// X -> Six
		quantita2[6] = quantita['X'-'A'];
		for(int j=0; j<quantita2[6]; j++)
		{
			quantita['S'-'A']--;
			quantita['I'-'A']--;
			quantita['X'-'A']--;
		}
		// G -> Eight
		quantita2[8] = quantita['G'-'A'];
		for(int j=0; j<quantita2[8]; j++)
		{
			quantita['E'-'A']--;
			quantita['I'-'A']--;
			quantita['G'-'A']--;
			quantita['H'-'A']--;
			quantita['T'-'A']--;
		}
		// O -> One
		quantita2[1] = quantita['O'-'A'];
		for(int j=0; j<quantita2[1]; j++)
		{
			quantita['O'-'A']--;
			quantita['N'-'A']--;
			quantita['E'-'A']--;
		}
		// H -> Three
		quantita2[3] = quantita['H'-'A'];
		for(int j=0; j<quantita2[3]; j++)
		{
			quantita['T'-'A']--;
			quantita['H'-'A']--;
			quantita['R'-'A']--;
			quantita['E'-'A']--;
			quantita['E'-'A']--;
		}
		// F -> Five
		quantita2[5] = quantita['F'-'A'];
		for(int j=0; j<quantita2[5]; j++)
		{
			quantita['F'-'A']--;
			quantita['I'-'A']--;
			quantita['V'-'A']--;
			quantita['E'-'A']--;
		}
		// S -> Seven
		quantita2[7] = quantita['S'-'A'];
		for(int j=0; j<quantita2[7]; j++)
		{
			quantita['S'-'A']--;
			quantita['E'-'A']--;
			quantita['V'-'A']--;
			quantita['E'-'A']--;
			quantita['N'-'A']--;
		}
		// I -> Nine
		quantita2[9] = quantita['I'-'A'];
		out << "Case #" << i+1 << ": ";
		for(int j=0; j<10; j++)
			for(int k=0; k<quantita2[j]; k++)
				out << j;
		out << endl;
	}
	return 0;
}
