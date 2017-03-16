#include <vector>
#include <map>
//#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int k,l,s;
char keyboard[102];
char pat[102];
int lps[102];
int f[102][102];
double f2[102][102];

void computeLPSArray() {
	int len = 0, i;
	lps[0] = 0; //lps[0] is always 0
	i = 1;
	while(i < l) {
		if(pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if(len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int g(int i,int j)
{
	if(i==s) return 0;
	int&res=f[i][j];
	if(res!=-1) return res;
	res=0;
	for(int alpha=0;alpha<k;++alpha)
	{
		char now=keyboard[alpha];
		int t_i=i,t_j=j;
		while(t_i==i)
		{
			if(pat[j]==now)
			{
				++i,++j;
				res=max(res,(j==l?1+g(i,lps[j-1]):g(i,j)));
				break;
			}
			else
			{
				if(j!=0)
					j=lps[j-1];
				else
				{
					res=max(res,g(i+1,j));
					break;
				}
			}
		}
		i=t_i,j=t_j;
	}
	return res;
}

double G(int i,int j)
{
	if(i==s) return 0;
	double&res=f2[i][j];
	if(res==res) return res;
	res=0.0;
	for(int alpha=0;alpha<k;++alpha)
	{
		char now=keyboard[alpha];
		int t_i=i,t_j=j;
		while(t_i==i)
		{
			if(pat[j]==now)
			{
				++i,++j;
				res+=(j==l?1.0+G(i,lps[j-1]):G(i,j));
				break;
			}
			else
			{
				if(j!=0)
					j=lps[j-1];
				else
				{
					res+=G(i+1,j);
					break;
				}
			}
		}
		i=t_i,j=t_j;
	}
	res/=k;
	return res;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("o.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d%d%d",&k,&l,&s);
		scanf(" %s",keyboard);
		scanf(" %s",pat);
		computeLPSArray();
		memset(f,-1,sizeof(f));
		memset(f2,-1,sizeof(f2));
		int max_bananas=g(0,0);
		double expected_take=G(0,0);
		printf("%.12lf\n",max_bananas-expected_take);
	}
	return 0;
}