#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include <ctime>
//#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>


using namespace std;



int main() 
{
	char c[1000];
	int number[10];

	ifstream fin("A-large.in");  
	ofstream fout("output.out");

	/*ifstream fin("input.txt");  
	ofstream fout("output.txt");*/
	
	int T;
	fin>>T;

	for (int cnt=1; cnt<=T; cnt++)
	{
		for (int i=0; i<10; i++)
			number[i]=0;
		int notobtained=10;
		

		string s;
		fin>>s;
		for (int i=0; i<s.length(); i++)
		{
			c[i]=s[s.length()-1-i];
			if (number[c[i]-'0']==0)
			{
				number[c[i]-'0']=1;
				notobtained--;
			}
		}
		int lengthc=s.length();
		if (s.length()==1 && s[0]=='0')
			fout<<"Case #"<<cnt<<": INSOMNIA"<<endl;
		else
		{
			while (notobtained>0)
			{
				int extra=0;
				for (int i=0; i<s.length(); i++)
				{
					int index=s.length()-1-i;
					int digital=c[i]-'0'+s[index]-'0'+extra;
					if (digital<10)
					{
						c[i]=digital+'0';
						extra=0;
					}
					else
					{
						c[i]=digital%10+'0';
						extra=1;
					}
				}
				if (extra==1)
				{
					if (lengthc==s.length())
					{
						c[lengthc]='1';
						lengthc++;
					}
					else
					{
						for (int i=s.length(); i<lengthc; i++)
						{
							int digital=c[i]-'0'+extra;
							if (digital<10)
							{
								c[i]=digital+'0';
								extra=0;
							}
							else
							{
								c[i]=digital%10+'0';
								extra=1;
							}
						}
						if (extra==1)
						{
							c[lengthc]='1';
							lengthc++;
						}

					}
				}

				for (int i=0; i<lengthc; i++)
				{
					if (number[c[i]-'0']==0)
					{
						number[c[i]-'0']=1;
						notobtained--;
					}
				}
			}

			fout<<"Case #"<<cnt<<": ";
			for (int i=0; i<lengthc; i++)
				fout<<c[lengthc-1-i];
			fout<<endl;

		}


	}


	
	

	system("pause");
	return 0;
}
