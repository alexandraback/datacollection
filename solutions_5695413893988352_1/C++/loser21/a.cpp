#include <bits/stdc++.h>
 
 
 
#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&x)
#define LL long long
#define F first
#define S second
#define pb push_back
#define mod (LL)(1e9+7)
#define LL long long
#define VVI vector< vector<int> >
#define maxn 1000100
#define MAXL 18
#define pii pair<int,int>
#define vpi vector< pair<int,int> >
#define vvpi vector< vector<pair<int,int>> >
#define pi acos(-1)
#define eps 1e-8

using namespace std;




LL num(string s)
{
	LL res =0;
	for(int i=0;i<s.length();i++)
		res = 10*res + (s[i]-'0');
	return res;
}	

string ans1,ans2;
int cur = -1,c=-1,j=-1;
int len;

void f(string s1,string s2,int i,int st)
{

	if(i==len)
	{
		LL n1 = num(s1);
		LL n2 = num(s2);
		if(cur==-1 || abs(n1-n2)<cur)
		{
			cur = abs(n1-n2);
			c=n1;
			j=n2;
			ans1=s1;
			ans2=s2;
		}
		else if(abs(n1-n2)==cur)
		{
			if(n1<c)
			{
				ans1=s1;
				ans2=s2;
				c=n1;
				j=n2;
			}
			else if(n1==c && n2<j)
			{
				ans1=s1;
				ans2=s2;
				c=n1;
				j=n2;	
			}
		}
		return;
	}

	if(st==1)
	{
		//cout << "in1\n";
		if(s1[i]=='?' && s2[i]=='?')
		{
			s1[i]='0';
			s2[i]='9';
		}
		else if(s1[i]=='?')
			s1[i]='0';
		else if(s2[i]=='?')
			s2[i]='9';
		f(s1,s2,i+1,st);
	}
	else if(st==2)
	{
		//cout << "in2\n";
		if(s1[i]=='?' && s2[i]=='?')
		{
			s1[i]='9';
			s2[i]='0';
		}
		else if(s1[i]=='?')
			s1[i]='9';
		else if(s2[i]=='?')
		{
			s2[i]='0';	
		}
		f(s1,s2,i+1,st);
	}
	else
	{
		if(s1[i]=='?' && s2[i]=='?')
		{

				s1[i]='0';
				s2[i]='0';
				f(s1,s2,i+1,st);
				s1[i]='1';
				s2[i]='0';
				f(s1,s2,i+1,1);
				s1[i]='0';
				s2[i]='1';
				f(s1,s2,i+1,2);
		}
		else if(s1[i]=='?' || s2[i]=='?' )
		{
				if(s1[i]=='?')
				{
					s1[i]=s2[i];
					f(s1,s2,i+1,st);
					if(s2[i]>='1')
					{
						s1[i]=s2[i]-1;
						f(s1,s2,i+1,2);
					}
					if(s2[i]<='8')
					{
						s1[i]=s2[i]+1;
						f(s1,s2,i+1,1);
					}

				}
				else
				{
					s2[i]=s1[i];
					f(s1,s2,i+1,st);
					if(s1[i]>='1')
					{
						s2[i]=s2[i]-1;
						f(s1,s2,i+1,1);
					}
					if(s1[i]<='8')
					{
						s2[i]=s1[i]+1;
						f(s1,s2,i+1,2);
					}

				}
		}
		else
		{
	//		cout << "in" << endl;
			if(s1[i]>s2[i])
				st=1;
			else if(s1[i]<s2[i])
				st=2;
			else
				st=0;
			f(s1,s2,i+1,st);
		}
	}



}





int main()
{
	int t;
	icin(t);

	for(int tc=1;tc<=t;tc++)
	{
		cur = -1,c=-1,j=-1;
		string s1,s2;
		cin >> s1 >> s2;
		len=s1.length();
		int st=0;
		f(s1,s2,0,0);
		cout << "Case #" << tc << ": " << ans1 << " " << ans2 << endl;

	}
}