#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <tuple>
#include <queue>
#include <map>

using namespace std;

void subs(map<char, int>& mm, const string& w, int countt)
{
	for(char c : w)
	{
		mm[c]-=countt;
	}
}

int main()
{
	
unsigned nn;
cin >> nn;
for(unsigned kk=1; kk <= nn; kk++)
{
	
	string s;
	cin >> s;
	
	map<char, int> mm;
	map<int, int> mres;
	
	for(char c : s)
	{
		if(mm.find(c) == mm.end()) mm[c] = 1;
		else mm[c]++;
	}
	
	char cur;
	int curi;
	string w;
	int countt;
	
	w = "ZERO";
	cur = 'Z';
	curi = 0;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "TWO";
	cur = 'W';
	curi = 2;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "SIX";
	cur = 'X';
	curi = 6;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "EIGHT";
	cur = 'G';
	curi = 8;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "SEVEN";
	cur = 'S';
	curi = 7;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "FIVE";
	cur = 'V';
	curi = 5;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "FOUR";
	cur = 'F';
	curi = 4;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "THREE";
	cur = 'T';
	curi = 3;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "ONE";
	cur = 'O';
	curi = 1;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	w = "NINE";
	cur = 'I';
	curi = 9;
	if(mm.find(cur)==mm.end()) countt = 0;
	else countt = mm[cur];
	mres[curi] = countt;
	subs(mm, w, countt);
	
	
	cout << "Case #" << kk << ": ";
	for(unsigned n=0; n<=9; n++)
	{
		unsigned num;
		if(mres.find(n)==mres.end()) num = 0;
		else num = mres[n];
		for(int i=0; i<num; i++) cout << n;
	}
	cout << endl;
	
}
	
}
