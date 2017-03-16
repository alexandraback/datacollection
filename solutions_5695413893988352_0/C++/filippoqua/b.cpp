#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

const double PI = 3.1415926535;

using namespace std;
int q1, q2;

string conzeri(int num, int ncif)
{
	string q;
	q.resize(ncif);
	for(int i=ncif-1; i>=0; i--)
	{
		q[i] = num%10+'0';
		num/=10;
	}
	return q;
}

int tonum(string &s)
{
	int num = 0;
	for(int i=0; i<(int)s.length(); i++)
		num = num*10+s[i]-'0';
	return num;
}

void aggiorna(string &s1, string &s2)
{
	int q1bis = tonum(s1);
	int q2bis = tonum(s2);
	if(abs(q1-q2)>abs(q1bis-q2bis) || (abs(q1-q2)==abs(q1bis-q2bis) && q1bis<q1) || (abs(q1-q2)==abs(q1bis-q2bis) && q1bis==q1 && q2bis<q2))
	{
		q1 = q1bis;
		q2 = q2bis;
	}
}

void prova2(string &s1, string &s2, int pos)
{
	if(s2[pos]=='?')
	{
		for(int i=0; i<10; i++)
		{
			s2[pos] = '0'+i;
			if(pos==(int)s2.length()-1)
				aggiorna(s1,s2);
			else
				prova2(s1,s2,pos+1);
		}
		s2[pos] = '?';
	}
	else
	{
		if(pos==(int)s2.length()-1)
			aggiorna(s1,s2);
		else
			prova2(s1,s2,pos+1);
	}
}

void prova(string &s1, string &s2, int pos)
{
	if(s1[pos]=='?')
	{
		for(int i=0; i<10; i++)
		{
			s1[pos] = '0'+i;
			if(pos==(int)s1.length()-1)
				prova2(s1,s2,0);
			else
				prova(s1,s2,pos+1);
		}
		s1[pos] = '?';
	}
	else
	{
		if(pos==(int)s1.length()-1)
				prova2(s1,s2,0);
		else
			prova(s1,s2,pos+1);
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int t;
	string s1,s2;
	in >> t;
	for(int i=0; i<t; i++)
	{
		in >> s1 >> s2;
		q1 = 1000;
		q2 = 0;
		prova(s1,s2,0);
		
		out << "Case #" << i+1 << ": " << conzeri(q1,s1.length()) << " " << conzeri(q2,s1.length()) << endl;
	}
	return 0;
}

