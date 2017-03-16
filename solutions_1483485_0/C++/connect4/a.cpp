#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
using namespace std;


int main()
{
fstream In("a-small.in", ios::in);
fstream Out("a-small.out", ios::out);

int tests;
string s;
getline(In, s);
tests = atoi(s.c_str() );

string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvqz";
string s2 = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upzq";

char table[256];
memset(table, 0 , sizeof(table));

for(int i=0; i<s1.size(); i++)
		table[s1[i]] = s2[i];

for(int h=0; h<tests; h++)
{
	
getline(In, s);
for(int i=0; i<s.size(); i++)
	s[i] = table[s[i]];

Out << "Case #" << h+1 << ": " << s << endl;

}

In.close();

Out.close();

return 0;

}
 
