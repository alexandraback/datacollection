#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
long long int mod=1000000007;
struct letter
{
	long long int beg_with,end_with,whole,within;
};
long long int fact(long long int n)
{
	if(n==0)
		return 1;
	else
		return (n*fact(n-1))%mod;
}
int main()
{
	freopen("bs.in","r",stdin);
	freopen("b_small.out","w",stdout);
	int t;
	cin>>t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		int n;
		cin>>n;
		vector <string> A(n);
		letter temp;
		//
		temp.beg_with=0;
		temp.end_with=0;
		temp.whole=0;
		temp.within=0;
		//
		bool ans_exist=true;
		vector <letter> B(26,temp);
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
			int sz=A[i].length();
			char sw=A[i][0],ew=A[i][sz-1];
			bool wh=true;
			for (int j = 0; j < sz; ++j)
			{
				if(A[i][j]!=sw)
				{
					wh=false;
					break;
				}
			}
			if(wh)
			{
				B[sw-'a'].whole++;
				continue;
			}
			vector <int> visited(26,-1);
			B[sw-'a'].beg_with++;
			B[ew-'a'].end_with++;
			for (int j = 0; j < sz; ++j)
			{
				if(A[i][j]!=sw && A[i][j]!=ew)
					B[A[i][j]-'a'].within++;
				if(visited[A[i][j]-'a']==-1)
				{
					visited[A[i][j]-'a']=j;
				}
				else
				{
					if(visited[A[i][j]-'a']==j-1)
						visited[A[i][j]-'a']=j;
					else
					{
						ans_exist=false;
						break;
					}
				}
			}
		}
		long long int ans=1,pieces=0;
		for (int i = 0; i < 26; ++i)
		{
			ans%=mod;
			if(B[i].end_with>1 || B[i].beg_with>1)
			{
				ans_exist=false;
				break;
			}
			if(B[i].within>0 &&(B[i].end_with || B[i].beg_with || B[i].whole))
			{
				ans_exist=false;
				break;
			}
			if(B[i].beg_with==0 && B[i].end_with==0 && B[i].whole==0)
			{
				continue;
			}
			if(B[i].beg_with==0 && B[i].end_with==0 && B[i].whole>0)
			{
				ans*=fact(B[i].whole);
				pieces+=2;
				continue;
			}
			if(B[i].beg_with>0 || B[i].end_with>0)
			{
				if(B[i].beg_with==0 || B[i].end_with==0)
				{
					pieces+=2;
				}
				ans*=fact(B[i].whole);
				continue;
			}
		}
		ans*=fact(pieces/2);
		ans%=mod;
		if(!ans_exist)
			ans=0;
		cout<<"Case #"<<test_case<<": "<<ans<<"\n";
	}
	return 0;
}