#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("A.in");
	ofstream fout;
	fout.open("A.out");
	int tc,round,i;
	char c[26];
	string s;
	c[0]='y';
	c[1]='h';
	c[2]='e';
	c[3]='s';
	c[4]='o';
	c[5]='c';
	c[6]='v';
	c[7]='x';
	c[8]='d';
	c[9]='u';
	c[10]='i';
	c[11]='g';
	c[12]='l';
	c[13]='b';
	c[14]='k';
	c[15]='r';
	c[16]='z';
	c[17]='t';
	c[18]='n';
	c[19]='w';
	c[20]='j';
	c[21]='p';
	c[22]='f';
	c[23]='m';
	c[24]='a';
	c[25]='q';
	fin>>tc;
	getline(fin,s);
	for (round=0;round<tc;round++)
	{
		getline(fin,s);
		for (i=0;i<s.length();i++)
			if (s[i]==' ')
				s[i]=' ';
			else
				s[i]=c[s[i]-'a'];
		fout<<"Case #"<<round+1<<": "<<s<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}