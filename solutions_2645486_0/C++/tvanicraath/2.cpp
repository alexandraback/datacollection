/*
                                                     _     
                       o                            | |    
_|_       __,   _  _       __   ,_    __,   __, _|_ | |    
 |  |  |_/  |  / |/ |  |  /    /  |  /  |  /  |  |  |/ \   
 |_/ \/  \_/|_/  |  |_/|_/\___/   |_/\_/|_/\_/|_/|_/|   |_/
                                                           
                                                           
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mfor(i,e)	for(int i = 0; i < e; i++)
#define mford(i,s,e)	for(int i = s; i > e; i--)
//#define FORE(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define mfori(i,s,e)	for(int i = s; i < e; i++)
#define in(x)		(x = getc(stdin))
#define MP			make_pair
#define out(x)		putc(x, stdout)
#define pb			push_back

template <class _T> _T MAX(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T MIN(_T a, _T b){ return a < b ? a : b; }
template <class _T> _T GCD(_T a, _T b){ return b ? gcd(b, a % b) : a; }
int sev=10000000;
int ans[70];
int ans1[70];
int v[70];

int main(void){
	int tt,test;
	int E,R,N,i,t,j,gain,r,mymax;
	scanf("%d",&test);
	for(tt=1;tt<=test;tt++)	{
	scanf("%d %d %d",&E,&R,&N);
	for(i=1;i<=N;i++) scanf("%d",&v[i]);
	for(i=0;i<=E;i++) ans[i]=0;
	gain=0;
	for(i=1;i<=N;i++)	{
		mymax=0;
		for(r=0;r<=E;r++)	{
			mymax=0;
			for(t=0;t<=E;t++)	{
			if(t>=r)
			mymax=MAX(mymax,ans[t]+((t-r)*v[i]));
			}
			ans1[r]=mymax;	
		}
		for(t=0;t<=E;t++) ans[t+R]=ans1[t];
		//printf("Level %d: ans[%d]=%d\n",i,t+R,ans1[t]);

	}
	mymax=0;
	for(i=0;i<=E;i++)	{
	mymax=MAX(mymax,ans[i]);
}
	printf("Case #%d: %d\n",tt,mymax);

}
	return 0;
}
