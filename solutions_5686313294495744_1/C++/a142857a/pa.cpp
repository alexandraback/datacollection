#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;


ifstream fin("C-large.in");
ofstream fout("ans.txt");
#define cin fin
#define cout fout

bool a[1005][1005];
map<string, int>h1, h2;
int pn, qn;
int n;
int lk[1005];
bool u[1005];

bool work(int p)
{
	for(int i = 1; i <= n; i++)
	if(a[p][i]&&!u[i])
	{
		u[i]=true;
		if(lk[i]==0||work(lk[i]))
		{
			lk[i]=p;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++)
	{
		int ans = 0;
		int tmp = 0;
		cin>>n;
		string s1, s2;
		h1.clear(); h2.clear();
		memset(a, 0, sizeof(a));
		pn=qn=0;
		for(int i = 1; i <= n; i++)
		{
			cin>>s1>>s2;
			if(!h1[s1])
			{
				h1[s1]=++pn;
			}
			if(!h2[s2])
			h2[s2]=++qn;
			
			int p=h1[s1];
			int q=h2[s2];
			if(a[p][q]) tmp++;
			else a[p][q]=1;
		}
		cout<<"Case #"<<t<<": ";
		memset(lk, 0, sizeof(lk));
		ans=0;
		for(int i = 1; i <= n; i++)
		{
			memset(u, 0, sizeof(u));
			if(work(i)) ans++;
		}
		cout <<n - (pn + qn - ans) - tmp<<endl;
	}
	
	
	return 0;
}
/* 
3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC
*/
 
