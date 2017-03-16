#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<list>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vi >
#define pp pair<int,int>
#define pb push_back
#define mp make_pair
#define ppl pair<ll,ll>
#define vl vector<ll>
#define vll vector<vl >
#define vb vector<bool>
#define llu unsigned ll
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define sc scanf
#define pf printf
ll power(ll a,ll b)
{
	if(!b)
		return 1;
	if(b==1)
		return a;
	ll temp=power(a,b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		temp=(temp*a)%mod;
	return temp;
}
int a1, a2;
string f1, f2;
int diff;

void sub( char t1[], char t2[], int n)
{
	int v1=0,v2=0,cal;
	int i;
	for( i=0;i<n;i++ )
	{
		v1 = v1*10 +(t1[i]-48);
		v2 = v2*10 + (t2[i]-48);
	}
	cal =v1-v2;
	if(cal<0)
		cal = -cal;
	string z1, z2;
	if( diff > cal)
	{
		a1 = v1;
		a2 = v2;
		diff = cal;
		for( i=0;i<n;i++ )
		{
			z1 +=t1[i];
			z2 += t2[i];
		}
		f1 = z1;
		f2 = z2;
	}
	else if( diff==cal)
	{
		if( a1 > v1)
		{
			a1 = v1;
			a2 = v2;
			for( i=0;i<n;i++ )
			{
				z1+=t1[i];
				z2 += t2[i];
			}
			f1 = z1;
			f2 = z2;
		}
		else if(a1==v1)
		{
			if( a2 > v2)
			{
				for( i=0;i<n;i++ )
				{
					z2 += t2[i];
				}
				a2 = v2;
				f2 = z2;
			}
		}
	}
}
void solve( string& s1,string& s2,int index,int n,char t1[],char t2[])
{
	if(index ==n)
	{
		sub(t1,t2,n);
		return;
	}
	int c = 0;
	if( s1[index]=='?')
		c++;
	if( s2[index]=='?')
		c++;
	if( c==2)
	{
		int i,j;
		for( i=0;i<10;i++ )
		{
			for( j=0;j<10;j++)
			{
				char ch;
				ch =(char)(i+48);
				t1[index]=ch;
				ch=(char)(j+48);
				t2[index]=ch;
				solve(s1,s2,index+1,n,t1,t2);
			}
		}
	}
	else if( c==1)
	{
		int i;
		for( i=0;i<10;i++ )
		{
			if( s1[index]=='?')
			{
				char ch;
				ch =(char)(i+48);
				t1[index]=ch;
				t2[index]=s2[index];
			}
			else
			{
				char ch;
				ch =(char)(i+48);
				t2[index]=ch;
				t1[index]=s1[index];
			}
			solve(s1,s2,index+1,n,t1,t2);
		}
	}
	else
	{
		t1[index]=s1[index];
		t2[index]=s2[index];
		solve(s1,s2,index+1,n,t1,t2);
	}
		
}
int main()
{
	ios_base::sync_with_stdio(false);
	//solve();
	freopen( "in.txt","r", stdin );
	freopen( "out.txt", "w", stdout);
	int t, n, k, i, j, ans;
	string s1,s2;
	char t1[10000], t2[100000];
	char ch;
	cin >> t;
	for( k=1;k<=t;k++)
	{
		cin >> s1 >> s2;
		n = s1.length();
		diff  = 100000;
		solve( s1, s2, 0, n, t1, t2); 
		cout <<"Case #"<<k<<": "<<f1<<" "<<f2;
		cout<<"\n";
	}
	//cin >> t;
//	cin >> n;
    return 0;
}
