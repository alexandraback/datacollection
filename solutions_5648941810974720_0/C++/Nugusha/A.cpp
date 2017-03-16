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
int a[100005];
int v[100005];
void mi(string s)
{
	for(int i=0;i<s.size();i++)
		a[s[i]]--;
	
}

/*
ZERO
SIX
EIGHT
TWO
SEVEN
THREE

FOUR
FIVE
ONE

NINE
*/
string sol(string s)
{
	int N=0;
	for(int i='A';i<='B';i++)a[i]=0;
	
	for(int i=0;i<s.size();i++)
		a[s[i]]++;
		
		
	while(a['Z'])
	{
		v[N++]=0;
		
		mi("ZERO");
	}
		
	while(a['X'])
	{
		v[N++]=6;
		
		mi("SIX");
	}
	
	
		
	while(a['G'])
	{
		v[N++]=8;
		
		mi("EIGHT");
	}
	
	
		
	while(a['W'])
	{
		v[N++]=2;
		
		mi("TWO");
	}
	
	while(a['S'])
	{
		v[N++]=7;
		
		mi("SEVEN");
	}
	while(a['T']>0)
	{
		v[N++]=3;
		
		mi("THREE");
	}
	
	while(a['R'])
	{
		v[N++]=4;
		
		mi("FOUR");
	}
	
	
	
	
	
		
	
		
	while(a['V'])
	{
		v[N++]=5;
		
		mi("FIVE");
	}
	
	
		
	while(a['O'])
	{
		v[N++]=1;
		
		mi("ONE");
	}
	
	
	while(a['N']>0)
	{
		v[N++]=9;
		
		mi("NINE");
	}
	

	
	
	
	
	
	
	
	string s1;
	sort(v,v+N);
	
	for(int i=0;i<N;i++)
		s1+=char(v[i]+'0');
	
	
	
	
	
	return s1;
}
main()
{

       READ("a.in");WRITE("a.out");
          int tt;
		  cin>>tt;
		  string s;
          for(int q=0;q<tt;q++)
		  {
		  	cin>>s;
			cout<<"Case #"<<q+1<<": ";
			cout<<sol(s)<<endl;;
		  }

}
