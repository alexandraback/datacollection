#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*vector<char> mapping(256,0);
	vector<bool> found(256,false);
	ifstream finput("input.txt");
	ifstream foutput("output.txt");
	char c;
	mapping['a'] = 'y';
	mapping['o'] = 'e';
	mapping['z'] = 'q';
	while ( finput >> c )
	{
		foutput >> mapping[c];
		found[mapping[c]] = true;
	}
	finput.close();
	foutput.close();

	char last;
	for ( c = 'a'; c <= 'z'; ++c )
	{
		if ( !found[c] ) last = c;
	}
	for ( c = 'a'; c <= 'z'; ++c )
	{
		if ( !mapping[c] ) mapping[c] = last;
	}
	cout << last;
	ofstream fout("map.txt");
	for ( c = 'a'; c <= 'z'; ++c )
	{
		fout << mapping[c] << '\n';
	}
	fout.close();*/
	
	vector<char> mapping(256,0);
	for ( int i = 0; i < 256; ++i ) mapping[i] = (char)i;
	ifstream fmap("map.txt");
	for ( char c = 'a'; c <= 'z'; ++c )
	{
		fmap >> mapping[c];
	}
	fmap.close();

	ifstream fin("a.txt");
	ofstream fout("a_sol.txt");
	string s;
	int cs;
	fin >> cs;
	getline(fin, s);
	for ( int t = 1; t <= cs; ++t  )
	{
		cout << t << '\n';
		getline(fin, s);
		for ( unsigned i = 0; i < s.length(); ++i )
		{
			s[i] = mapping[s[i]];
		}
		fout << "Case #" << t << ": " << s <<'\n';
	}
	fin.close();
	fout.close();
}