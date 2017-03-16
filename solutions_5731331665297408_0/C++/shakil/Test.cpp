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

char A[10][10],res[1000],temp[1009];
int n,m,visit[10],sak1[10];
vector<int> sak[10];

void make(int h1,int h2)
{
	if(h1==n)
	{
		temp[h2]=0;

		bool yes = 1;
		vector<int> kam;
		kam.push_back(sak1[0]);

		for(int i=1;i<h1;i++)
		{
			int ggg = 0;

			while(kam.size()!=0)
			{
			
				for(int j=0;j<sak[kam[kam.size()-1]].size();j++)
					if(sak[kam[kam.size()-1]][j]==sak1[i])
					{
						ggg = 1;
						break;
					}

					if(ggg)
					{
						break;
					}
					else
					{
						kam.pop_back();
					}
			}

			if(ggg==1)
			{
				kam.push_back(sak1[i]);
			}
			else
			{
				yes = 0;
				break;
			}
		}


		if(yes == 1)
		if(strlen(res)==0||strcmp(res,temp)>0)
			strcpy(res,temp);

	}
	else
	{
		for(int i=1;i<=n;i++)
			if(visit[i]==0)
			{
				visit[i]=1;
				sak1[h1]=i;
				strcpy(temp+h2,A[i]);
				make(h1+1,h2+strlen(A[i]));
				visit[i]=0;
			}
	}
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;

	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		scanf("%d %d",&n,&m);

		for(int i=1;i<=n;i++)
			sak[i].clear();

		for(int i=1;i<=n;i++)
		{
			scanf("%s",&A[i]);
			visit[i]=0;
		}

		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			sak[x].push_back(y);
			sak[y].push_back(x);
		}

		strcpy(res,"");

		for(int i=1;i<=n;i++)
		{
			visit[i]=1;
			strcpy(temp,A[i]);
			sak1[0]=i;
			make(1,strlen(A[i]));
			visit[i]=0;
		}

		printf("Case #%d: %s\n",cas1,res);

	}

	return 0;    
}
