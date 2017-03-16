#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

int f(vector<vector<int> > &vvec, int k)
{
	forn(i,vvec.size())
	{
		int a=0,b=0,c=0;
		forn(j,vvec.size())
		{
			if(vvec[i][0]==vvec[j][0] && vvec[i][1] == vvec[j][1])
				a++;
			if(vvec[i][0]==vvec[j][0] && vvec[i][2] == vvec[j][2])
				b++;
			if(vvec[i][1]==vvec[j][1] && vvec[i][2] == vvec[j][2])
				c++;
		}
		if(a > k || b > k || c > k)
			return false;
	}
	return true;
}

int main()
{
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
		int j,p,s,k;
		cin >> j >> p >> s >> k;
		vector<vector<int> > todos,vvec;
		for(int a=1;a<=j;a++)
		for(int b=1;b<=p;b++)
		for(int c=1;c<=s;c++)
		{
			vector<int> vec(3);
			vec[0] = a;
			vec[1] = b;
			vec[2] = c;
			todos.push_back(vec);
		}
		if(k >= 3)
			vvec = todos;
		else if(j == 3)
		{
			if(k == 1)
			{
				vector<int> vec;
				vec.push_back(1);
				vec.push_back(1);
				vec.push_back(1);
				vvec.push_back(vec);
				vec[1] = 2;
				vec[2] = 2;
				vvec.push_back(vec);
				vec[1] = 3;
				vec[2] = 3;
				vvec.push_back(vec);
				vec[0] = 2;
				vec[1] = 1;
				vec[2] = 2;
				vvec.push_back(vec);
				vec[1] = 2;
				vec[2] = 3;
				vvec.push_back(vec);
				vec[1] = 3;
				vec[2] = 1;
				vvec.push_back(vec);
				vec[0] = 3;
				vec[1] = 2;
				vec[2] = 1;
				vvec.push_back(vec);
				vec[1] = 3;
				vec[2] = 2;
				vvec.push_back(vec);
				vec[1] = 1;
				vec[2] = 3;
				vvec.push_back(vec);
			}
			else if(k == 2)
			{
				/**
				1 1 1
				1 1 3
				1 2 1
				1 2 2
				1 3 2
				1 3 3
				2 1 1
				2 1 2
				2 2 2
				2 2 3
				2 3 1
				2 3 3
				3 1 2
				3 1 3
				3 2 1
				3 2 3
				3 3 1
				3 3 2
				*/
				vector<int> vec(3,1);
				vvec.push_back(vec);
				vec[2] = 3;
				vvec.push_back(vec);
				vec[2] = 1;
				vec[1] = 2;
				vvec.push_back(vec);
				vec[2] = 2;
				vvec.push_back(vec);
				vec[1] = 3;
				vvec.push_back(vec);
				vec[2] = 3;
				vvec.push_back(vec);
				vec[0] = 2;
				vec[1] = 1;
				vec[2] = 1;
				vvec.push_back(vec);
				vec[2] = 2;
				vvec.push_back(vec);
				vec[1] = 2;
				vvec.push_back(vec);
				vec[2] = 3;
				vvec.push_back(vec);
				vec[2] = 1;
				vec[1] = 3;
				vvec.push_back(vec);
				vec[2] = 3;
				vvec.push_back(vec);
				vec[0] = 3;
				vec[1] = 1;
				vec[2] = 2;
				vvec.push_back(vec);
				vec[2] = 3;
				vvec.push_back(vec);
				vec[1] = 2;
				vec[2] = 1;
				vvec.push_back(vec);
				vec[2] = 3;
				vvec.push_back(vec);
				vec[1] = 3;
				vec[2] = 1;
				vvec.push_back(vec);
				vec[2] = 2;
				vvec.push_back(vec);
			}
		}
		else 
		{
			for(int i=0;i<=(1<<(todos.size()));i++)
			{
				vector<vector<int> > aux;
				forn(j,todos.size())
				if((i>>j)%2==1)
					aux.push_back(todos[j]);
				if(f(aux,k) && aux.size() > vvec.size())
					vvec = aux;
			}
		}
		printf("Case #%d: %d\n",casito,(int)vvec.size());
		for(int i=0;i<vvec.size();i++)
		{
			cout << vvec[i][0] <<" "<< vvec[i][1] <<" "<< vvec[i][2] << endl;
		}
	}
}
