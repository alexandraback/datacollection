#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
char mapping[26];
int asInteger(string u)
{
	return atoi(u.c_str());
}
int main()
{	
	mapping[0]='y';
	mapping[1]='h';
	mapping[2]='e';
	mapping[3]='s';
	mapping[4]='o';
	mapping[5]='c';
	mapping[6]='v';
	mapping[7]='x';
	mapping[8]='d';
	mapping[9]='u';
	mapping[10]='i';
	mapping[11]='g';
	mapping[12]='l';
	mapping[13]='b'	;
	mapping[14]='k';
	mapping[15]='r';
	mapping[16]='z'	;
	mapping[17]='t';
	mapping[18]='n';
	mapping[19]='w';
	mapping[20]='j';
	mapping[21]='p';
	mapping[22]='f';
	mapping[23]='m';
	mapping[24]='a'	;
	mapping[25]='q'	;

	string str;
	getline(cin,str);
	int T = asInteger(str);
	for (int kase=1;kase<=T;++kase)
	{
		getline(cin,str);
		stringstream im(str);
		string word;
		printf("Case #%d:",kase);
		while (im.eof() == false)
		{
			im >> word;
			printf(" ");
			for (int q=0;q<word.length();++q)
				printf("%c",mapping[word[q]-'a']);
		}
		printf("\n");
	}

	return 0;
}