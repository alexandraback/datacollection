
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
set <int> xx[2000000+10];
    int main()
        {
			freopen("input.txt","rt", stdin);
			freopen("output.txt","wt", stdout);
			int tests;
			scanf("%d",&tests);
			for (int i = 0; i <=2000000;i++)				
			{					
					xx[i].clear();
					for (int d = 10; d <=i; d*=10)
					{
						int x = i%d;
						int y = i/d;		
						char os[1000];
						sprintf(os,"%d%d",x,y);						
						//ostringstream oss;
						//oss << x << y;
						//istringstream iss(oss.str());
						
						int res;
						//iss >> res;
						sscanf(os, "%d", &res);

						if (res > i && res <= 2000000)
							xx[i].insert(res);
							//ms.insert(res);
					}
			}
				
			for (int test = 1; test <= tests; test++)
			{
				int n,a,b;
				scanf("%d%d",&a,&b);
				long long anw =0;
				long long p[20];
				p[0] = 1;
				for (int i = 1; i < 9; i++)
					p[i] = p[i-1]*10;
				int len;
				for(int i = 1; i < 9;i++)
					if (p[i]> b)
					{
						len = i-1;
						break;
					}
				//for (int i = 0; i <=2000000;i++)
				for (int i = a; i <= b; i++)
				{
					for(set<int>::iterator it = xx[i].begin(); it != xx[i].end();it++)
					{
						int res = *it;
						if (res > i && res <= b)
							anw++;

					}
					/*
					set <int> ms;
					ms.clear();
					for (int d = 10; d <=b; d*=10)
					{
						int x = i%d;
						int y = i/d;		
						char os[1000];
						sprintf(os,"%d%d",x,y);
						//ostringstream oss;
						//oss << x << y;
						//istringstream iss(oss.str());
						
						int res;
						//iss >> res;
						sscanf(os, "%d", &res);
						if (res > i && res <= b)
							ms.insert(res);
					}
					anw += ms.size();
					*/
				}
				
				printf("Case #%d: ",test);
				printf("%I64d\n",anw);

			}

		return 0;

			
        } 
    // END CUT HERE 
