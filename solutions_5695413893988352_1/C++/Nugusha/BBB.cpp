// __   _   _   _   _____   _   _   _____   _   _       ___
//|  \ | | | | | | /  ___| | | | | /  ___/ | | | |     /   |
//|   \| | | | | | | |     | | | | | |___  | |_| |    / /| |
//| |\   | | | | | | |  _  | | | | \___  \ |  _  |   / / | |
//| | \  | | |_| | | |_| | | |_| |  ___| | | | | |  / /  | |
//|_|  \_| \_____/ \_____/ \_____/ /_____/ |_| |_| /_/   |_|

#include<bits/stdc++.h>
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define fi first
#define se second
#define ll long long
#define pii pair< int, int >
#define MEM(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define S system("pause")
#define R return(0)
#define INF int(1e9)
#define MAX_5 int(1e5+5)
#define MAX_6 int(1e6+6)
#define ll long long
#define tree int h,int l1,int r1
#define left 2*h,l1,(l1+r1)/2
#define right 2*h+1,(l1+r1)/2+1,r1
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
	
	
	
	
//	for(int i=0;idsadsa<N;i++)cout<<v[i]dssadsa<<"==";cout<<endl;
	cout<<S1<<" "<<S2<<endl;
	
}
main()
{

       READ("a.in");WRITE("a.out");
          int tt;
		  cin>>tt;
          for(int q=0;q<tt;q++)
		  {
		  	cin>>s>>s1;
			cout<<"Case #"<<q+1<<": ";
			lp();
		  }

}
