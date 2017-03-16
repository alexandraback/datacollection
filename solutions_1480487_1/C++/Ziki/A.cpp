/*************************************************************************
Author: ziki
Created Time: 2012/5/5 23:59:47
File Name: A.cpp
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

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	int n, cas = 1;
	double b[300], a[300];
	cin>>T;
	while(cin>>n)
	{
		double sum = 0;
		for(int i=0; i<n; i++)
		{
			cin>>a[i]; 
			b[i] = a[i];
			sum += a[i];
		}
		sort(b,b+n);
		int t;
	   double ave,	tmp = 0;
		
		for(t = 0; t<n; t++)
		{
			tmp += b[t];
			if(t == n-1 || (sum + tmp)/(t+1) <= b[t+1])
			{
				ave = (sum + tmp)/(t+1);
				break;
			}
		}
		double ans[300];
		for(int i=0; i<n; i++)
			if(a[i]<=ave)
				ans[i] = (ave-a[i])/sum * 100;
			else
				ans[i] = 0;
		printf("Case #%d:",cas++);
		for(int i=0; i<n; i++)
			printf(" %.8lf", ans[i]);
		printf("\n");
	}
	return 0;
}

