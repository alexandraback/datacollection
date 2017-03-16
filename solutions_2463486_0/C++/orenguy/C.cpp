#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<deque>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
#include<set>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
int MAXINT = 2147483647;
LL INFLL = 1000000000000000000LL;
LL MAXLL = 9223372036854775807LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define SIZE(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define RESET(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a,b) for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); (a)++)
#define MIN(a, b) (a) = min((a), (b))
#define MAX(a, b) (a) = max((a), (b))
#define PAUSE system("pause")

#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)

pii M[8] = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1),mp(-1,1),mp(-1,-1),mp(1,-1),mp(1,1)};

/*\   \
\   \*/

LL palin[71] = {0, 1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002, 100000001, 100010001, 100020001, 100101001, 100111001, 100121001, 101000101, 101010101, 101020101, 101101101, 101111101, 110000011, 110010011, 110020011, 110101011, 110111011, 111000111, 111010111, 111101111, 111111111, 200000002, 200010002};

int main()
{
	int t;
	scanf("%d",&t);
	FOR(tc,1,t)
	{
		LL A,B;
		cin >> A >> B;
		int ans = 0;
		FOR(a,1,70)
		{
			if (A <= palin[a]*palin[a] && palin[a]*palin[a] <= B) ans++;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	/*
	FOR(b,1,10000)
	{
		string q1="",p1="";
		LL q = b;
		while(q != 0)
		{
			char y = ((q%10)+'0');
			q1 = y + q1;
			q /= 10;
		}
		LL p = b*b;
		while(p != 0)
		{
			char y =((p%10)+'0') ;
			p1 =  y+ p1;
			p /= 10;
		}
		bool bisa = 1;
		FOR(a,0,q1.length()-1)
		{
			if (q1[a] != q1[q1.length()-1-a]) bisa = 0;
		}
		FOR(a,0,p1.length()-1)
		{
			if (p1[a] != p1[p1.length()-1-a]) bisa = 0;
		}
		if (bisa) cout << b*b << endl;
	}*/
}
