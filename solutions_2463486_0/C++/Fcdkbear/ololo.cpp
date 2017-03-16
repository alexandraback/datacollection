#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
int cnt1=0,cnt2=0;
bool ispal(LL num)
{
	stringstream tmp;
	tmp<<num;
	string s1,s2;
	tmp>>s1;
	s2=s1;
	reverse(s2.begin(),s2.end());
	return (s1==s2);
}
string mul(string s1)
{
	string res;
	FOR(i,0,s1.size()+s1.size())
		res+='0';
	FOR(i,0,s1.size())
	{
		int p=0;
		for (int j=0; j<s1.size() || p; ++j)
		{
			int v=0;
			if (j<s1.size())
				v=s1[j]-'0';
			int k=(s1[i]-'0')*v+p+(res[i+j]-'0');
			res[i+j]=k%10+'0';
			p=k/10;
		}
	}
	while ((res.back()=='0') && (res.size()>1))
		res.pop_back();
	return res;
}
bool check1(string s, string A)
{
	if (s.size()>A.size())
		return true;
	if (s.size()<A.size())
		return false;
	FOR(i,0,s.size())
	{
		if (s[i]>A[i])
			return true;
		if (s[i]<A[i])
			return false;
	}
	return true;
}
bool check2(string s, string A)
{
	if (s.size()<A.size())
		return true;
	if (s.size()>A.size())
		return false;
	FOR(i,0,s.size())
	{
		if (s[i]<A[i])
			return true;
		if (s[i]>A[i])
			return false;
	}
	return true;
}
bool ispal1(string s)
{
	string s1=s;
	reverse(s1.begin(),s1.end());
	return (s==s1);
}
string A,B;
int go(string s)
{
	if (s.size()>51)
		return 0;
	string s1=s.substr(0,s.size()/2);
	string s2=s.substr(s.size()/2,s.size()/2);
	int res=1;
	FOR(i,0,3)
	{
		char c1='0'+i;
		string s3=s1+c1+s2;
		string s4=mul(s3);
		if (ispal1(s4) && (check1(s4,A) && (check2(s4,B))))
		{
			cnt2++;
			res++;
		}
		s3=s1+c1;
		s3+=c1;
		s3+=s2;
		s4=mul(s3);
		if (ispal1(s4) && (check1(s4,A) && (check2(s4,B))))
		{
			res+=go(s3);
		}
	}
	return res;
}

int main()
{
#ifdef Fcdkbear
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double beg=clock();
#else
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	FOR(it,0,t)
	{
		printf("Case #%d: ",it+1);
		cin>>A>>B;
		int res=0;
		if ((check1("1",A)) && (check2("1",B)))
			res++;
		if ((check1("4",A)) && (check2("4",B)))
			res++;
		if ((check1("9",A)) && (check2("9",B)))
			res++;
		if ((check1("121",A)) && (check2("121",B)))
			res+=go("11");
		if ((check1("484",A)) && (check2("484",B)))
			res+=go("22");
		printf("%d\n",res);
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}