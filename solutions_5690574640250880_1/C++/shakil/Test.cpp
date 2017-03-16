#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<map>
using namespace std;

/*
void Vec()
{
	vector<int> A;  
	A.push_back(10);
	int n = A.size();
	A.clear();
	if(!A.empty())
	{
		int sum = 0;
		for(vector<int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += *it;
		}

		vector<int>::iterator it = A.begin();
		A.erase(it);
		sort(A.begin(),A.end());
		it = max_element(A.begin(),A.end());
		it = min_element(A.begin(),A.end());
		A.insert(it,10);
		A.pop_back();
		int a = A.front();
		int b = A.back();
	}
}

void Pairs()
{
	pair<int,int> A;
	A.first = 10;
	A.second = 15;
}

void STRING()
{
	string a = "Hello";
	a = a + a;
	string b = a.substr(0,3);
	int t = a.find_first_of('a');
	cout<< a;
}

void SET()
{
	set<int> A;
	A.insert(10);
	A.erase(10);
	int t = A.count(10);
	set<int>::iterator it = A.find(10);
	it = A.upper_bound(10);//>10
	it = A.lower_bound(10);//<=10

	A.clear();
	if(!A.empty())
	{
		int sum = 0;
		for(set<int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += *it;
		}
	}
}

void MAP()
{
	map<int,int> A;
	A[10]=20;
	A.erase(10);
	A.clear();
	A.size();
	map<int,int>::iterator it = A.find(10);

	if(!A.empty())
	{
		int sum = 0;
		for(map<int,int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += it->second;
		}
	}
}

struct fun{
  int  xnode, weight;
  fun() {}
  fun(int t, int w) : xnode(t), weight(w) {}
  bool operator < (const fun &that) const {
    return weight > that.weight;
  }
};

void Priority_Queue()
{
	priority_queue<fun> q;
	q.top().weight;
	q.pop();
	q.push(fun(1,2));
	int i = q.size();
	if(!q.empty())
	{}
}
*/

	char A[109][109];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;

	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		int r,c,m;

		scanf("%d %d %d",&r,&c,&m);

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				A[i][j]='.';

		int yes = 1;

		if(m>0)
		{
		if(r==1||c==1)
		{
			if(r==1)
			{
				for(int i=0;i<m;i++)
					A[0][i]='*';

				A[0][c-1]='c';
			}
			else
			{
				for(int i=0;i<m;i++)
					A[i][0]='*';

				A[r-1][0]='c';
			}
		}
		else if(r==2||c==2)
		{
			if(r*c-1==m)
			{
				for(int i=0;i<r;i++)
					for(int j=0;j<c;j++)
						A[i][j]='*';

				A[r-1][c-1]='c';
			}
			else if(m%2==0 && m <= r*c - 4)
			{
				if(r==2)
				{
					for(int i=0;i<m/2;i++)
					{
						A[0][i]='*';
						A[1][i]='*';
					}
				}
				else
				{
					for(int i=0;i<m/2;i++)
					{
						A[i][0]='*';
						A[i][1]='*';
					}
				}

				A[r-1][c-1]='c';
			}
			else
				yes = 0;
		}
		else
		{
			if(r*c-1==m)
			{
				for(int i=0;i<r;i++)
					for(int j=0;j<c;j++)
						A[i][j]='*';

				A[r-1][c-1]='c';
			}
			else if(m > r * c - 4 || m == r * c - 4 - 1 || m == r * c - 4 - 3)
			{
				yes = 0;
			}
			else
			{
				int t = 0;

				for(int i=0;i<r-2;i++)
				{
					for(int j=0;j<c;j++)
					{
						A[i][j]='*';
						t++;
						if(t==m)
							break;
					}

					if(t==m)
							break;
				}

				if(t==m)
				{
					if(m%c==c-1)
					{
						int p = m/c;
						A[p][c-2]='.';
						A[p+1][0]='*';

						if(p+1>=r-2)
						{
							A[p][c-3]='.';
							A[p+2][0]='*';
						}
					}
				}
				else
				{
					int p = m - t;

					for(int j=0;j<c;j++)
					{
					for(int i=r-2;i<r;i++)
					{
						A[i][j]='*';
						t++;
						if(t==m)
							break;
					}

						if(t==m)
							break;
					}

					if(p%2!=0)
					{
						A[r-3][c-1] = '.';
						A[r-3][c-2] = '.';
						A[r-3][c-3] = '.';

						int p2 = p / 2;
						A[r-1][p2]='*';
						A[r-2][p2+1]='*';
						A[r-1][p2+1]='*';
					}
				}


				A[r-1][c-1]='c';
			}
		}
		}
		else
		{
			A[r-1][c-1] = 'c';
		}	

		printf("Case #%d:\n",cas1);

		if(yes==0)
			printf("Impossible\n");
		else 
		{
			for(int i=0;i<r;i++)
			{
			for(int j=0;j<c;j++)
				printf("%c",A[i][j]);
			printf("\n");
			}
		}
	}

	return 0;    
}
