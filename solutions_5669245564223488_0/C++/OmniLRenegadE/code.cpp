#pragma comment(linker, "/STACK:64000000")
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (LL i=0;i<n;i++)
#define rforn(i,n) for (LL i=n-1;i>=0;i--)
#define kforn(i,l,r) for (LL i=l;i<=r;i++)
#define mp make_pair
#define __int64 long long
#define LL long long

int f[256];
int pr[256];
int suff[256];
int dd[256];
int cnt[256];

const LL mod = 1000000007;

LL get(int pos, vector <bool> &fl){
	if (fl[pos])
		return 0;
	if (f[pos]==0 && pr[pos]==-1 && suff[pos]==-1)
		return 0;

	fl[pos]=1;
	LL buf=1;
	for (int i=1;i<=f[pos];i++)
		buf=(buf*i)%mod;

	if (suff[pos]!=-1)
	{
		kforn(i,'a','z')
			if (suff[pos]==pr[i]){
				buf=(buf*get(i, fl))%mod;
			}
	}

	return buf;
}

int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T;
	cin>>T;
	int n;
	vector <string> s;
	vector <int> w;
	vector <bool> fl;
	vector <LL> ch;
		
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";

		cin>>n;
		s.resize(n);
		forn(i,n)
		{
			cin>>s[i];
		}
		bool can=true;

		kforn(i,'a','z')
		{
			f[i]=0;
			pr[i]=-1;
			suff[i]=-1;
			cnt[i]=0;
			dd[i]=0;
		}

		int was[256]={0};
		forn(i,n)
		{			
			forn(j,s[i].length())
			{
				cnt[s[i][j]]++;
				if (s[i][j]!=s[i].front() && s[i][j]!=s[i].back())
					if (was[s[i][j]] != i+1){
						dd[s[i][j]]++;
						was[s[i][j]]=i+1;
					}
			}
		}

		forn(i,n)
		{
			if (s[i].front() == s[i].back())
			{
				forn(j,s[i].length())
					if (s[i][j]!=s[i][0]){
						can = false;
					}
				if (can)
				{
					f[s[i][0]]++;
				}
			}
			else
			{
				bool was[256]={0};
				char prev=0;

				forn(j,s[i].length())
				{
					if (prev!=s[i][j] && was[s[i][j]]==1){
						can = false;
						break;
					}
					prev = s[i][j];
					was[s[i][j]]=1;
				}

				if (suff[s[i].front()] != -1)
					can = false;
				else
					suff[s[i].front()]=i;

				if (pr[s[i].back()] != -1)
					can = false;
				else
					pr[s[i].back()]=i;
			}

			if (!can)
				break;
		}

		kforn(i,'a','z')
		{
			if (pr[i]!=-1 || suff[i]!=-1 || f[i]!=0){
				if (dd[i]>0)
					can=false;
			}
			else
			{
				if (dd[i]>1)
					can=false;
			}
		}

		LL res=0;
		LL buf;
		ch.clear();
		
		if (can){
			res=1;
			fl.assign(256,0);
			kforn(i,'a','z') {
				if (pr[i]!=-1)
					continue;

				buf=get(i,fl);
				if (buf > 0){
					ch.push_back(buf);
				}
			}

			for (int i=1;i<=ch.size();i++)
			{
				res=(res*i)%mod;
				res=(res*ch[i-1])%mod;
			}

			kforn(i,'a','z'){
				if (fl[i]==0 && (pr[i]!=-1 || suff[i]!=-1 || f[i]!=0))
					res=0;
			}
		}

		cout<<res<<"\n";
	}

}