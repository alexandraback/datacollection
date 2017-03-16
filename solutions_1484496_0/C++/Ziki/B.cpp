/*************************************************************************
Author: ziki
Created Time: 2012/5/6 0:35:35
File Name: B.cpp
Description: 
************************************************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>


using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define zero(a) memset(a, 0, sizeof(a))
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

int s;
int64 a[505];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int cas = 1; cas<=T; cas++)
	{
		printf("Case #%d:\n", cas);
		cin>>s;
		for(int i=0; i<s; i++)
			cin>>a[i];
		map<int64, int> mp;
		sort(a,a+s);
		int ans1, ans2;
		for(int i=1; i<(1<<20); i++)
		{
			int64 t = 0;
			for(int j=0; j<20; j++)
				if(i&(1<<j)) t += a[j];
			
			if(mp.count(t))
			{
				bool flag = true;
				int v = mp[t];
				//for(int j=0; j<20; j++)
					//if(
				ans1 = v;
				ans2 = i;
				break;
			}
			else
				mp[t] = i;
		}
		int tb = ans1&ans2;
		ans1 -= tb; ans2 -= tb;
		bool f = false;
		for(int i=0; i<20; i++)
			if((1<<i)&ans1)
			{
				if(!f){
					f = true;
					printf("%d",a[i]);
				}
				else
					printf(" %d",a[i]);
			}
		printf("\n");

		f = false;
		for(int i=0; i<20; i++)
			if((1<<i)&ans2)
			{
				if(!f){
					f = true;
					printf("%d",a[i]);
				}
				else
					printf(" %d",a[i]);
			}
		printf("\n");
	}

	return 0;
}

