#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstring>
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

char temp[1000009];
__int64 cnt,sak1,sak2;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);


	int cas,n;

	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		scanf("%s %d",temp,&n);

		int l  = strlen(temp);
		cnt = 0;
		
		for(int i=0;i<l;i++)
		{
		  for(int j=i;j<l;j++)
		  {
			  int p = 0;
			  for(int k=i;k<=j;k++)
			  {
				  if(temp[k]=='a'||temp[k]=='e'||temp[k]=='i'||temp[k]=='o'||temp[k]=='u')
				  {
					  p = 0;
				  }
				  else
				  {
					  p++;
					  if(p>=n)
					  {
						  cnt++;
						  break;
					  }
				  }
			  }
		  }
		}

		printf("Case #%d: %I64d\n",cas1,cnt);
	}

	return 0;    
}
