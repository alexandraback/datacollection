#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef vector<int> vi;


#define MAX_N 105

int k,l,s;
char keys[MAX_N],t[MAX_N],out[MAX_N];
double prop[30];
int best;
double ans;

int g()
{
	int r=0;
	for (int i=0; i+l-1<s; i++)
	{
		bool work=true;
		for (int j=0; work&&j<l; j++)
			work=out[i+j]==t[j];
		if (work)
			r++;
	}
	return r;
}

void f(int i, double p)
{
	if (i==s)
	{
		int in=g();
		best=max(best,in);
		ans+=in*p;
		return;
	}
	for (int j=0; j<26; j++)
		if (prop[j]!=0)
		{
			out[i]=j+'A';
			f(i+1,p*(prop[j]/k));
		}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int asdf=1; asdf<=tc; asdf++)
	{
		scanf("%d %d %d",&k,&l,&s);
		scanf("%s",keys);
		for (int i=0; i<30; i++)
			prop[i]=0;
		for (int i=0; i<k; i++)
			prop[keys[i]-'A']++;
		scanf("%s",t);
		bool can=true;
		for (int i=0; can&&i<l; i++)
			can&=prop[t[i]-'A']!=0;
		printf("Case #%d: ",asdf);
		if (!can)
		{
			printf("%.10lf\n",0.);
			continue;
		}
		best=0;
		ans=0;
		f(0,1.);
		printf("%.10lf\n",best-ans);
	}
	return 0;
}
