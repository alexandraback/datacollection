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


int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);


	int cas,a,n,k;

	scanf("%d",&cas);
	for(int cas1=1;cas1<=cas;cas1++)
	{
		scanf("%d %d",&a,&n);

		vector<int> A; 

		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			A.push_back(k);
		}

		sort(A.begin(),A.end());

		int result = n;
		int cnt = 0,sum = a;

		if(a!=1)
		for(int i=0;i<n;i++)
		{
			if(A[i]<sum)
				sum+=A[i];
			else
			{
				while(A[i]>=sum)
				{
					sum += (sum-1);
					cnt++;
				}

				sum += A[i];
			}

			if(result>cnt+(n-i-1))
				result = cnt+(n-i-1);
		}


		printf("Case #%d: %d\n",cas1,result);
	}

	return 0;    
}
