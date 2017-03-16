
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
			int tests;
			scanf("%d",&tests);
			int bestscore[100], surpr[100];
			for(int i = 0; i <= 30;i++)
				bestscore[i] = surpr[i] = 0;
			for (int a = 0; a <= 10; a++)
				for (int b = 0; b <= 10; b++)
					for (int c = 0; c <= 10; c++)
					{
						int bs = max(max(a,b),c);
						if ((abs(a - b) > 2)||(abs(a - c) > 2)||(abs(b - c) > 2))
							continue;
						if ((abs(a - b) == 2)||(abs(a - c) == 2)||(abs(b - c) == 2))
							surpr[a+b+c] = max(surpr[a+b+c], bs);
						else
						{
							bestscore[a+b+c] = max(bestscore[a+b+c], bs);
							surpr[a+b+c] = max(surpr[a+b+c], bs);
						}

					}
			for (int test = 1; test <= tests; test++)
			{
				int n,s,p;
				scanf("%d%d%d",&n,&s,&p);
				vector<int> v;
				v.clear();
				for(int i = 0; i < n; i++)
				{
					int c;
					scanf("%d", &c);
					v.push_back(c);
				}
				sort(v.begin(),v.end());
				reverse(v.begin(),v.end());
				int anw = 0;
				for (int i = 0; i < v.size(); i++)
				{
					int x = v[i];
					if (bestscore[x] >= p)
						anw++;
					else
						if ((surpr[x]>=p) && (s>0))
						{
							s--;
							anw++;
						}
				}
				printf("Case #%d: ",test);
				printf("%d\n",anw);

			}

		return 0;

			
        } 
    // END CUT HERE 
