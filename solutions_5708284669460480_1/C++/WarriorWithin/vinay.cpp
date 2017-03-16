#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include <map>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<cassert>
using namespace std;
 
#define DEBUG //on-off switch for prlling statements
 
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
 
// Useful constants
#define INF                        1000000005
#define EPS                         1e-12
 
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
 
// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(ll i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
 
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((ll)(a.size()))
 
// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
 
#define ll long long int
#define llu long long unsigned
#define ld long
 #define mod 1000000007
#define F first
#define S second
#define pb push_back
#define B 29
int lps[201];
void computeLPSArray(string pat)
{
		int M=pat.size();
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
double dp[103][103][103];
double prob[26];
int vis[26];
void solve(int t)
{	
	fill(prob,0);
	fill(vis,0);
	int n,m,s;
	s(m);
	s(n);
	s(s);
	string b;
	string a;
	cin >> b;
	cin >> a;
	int cnt=0;
	int len=0;
	int pos=0;
	computeLPSArray(a);
	while(1)
	{
		len= len+n-pos;
		if(len > s)
		break;
		cnt++;
		pos=lps[n-1];
	}
	for(int i=0;i<b.size();i++)
	{
		vis[b[i]-'A']++;
	}
	for(int i=0;i<26;i++)
	{
		prob[i] = ((double)vis[i])/m;
	}
	double val=0;
	for(int i=0;i<n;i++)
	{
		if(prob[a[i]-'A'] < EPS)
		{
			printf("Case #%d: 0.000000000\n",t);
			return;
		}
	}
	fill(dp,0);
	computeLPSArray(a);
	dp[0][0][0] = 1;
	for(int i=0;i<=s;i++)
	{
		for(int j=0;j<=s;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int c=0;c<26;c++)
				{
					double p=prob[c];
					double add = dp[i][j][k]*p;
					int l=k;
					char d=c+'A';
					while(1)
					{
						if(a[l] == d)
						{
							if(l!= n-1)
							dp[i+1][j][l+1] += add;
						 	else
						 	dp[i+1][j+1][lps[l]] += add;
						 	break;
						}
						else
						{
							if(l == 0)
							{
								dp[i+1][j][0] += add;
								break;
							}
							else
							{
								l=lps[l-1];
							}
						}
					}
				}
			}
		}
	}
	//cout<<dp[1][0][1]<<endl;
	double exp=0;
	for(int j=0;j<=s;j++)
	{
		for(int k=0;k<n;k++)
		{
			exp=exp+j*dp[s][j][k];
		}
	}
	//int maxi=s-n+1;
	printf("Case #%d: %0.9lf\n",t,cnt-exp);
}	
	

int main()
{
	int t;
	s(t);
	for(int i=0;i<t;i++)
	solve(i+1);
}