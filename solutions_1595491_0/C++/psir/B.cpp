#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

char buff[200];

int N, S, p;
vector<int> s;

int main()
	{

	int T;
	gets(buff);
	sscanf(buff,"%d",&T);

	for( int t = 0 ; t< T; ++t )
		{
		s.clear();
		gets(buff);
		string ss = string(buff,buff+strlen(buff));
		stringstream SS(ss);

		string tmp;
		SS >> tmp; sscanf(tmp.c_str(),"%d",&N);		
		SS >> tmp; sscanf(tmp.c_str(),"%d",&S);		
		SS >> tmp; sscanf(tmp.c_str(),"%d",&p);		

		s.resize(N);

		for( int i = 0; i < N; ++i )
			{ SS >> tmp; sscanf(tmp.c_str(),"%d",&s[i]);		
		}

		sort(s.rbegin(), s.rend());
		int sol = 0;
		for( int i = 0; i < N; ++i )
			{
			if( 3*(p-1) < s[i] )
				++sol;
			else if ( S > 0 && s[i] >= 3*p - 4 && s[i] >= p)
				{ ++sol; --S;}
			else break;
			}
		
		printf("Case #%d: %d\n",t+1,sol);
		}

	return 0;
	}
