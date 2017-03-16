/* Ömer Özdemir */

#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include<fstream>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int T;
string s;
int n;

ifstream myStream;
ofstream outfile;

int main()
{
	outfile.open("A-small_output.in");
	myStream.open("A-small-attempt0.in");

	if(myStream.is_open())
	{
		myStream >> T ;
		
		for(int i=1;i<=T;i++)
		{
			myStream >> s >> n ;
			int count1=0;
			for(int j=0;j<s.length();j++)
			{
				for(int k=1;k<=s.length()-j;k++)
				{
					string temp=s.substr(j,k);
					int count2=0;
					for(int l=0;l<temp.length();l++)
					{
						if(temp.at(l) != 'a' && temp.at(l) != 'e' && temp.at(l) != 'i' && temp.at(l) != 'o' && temp.at(l) != 'u' )
						{
							count2++;
						}
						else
						{
							if(count2<n)
							{
								count2=0;
							}
						}
					}
					if(count2>=n)
					{
						count1++;
						
					
					}

				}
			}
			outfile<<"Case #"<<i<<": "<<count1<<endl;
		}
	}

	return 0;
}