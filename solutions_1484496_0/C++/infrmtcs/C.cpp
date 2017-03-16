#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define fi "C-small-attempt1.in"
#define fo "C-small-attempt1.out"
//#define fi "C.INP"
//#define fo "C.OUT"
#define nmax 500+5
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef map<int,VI> MIV;
//VARIABLES
int n;
ll Sx,a[nmax];
bool ok;
MIV my_map;
VI St,St2;
//FUNCTION PROTOTYPES

void Init();
void Process(int test);

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
       	cerr << i << endl;
	}
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Init()
{
	Sx=0ll;St.clear();
	memset(a,0,sizeof(a));
	my_map.clear();
	scanf("%d",&n);
	for (int i=0;i<n;++i) cin >> a[i];
}
void Result(int k)
{
	VI::iterator it;
	if (k==n/2)
	{
		if (my_map.find(Sx)==my_map.end()) my_map[Sx]=St;
	} else
	if (my_map.find(-Sx)!=my_map.end())
	{
		St2=my_map[-Sx];
//		for (it=St.begin();it!=St.end();++it) cout << *it << " "; cout << endl;
//		for (it=St2.begin();it!=St2.end();++it) cout << *it << " "; cout << endl;
		for (it=St.begin();it!=St.end();++it)
		if (*it==1) printf("%d ",a[it-St.begin()+n/2+1]);
		for (it=St2.begin();it!=St2.end();++it)
		if (*it==1) printf("%d ",a[it-St2.begin()]);
		putchar('\n');
		for (it=St.begin();it!=St.end();++it)
		if (*it==-1) printf("%d ",a[it-St.begin()+n/2+1]);
		for (it=St2.begin();it!=St2.end();++it)
		if (*it==-1) printf("%d ",a[it-St2.begin()]);
		putchar('\n');
		ok=true;
	}
}
void Try(int i, int k)
{
	for (int j=-1;j<=1;++j)
	{
		St.push_back(j);
		Sx+=a[i]*ll(j);
		if (i==k) Result(k); else Try(i+1,k);
		if (ok) return;
		Sx-=a[i]*ll(j);
		St.pop_back();
	}
}
void Process(int test)
{
	ok=false;
	printf("Case #%d:\n",test);
	Try(0,n/2);
	Try(n/2+1,n-1);
	if (!ok) printf("Impossible\n");
}
