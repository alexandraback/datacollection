
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
			for (int test = 1; test <= tests; test++)
			{
				//scanf("")
				int n;
				scanf("%d", &n);
				vector <pair<int,int> > v;
				v.clear();
				vector <pair<int,int> > vv;
				vv.clear();
				for (int i = 1; i <=n; i++)
				{
					int a, b;
					scanf("%d%d", &a,&b);
					v.push_back(make_pair(b, a));
				}
				sort(v.begin(), v.end());
				for (int i = 0; i < n; i++)
				{
					//v[i].first = -v[i].first;
					vv.push_back(v[i]);

				}
				int best  = 0;
				int stars = 0;
				int haveone = n;
				int myanw = 1000000000;
				vector<int> perm;
				for (int i = 0; i < n; i++)
					perm.push_back(i);
				do 
				{
					for (int i = 0; i < n; i++)
						v[i] = vv[i];
				stars = 0;
				best  = 0;
				for (int z = 0; z < 20000000; z++)
				{
					int flag = 0;
					for(int i = 0; i < n; i++)
						if ((v[i].first != -1)   && (v[i].first <= stars))
						{
							if (v[i].second != -1)
								stars +=2;
							else
								stars += 1;

							v[i].first = -1;
							v[i].second = -1;
							haveone -=1;
							best +=1;
							flag = 1;
							//break;
						}
					if (flag == 1)
						continue;
					/*
					int nextt = 1000000;

					int target = -1;
					for(int i = 0; i < n; i++)
						if(v[i].first != -1  && v[i].second != -1)
							if (v[i].first < nextt)
							{
								nextt = v[i].first;
								target = i;
							}
					if (target != -1)
					{
						int i = target;
						if ((v[i].second != -1) && (v[i].second <= stars) && flag == 0)
						{
						
							v[i].second = -1;
							stars +=1;
							best +=1;
							flag = 1;
							continue;
						}
					}
					*/
					
					for(int j = 0; j < n; j++)
					{
						int i = perm[j];
						if ((v[i].second != -1) && (v[i].second <= stars) && flag == 0)
						{
							v[i].second = -1;
							stars +=1;
							best +=1;
							flag = 1;
							break;
						}
					}
					
					if (flag == 0)
						break;
				}
				int flag = 0;
				for(int i = 0; i < n; i++)
					if (v[i].first != -1  || v[i].second !=-1)
							flag = 1;
				if (stars!= n*2)
					flag = 1;
				if ( flag == 0)
					myanw = min(myanw, best);
				} while (next_permutation(perm.begin(), perm.end()));

				best = myanw;
				
				printf("Case #%d: ",test);
				if (best <= 1000000)
					printf("%d\n",best);
				else
					printf("Too Bad\n",best);

			}



			
        } 
    // END CUT HERE 
