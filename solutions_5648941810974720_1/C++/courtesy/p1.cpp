#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
string s;
int a[10];
void fun(int p,int c)
{
	if(c==1)
	{
		if(s[p]=='Z')
		{
			s[p]='Q';
			a[0]++;
		}
		if(s[p]=='W')
		{
			s[p]='Q';
			a[2]++;
		}
		if(s[p]=='U')
		{
			s[p]='Q';
			a[4]++;
		}
		if(s[p]=='X')
		{
			s[p]='Q';
			a[6]++;
		}
		if(s[p]=='G')
		{
			s[p]='Q';
			a[8]++;
		}
	}
	else
	if(c==2)
	{
		if(s[p]=='F')
		{
			s[p]='Q';
			a[5]++;
		}
	}
	else
	if(p==3)
	{
		if(s[p]=='I')
		{
			s[p]='Q';
			a[9]++;
		}
	}
	else
	if(p==4)
	{
		if(s[p]=='A')
		{
			s[p]='Q';
			a[0]++;
		}
	}
}
int main()
{
	int t,i,j,k,cs,css;
	int b[500];
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cin>>s;
		for(i=0;i<10;i++)a[i]=0;
		for(i=0;i<500;i++)b[i]=0;
		for(i=0;i<s.sz;i++)
		{
			b[s[i]]++;
		}
		a[0]=b['Z'];
		b['E']-=b['Z'];
		b['R']-=b['Z'];
		b['O']-=b['Z'];
		b['Z']=0;
		
		a[2]=b['W'];
		b['T']-=b['W'];
		b['O']-=b['W'];
		b['W']=0;
		
		a[4]=b['U'];
		b['F']-=b['U'];
		b['O']-=b['U'];
		b['R']-=b['U'];
		b['U']=0;
		
		a[6]=b['X'];
		b['S']-=b['X'];
		b['I']-=b['X'];
		b['X']=0;
		
		a[8]=b['G'];
		b['E']-=b['G'];
		b['I']-=b['G'];
		b['H']-=b['G'];
		b['T']-=b['G'];
		b['G']=0;
		
		a[5]=b['F'];
		b['I']-=b['F'];
		b['V']-=b['F'];
		b['E']-=b['F'];
		b['F']=0;
		
		a[9]=b['I'];
		b['N']-=2*b['I'];
		b['E']-=b['I'];
		b['I']=0;
		
		a[1]=b['O'];
		b['N']-=b['O'];
		b['E']-=b['O'];
		b['O']=0;
		
		a[7]=b['S'];
		a[3]=b['H'];
		cout<<"Case #"<<cs<<": ";
		for(i=0;i<=9;i++)
		{
			for(j=0;j<a[i];j++)cout<<i;
		}
		cout<<endl;
	}
	return 0;
}
