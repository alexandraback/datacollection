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

int A[209],B[209],C[209],D[209];
int sak[100009];
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);


	int cas;
	int d[20],n[20],w[20],e[20],s[20],dd[20],dw[20],ds[20],N;
	
	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		scanf("%d",&N);
		int M = 0;

		for(int i=0;i<N;i++)
		{
		scanf("%d %d %d %d %d %d %d %d",&d[i],&n[i],&w[i],&e[i],&s[i],&dd[i],&dw[i],&ds[i]);
		}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<n[i];j++)
			{
				A[M] = d[i];
				B[M] = w[i];
				C[M] = e[i];
				D[M] = s[i];
				d[i] += dd[i];
				w[i]+=dw[i];
				e[i]+=dw[i];
				s[i]+=ds[i];
				M++;
			}
		}

		for(int i=0;i<M-1;i++)
			for(int j=0;j<M-1-i;j++)
				if(A[j]>A[j+1]||(A[j]==A[j+1] && D[j]>D[j+1]))
				{
					A[M+1]=A[j];
					B[M+1]=B[j];
					C[M+1]=C[j];
					D[M+1]=D[j];
					A[j]=A[j+1];
					B[j]=B[j+1];
					C[j]=C[j+1];
					D[j]=D[j+1];
					A[j+1]=A[M+1];
					B[j+1]=B[M+1];
					C[j+1]=C[M+1];
					D[j+1]=D[M+1];
				}

				for(int i = 0; i<=100000;i++)
					sak[i]=0;

				int cnt = 0;

				for(int i=0;i<M;i++)
				{
					int mini = 10000007;

					for(int j=B[i]*2+50000;j<=C[i]*2+50000;j++)
						if(sak[j]<mini)
							mini = sak[j];

					if(mini<D[i])
						cnt++;
				
					if(i!=M-1 && A[i]!=A[i+1])
					{
						for(int k=i;k>=0;k--)
						{
							if(A[k]!=A[i])
								break;

							for(int j=B[k]*2+50000;j<=C[k]*2+50000;j++)
							if(sak[j]<D[k])
								sak[j] = D[k];
						
						}
					}
				}


		printf("Case #%d: %d\n",cas1,cnt);
	}

	return 0;    
}
