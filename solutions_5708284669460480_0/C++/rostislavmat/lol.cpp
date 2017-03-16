#include <algorithm>
#include <bitset>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string s="";
string h,go;
int max1=0;
long long sum=0;
int a,b,x;
long long dd=0;
void calc (string s1)
{
	int n = (int) s1.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i)
	{
		int j = pi[i-1];
		while (j > 0 && s1[i] != s1[j])
			j = pi[j-1];
		if (s1[i] == s1[j])  ++j;
		pi[i] = j;
	}
	int kol=0;
	for (int i=go.length()+1;i<pi.size();i++)
	{
		if (pi[i]==go.length())
			kol++;
	}
	if (kol>max1)
		max1=kol;
	sum+=kol;
}

void dfs(int l)
{
	if (l==x)
	{
		calc(go+"#"+s);
		dd++;
	}
	else
	{
		string ff=s;
		for (int i=0;i<h.length();i++)
		{
			s+=h[i];
			dfs(l+1);
			s=ff;
		}
	}
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
    int qq;
	cin>>qq;
	for (int q=0;q<qq;q++)
	{
		cout<<"Case #"<<q+1<<": ";
		s="";
		max1=0;
		sum=0;
		dd=0;
		cin>>a>>b>>x;
		cin>>h>>go;
		dfs(0);
		long double ans=(max1*dd-sum+.0)/(dd+0.0);
		cout<<setprecision(9)<<ans<<endl;
	}
    return 0;
}