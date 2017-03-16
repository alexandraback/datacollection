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
string s1,s2;
int dif;
int an1,an2;
string a1,a2;
void fnn()
{
	int i,j,k,v1=0,v2=0;
	for(i=0;i<s1.sz;i++)
	{
		v1=v1*10+s1[i]-'0';
		v2=v2*10+s2[i]-'0';
	}
	k=v1-v2;
	if(k<0)k=-k;
	if(k<dif)
	{
		dif=k;
		an1=v1;a1=s1;
		an2=v2;a2=s2;
	}
	else
	if(k==dif && (v1<an1 || (v1==an1 && v2<an2)))
	{
		dif=k;
		an1=v1;a1=s1;
		an2=v2;a2=s2;
	}
}
void fn(int p)
{
	if(p==s2.sz)
	{
		fnn();
		return;
	}
	if(s2[p]=='?')
	{
		int i,j,k;
		for(i=0;i<10;i++)
		{
			s2[p]='0'+i;
			fn(p+1);
		}
		s2[p]='?';
		return;
	}
	fn(p+1);
}
void fun(int p)
{
	if(p==s1.sz)
	{
		fn(0);
		return;
	}
	if(s1[p]=='?')
	{
		int i,j,k;
		for(i=0;i<10;i++)
		{
			s1[p]='0'+i;
			fun(p+1);
		}
		s1[p]='?';
		return;
	}
	fun(p+1);
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cin>>s1>>s2;
		dif=100000000;
		fun(0);
		cout<<"Case #"<<cs<<": ";
		cout<<a1<<" "<<a2<<endl;
	}
	return 0;
}
