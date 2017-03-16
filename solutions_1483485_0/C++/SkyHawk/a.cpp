//SkyHawk, CMC MSU

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;++i)

string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jvzq";

string s2 = "our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give upqz";

int main(int argc, char** argv)
{
	int n;
	scanf("%d\n",&n);
	FOR(i,n)
	{
		cout << "Case #" << i+1 << ": ";
		for(char c = getchar();c!='\n';c = getchar())
			FOR(i,s1.size())
				if(c == s1[i])
				{
					cout << s2[i];
					break;
				}
		cout << endl;
	}
}
