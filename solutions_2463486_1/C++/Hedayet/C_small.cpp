//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647
#define torad(a) (a*pi)/180.0;
#define eps 0.000000001
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;

ll PAL[]={
1LL,
4LL,
9LL,
121LL,
484LL,
10201LL,
12321LL,
14641LL,
40804LL,
44944LL,
1002001LL,
1234321LL,
4008004LL,
100020001LL,
102030201LL,
104060401LL,
121242121LL,
123454321LL,
125686521LL,
400080004LL,
404090404LL,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,
1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL,
};



int main()
{
	freopen("C-large-1.in","r",stdin);
	//freopen("c_output_large.txt","w",stdout);
	int kas;
	cin>>kas;
	rep(cas,kas){
	    ll A,B,ret=0;
	    cin>>A>>B;
	    printf("Case #%d: ",cas+1);
	    rep(i,39)if(PAL[i]>=A&&PAL[i]<=B)ret++;
	    cout<<ret<<endl;
	}

return 0;
}
