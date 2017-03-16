#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vit vi::iterator
#define vpi vector<pii >
#define sq(x) (x)*(x)

int gettop(int a)
{
	int res = 1;
	while(res<=a)
		res*=10;
	return res/10;
}

bool redo(int& a, int top)
{
	int ost = a%10;
	a/=10;
	a+=top*ost;
	return ost>0;
}

vector<pii> res1;
vector<pii> res2;
bool isshift(int a, int b)
{
	if(a==b)
		return false;
	bool can = false;
	int top = gettop(b);
	for(int i=0; i<4; ++i)
	{
		can = redo(b, top);
		if(can && b == a)
			return true;
	}
	return false;
}


void test(int t)
{
	//res1.clear();
	//res2.clear();
	int a,b;
	scanf("%d%d",&a,&b);
	int top = gettop(a);
	int answ = 0;
	for(int i=a; i<=b; ++i)
	{
		if(top*10<=i)
			top*=10;
		int k = i;
		bool can = redo(k, top);
		while(k!=i)
		{
			if(can && k<i && k>=a)
			{
				++answ;
				res1.push_back(pii(i,k));
			}
			can = redo(k, top);
		}
	}
	/*for(int i=a; i<=b; ++i)
		for(int j=a; j<i; ++j)
			if(isshift(i,j))
				res2.push_back(pii(i,j));
	sort(res1.begin(), res1.end());
	sort(res2.begin(), res2.end());
	for(int i=0; i<res2.size(); ++i)
		if(res2[i]!=res1[i])
		{
			printf("%d %d\n",res1[i].first, res1[i].second);
			break;
		}
	printf("%d\n",res2.size());*/
	printf("Case #%d: %d\n",t,answ);
}

int main()
{
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0; i<t; ++i)
		test(i+1);
	return 0;
}