#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

const int SIZE = 26;
int cas, index=1;
ifstream fin1("A-small-attempt0.in");
ofstream fout("A-Small.out");

char map[SIZE]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

void read()
{
	char * str= new char[200];	
	fin1.getline(str, 200);

	for (int i=0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			fout << map[str[i]-'a'];
		}//end if
		else
			fout << str[i];
	}//end for
	fout << endl;
}


int main()
{
	fin1 >> cas;
	
	char * str = new char[100];
	fin1.getline(str,100);
	while(index <= cas )
	{
		fout << "Case #"<<index<<": ";
		read();
		index ++;
	}
	
	return 0;
}