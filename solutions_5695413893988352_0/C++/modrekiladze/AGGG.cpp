#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <set>
#include <stack>
#include <iterator>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;

string s,s1;
string v[100005];
int N=0;
void go(int ind)
{
	if(ind==s.size())
	{
		v[N++]=s;
		return ;
	}
	if(s[ind]=='?')
	{
		for(int i=0;i<=9;i++)
		{
			s[ind]=char(i+'0');
			go(ind+1);
		}
		s[ind]='?';
		return ;
	}else
	go(ind+1);
}
string S1,S2;
int ma;


int ch(string s,string s1)
{
	int res=0;
	for(int i=0;i<s.size();i++)res=res*10+s[i]-'0';
	int res1=0;
	for(int i=0;i<s1.size();i++)res1=res1*10+s1[i]-'0';

//	cout<<s<<" "<<s1<<" " <<abs(res-res1)<<endl;
	return abs(res-res1);
}



void go1(int ind)
{
	if(ind==s1.size())
	{
		for(int i=0;i<N;i++)
		{
			int w=ch(v[i],s1);
			if(w<ma || (w==ma && S1>s))
			{
				ma=w;
				S1=v[i];
				S2=s1;
			}
		}

		return ;
	}
	if(s1[ind]=='?')
	{
		for(int i=0;i<=9;i++)
		{
			s1[ind]=char(i+'0');
			go1(ind+1);
		}
		s1[ind]='?';
		return ;
	}else
	go1(ind+1);
}
void lp()
{
	ma=1000000000;
	N=0;

	go(0);
	go1(0);

	cout<<S1<<" "<<S2<<endl;

}
main()
{

       READ("B-small-attempt1.in");WRITE("a.out");
          int tt;
		  cin>>tt;
          for(int q=0;q<tt;q++)
		  {
		  	cin>>s>>s1;
			cout<<"Case #"<<q+1<<": ";
			lp();
		  }

}
