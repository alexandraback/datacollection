//#define DEBUG_TEST 1


#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>

using namespace std;

#define PB push_back
#define PF push_front
#define FOR0(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORN0(i,n) for(int i=n;i>=0;i--)
#define FORN1(i,n) for(int i=n;i>=1;i--)
#ifdef DEBUG_TEST
# define DEBUG(X) cout << #X << " = " << (X) << endl;
#else
# define DEBUG(X) while(0){}
#endif


int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

const double pi = atan(1.0)*4.0;
typedef long long ll;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<ll> VLL;

typedef list<int> LI;
typedef list<char> LC;
typedef list<LI> LLI;
typedef list<LC> LLC;
typedef list<ll> LLL;

typedef VI::iterator IT_VI;
typedef VC::iterator IT_VC;
typedef VVI::iterator IT_VVI;
typedef VVC::iterator IT_VVC;
typedef VLL::iterator IT_VLL;

typedef LI::iterator IT_LI;
typedef LC::iterator IT_LC;
typedef LLI::iterator IT_LLI;
typedef LLC::iterator IT_LLC;
typedef LLL::iterator IT_LLL;


int comparechar(const void* a,const void* b)
{
	if(*(char*)a==*(char*)b)
		return 0;
	if(*(char*)a<*(char*)b)
		return -1;
	if(*(char*)a>*(char*)b)
		return 1;
}


void solve()
{
	int j,p,s,k;
	int jp[10][10],js[10][10],ps[10][10];
	int total=0;
	int output[1005][3];
	scanf("%d%d%d%d",&j,&p,&s,&k);
	FOR0(x,10)
	{
		FOR0(y,10)
		{
			jp[x][y]=0;
			js[x][y]=0;
			ps[x][y]=0;
		}
	}
	for(int x=1;x<=j;x++)
	{
	
		for(int y=1;y<=p;y++)
		{
			for(int z=1;z<=s;z++)
			{
				if( jp[x][y]<k && js[x][z]<k && ps[y][z]<k)
				{
					total++;
					jp[x][y]++;
					js[x][z]++;
					ps[y][z]++;
					output[total-1][0]=x;
					output[total-1][1]=y;
					output[total-1][2]=z;
					//sprintf(output,"%d %d %d\n",x,y,z);
				}
			}
		}
	}

	printf("%d\n",total);
	FOR0(i,total)
	{
		printf("%d %d %d\n",output[i][0],output[i][1],output[i][2]);
	}

}


int main() {

	int no_test;

	//freopen("Cinput.txt", "r", stdin);


freopen("Csmall.in", "r", stdin);	 
freopen("Csmallout.txt", "w", stdout);


//freopen("Clarge.in", "r", stdin);
//freopen("Clargeout.txt", "w", stdout);

	cin>>no_test;
	FOR1(test,no_test) {
		DEBUG(test)
		printf("Case #%d: ",test);
		solve();
		//printf("\n");
	}
	return 0;
}

