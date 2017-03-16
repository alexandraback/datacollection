// QualRound.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

//1 i j k -> 1 2 3 4
int g[5][5]={
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1},
            };

int calc(int i, int j)
{
	int sign=1;
	if(i*j<0) sign=-1;
	i=abs(i); j=abs(j);
	return sign*g[i][j];
}

int convert(char ch)
{
	if(ch=='i') return 2;
	if(ch=='j') return 3;
	if(ch=='k') return 4;
	return 1;
}

int solve()
{
	int l,x;
	string s;
	cin>>l>>x>>s;
	int cur=0;
	for(int stage=1;stage<=3;stage++)
	{
		int t=1;
		for(int i=0;i<16*l && cur<l*x;i++,cur++)
		{
			int c=convert(s[cur%s.size()]);
			t=calc(t,c);
			if(t==stage+1) break;
		}
		if(t!=stage+1) return 0;
		cur++;
	}
	int t=1;
	for(; cur<l*x; cur++)
	{
		int c=convert(s[cur%s.size()]);
		t=calc(t,c);
	}
	if(t==1)
	{
		return 1;
	}
	return 0;
}


int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		if(solve())
		{
			cout<<"Case #"<<tc+1<<": ";
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": ";
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
