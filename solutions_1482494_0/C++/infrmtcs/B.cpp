#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "B-small-attempt1.in"
#define fo "B-small-attempt1.out"
//#define fi "input.txt"
//#define fo "output.ans"
#define nmax 2000+5
#define INF 1000000000
using namespace std;
typedef pair<int,int> II;
//VARIABLES
int n,S,res,small,large;
II a[nmax];
bool check[2][nmax];
//FUNCTION PROTOTYPES

void Init();
void Process(int tc);

//MAIN
int main()
{
	int test;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&test);
       for (int i=1;i<=test;++i)
       {
	       Init();
       	Process(i);
	}
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Init()
{
	int p,q;
	res=small=large=S=0;
	memset(a,0,sizeof(a));
	memset(check,true,sizeof(check));
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&p,&q);
		a[i]=II(p,q);
	}
}
void Process(int tc)
{
	int li;
	a[0]=II(INF,INF);
	a[n+1]=II(-INF,-INF);
	while (true)
	{
		if (large<n)
		{
			li=0;
			for (int i=1;i<=n;++i)
			if (check[1][i])
			if (a[i].second<=S)
			if (a[i].second<a[li].second) li=i;
			if (li!=0)
			{
				if (check[0][li])
				{
					S+=2;
					++small;
				} else ++S;
				check[0][li]=check[1][li]=false;
//				cout << li << " " << 2 << endl;
				++res;++large;continue;
			}
		}
		if (small<n)
		{
			li=n+1;
			for (int i=1;i<=n;++i)
			if (check[0][i])
			if (a[i].first<=S)
			if (a[i].second>a[li].second) li=i;
			if (li!=n+1)
			{
				++res;++S;++small;
				check[0][li]=false;
//				cout << li << " " << 1 << endl;
				continue;
			}
		}
		break;
	}
	if (S==2*n) printf("Case #%d: %d\n",tc,res); else printf("Case #%d: Too Bad\n",tc);
}
