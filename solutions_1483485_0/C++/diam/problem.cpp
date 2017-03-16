
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
    int main()
        {
			freopen("input.txt","rt", stdin);
			freopen("output.txt","wt", stdout);
			int n;
			scanf("%d", &n);
			char  buf[1000];
			gets(buf);
			char rp[500];
			int used[500];
			for (int c = 0; c<=255;c++)
			{
				used[c] = 0;
				rp[c]=c;
			}
			string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvyeq";
			string s2 = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upaoz";			
			for (int i = 0; i < s1.size();i++)
			{
				rp[s1[i]] = s2[i];
				used[s2[i]] = 1;
			}
			rp['z'] = 'q';
			
			//for (int c = 'a'; c<='z';c++)								
					//printf("%c%c\n",c,rp[c]);
					
			for (int test = 1; test <= n; test++)
			{
				gets(buf);
				string s = buf;
				for (int i = 0; i < s.size();i++)
					s[i] = rp[s[i]];
				printf("Case #%d: ",test);
				printf("%s\n",s.c_str());

			}



			
        } 
    // END CUT HERE 
