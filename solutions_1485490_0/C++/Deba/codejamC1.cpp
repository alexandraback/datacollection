
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

#define CLR(x) memset((x),0,sizeof(x))
#define pb push_back
#define sz size()
#define FOR(i,n) for(i=0;i<n;i++)
#define FORALL(i,x) for(i=0;i<x.size();i++)
#define FORALLR(i,x) for(i=x.size()-1;i>=0;i--)
#define SWAP(x,y) (x)+=(y);y=(x)-(y);x=(x)-(y);
#define lint int

#define INF 1<<30

typedef vector<int> vi;
typedef vector<string> vs;

int cases,caseno;
int iN, iM;
int a[1001];
int A[1001];

int m[1001];
int M[1001];
int MAX = 0;
void input()
{
	int i;
	cin >> iN >> iM;
	FOR(i,iN)
	{
		cin >> a[i] >> A[i];
	}
	FOR(i,iM)
	{
		cin >> m[i] >> M[i];
	}
	
}
int getMax( int a, int b)
{
	return ( a > b)? a : b;
}
void  backTrack(int ai,int mi,int CNT)
{
	if( ai == iN )
	{
		MAX = getMax(MAX,CNT);			
		return;
	}
	int i, now = a[ai];
	backTrack(ai+1,mi,CNT );
	for(i=mi+1;i<iM;i ++ )
	{
		if(M[i]==A[ai] )
		{
			int cur=now<m[i]?now:m[i];
			CNT += cur, now -= cur;			
			m[mi] -= cur;
			backTrack(ai+1,i-1,CNT );			
			m[mi] += cur;
		}		
		backTrack(ai+1,i,CNT );			
	}

}
void process()
{
	backTrack(0,-1,0);
	cout << "Case #"<< (++caseno)<< ": "<< MAX << endl;
}
int main()
{
	freopen("input.txt", "r", stdin );
	freopen("outC1.txt", "w", stdout );
	MAX = 0;
	cin >> cases;
	while( cases-- )
	{
		MAX = 0;
		input();
		process();
	}
}