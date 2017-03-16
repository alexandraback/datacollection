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
vector<string> A[40];
int resultPre = -1;

int make(char x[30], int h1)
{
	int y = strlen(x);
	int result = -1;
	for(int i1 = 0; i1< A[y].size();i1++)
	{
		bool yes = true;
		int cnt = 0, pre = -1, ch = 0;
		for(int j=0;j<y;j++)
		{
			if(A[y][i1][j]!=x[j])
			{
				if((pre == -1 && (h1 == -1 || h1 + cnt>=4))
					|| cnt>=4)
				{
					pre = j;
					cnt = 0;
					ch ++;
				}
				else
				{
					yes = false;
					break;
				}
			}
			else
				cnt ++;
		}

		if(yes == true && (result == -1 || result > ch || (result == ch && cnt>resultPre)))
		{
			result = ch;

			if(pre == -1)
			{
				resultPre = h1;

				if(resultPre!=-1)
					resultPre += y;
			}
			else
				resultPre = cnt;
		}
	}

	return result;
}

char line[4009];
int B[4009];
int C[4009];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);

	FILE *fp = fopen("garbled_email_dictionary.txt","r");
    
    while( fgets(line,1024,fp) ) {
		A[strlen(line)-1].push_back(line);
    }

	int cas;

	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		scanf("%s",line);

		int n = strlen(line);

		for(int i=0;i<n;i++)
		{
			B[i]=-1;
			C[i]=-1;
		}

	    char temp[30];

		for(int i=0;i<20;i++)
		{
			if(i>=n)
				break;
			temp[i]=line[i];
			temp[i+1]=0;

			int p = make(temp,-1);
			
			if(p!=-1)
			{
				B[i]=p;
				C[i]=resultPre;
			}
		}

		for(int i=0;i<n-1;i++)
			if(B[i]!=-1)
			{
				for(int j=1;j<=20;j++)
				{
					if(i+j>=n)
						break;
					temp[j-1]=line[i+j];
					temp[j]=0;

					int p = make(temp,C[i]);

					if(p!=-1 && (B[i+j] == -1 || B[i+j]> B[i]+p || (B[i+j] == B[i]+p && resultPre > C[i+j])))
					{
						B[i+j] = B[i]+p;
						C[i+j] = resultPre;
					}
				}
			}

		printf("Case #%d: %d\n",cas1,B[n-1]);
	}

	return 0;    
}
