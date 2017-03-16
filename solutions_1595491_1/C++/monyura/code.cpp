#pragma comment(linker,"/STACK:250000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define ind second

const double PI=acos(-1.0);

vector<string> split(string str,string sep)
{
	char *S=new char[str.size()+2];
	char *Sep=new char[sep.size()+2];
	strcpy(S,str.c_str());
	strcpy(Sep,sep.c_str());
	vector<string> res;
	for (char *curr=strtok(S,Sep);curr;curr=strtok(0,Sep))
		res.push_back(curr);
	delete []S;
	delete []Sep;
	return res;
}
template<class T> T SQR(const T &a){return a*a;}

map<char,char> mp;

void test(int Test)
{
	int n,s,p;
	cin>>n>>s>>p;
	int cnt=0,cntSB=0;
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		bool can=0;
		if (a%3==0 && a/3>=p) can=1;
		if (a%3>=1 && a/3+1>=p) can=1;
		if (can)
		{
			cnt++;
		}
		else if (a>=2 && a<=28)
		{
			if (a%3<=1 && a/3+1>=p)
				can=1;
			if (a%3==2 && a/3+2>=p)
				can=1;
			if (can)
				cntSB++;
		}
	}
	cnt+=min(cntSB,s);
	printf("Case #%d: %d\n",Test,cnt);
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t;	
	cin>>t;
	cin.get();
	rep(i,0,t)
		test(i+1);
	return 0;
}

/*
*/