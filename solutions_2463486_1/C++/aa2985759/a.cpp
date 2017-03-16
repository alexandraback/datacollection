#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string.h>
#include <bitset>
#include<fstream>
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

using namespace std;


int cmp(string a,string b)
{
	if(a.size()==b.size())
		return a<b;
	return a.size()<b.size();
}

char ans[1100],s1[1100];

void rev()
{
	int len=strlen(s1),i;
	ans[len]=0;

	for(i=0;s1[i];i++)
		ans[len-i-1]=s1[i];
	strcpy(s1,ans);
}
int a[1100],b[1100];
string get()
{
	rev();
	int i,j,len=0;
	for(i=0;s1[i];i++)
		a[i]=s1[i]-'0';
	len=i;

	memset(b,0,sizeof(b));
	for(i=0;i<len;i++)
		for(j=0;j<len;j++)
			b[i+j]+=a[i]*a[j];

	memset(s1,0,sizeof(s1));
	for(i=0;i<=len+len-2;i++)
		s1[i]=b[i]+'0';
	rev();
	string s=s1;
	return s;
}

string s[510000];
int cnt;

int BS(string now)
{
	int l=0,r=cnt-1,mid;

	while(l<r)
	{
		mid=(l+r+1)/2;
		if(s[mid].size()>now.size()||(s[mid].size()==now.size()&&s[mid]>now))
			r=mid-1;
		else
			l=mid;
	}
	return l;
}
int main()
{
	ifstream fin1("2.txt");
	ifstream fin2("C-large-1.in");

	freopen("1.txt","w",stdout);
	while(fin1>>s1)
	{
		s[cnt++]=get();
	}

	int t,i,j;
	string A,B;
	fin2>>t;

	for(int ii=1;ii<=t;ii++)
	{
		fin2>>A>>B;
		printf("Case #%d: ",ii);
		int l=BS(A),r=BS(B);
		if(A==s[l])
			cout<<r-l+1<<endl;
		else
			cout<<r-l<<endl;
	}
}