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
	

	ifstream fin("B-large.in");  
	ofstream fout("output.out");

	/*ifstream fin("input.txt");  
	ofstream fout("output.txt");*/
	
	int T;
	fin>>T;

	for (int cnt=1; cnt<=T; cnt++)
	{
		char flag='+';
		string s;
		fin>>s;
		int number=0;
		for (int i=s.length()-1; i>=0; i--)
		{
			if (s[i]!=flag)
			{
				number++;
				if (flag=='+')
					flag='-';
				else
					flag='+';
			}
		}
		fout<<"Case #"<<cnt<<": "<<number<<endl;
	}
	

	//system("pause");
	//return 0;
}
