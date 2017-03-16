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

bool B[2000002]={0};
void test(int Test)
{
	int a,b;
	scanf("%d%d",&a,&b);
	int len=0;
	int ten=1;
	int tmp=a;
	while (tmp)
	{
		len++;
		ten*=10;
		tmp/=10;
	}
	ten/=10;
	int res=0;
	int A[7];
	int pos;
	rep(i,a,b)
	{
		int c=i;
		int st=c%10;
		pos=0;
		rep(j,0,len)
		{
			int d=c/10+c%10*ten;
			if (a<=d && d<=b && d>i && !B[d])
			{
				res++;
				B[d]=1;
				A[pos++]=d;
			}
			c=d;
		}
		rep(j,0,pos)
			B[A[j]]=0;
	}
	printf("Case #%d: %d\n",Test,res);
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int t;	
	cin>>t;
	cin.get();
	rep(i,0,t)
		test(i+1);
	return 0;
}

/*
*/