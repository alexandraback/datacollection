/*
 * ac.cpp
 *
 *  Created on: 2015-5-10
 *      Author: bjfudq
 */
#include <functional>
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")


#define MEM(a) (memset((a),0,sizeof(a)))
#define LEN(a) (int)strlen((a))
#define fr(a) for(int i=0;i<(a);i++)
#define sf(a) scanf("%d",&(a))
#define sf64(a) scanf("%I64d",&(a))
#define sff(a) scanf("%lf",&(a))
#define sfs(a) scanf("%s",(a))
#define sf2(a,b) scanf("%d%d",&(a),&(b))
#define sf3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define sf2s(a,b) scanf("%s%s",(a),(b))
#define sf2f(a,b) scanf("%lf%lf",&(a),&(b))
#define sf3f(a,b,c) scanf("%lf%lf%lf",&(a),&(b),&(c))
#define sf264(a,b) scanf("%I64d%I64d",&(a),&(b))
#define sf364(a,b,c) scanf("%I64d%I64d%I64d",&(a),&(b),&(c))
#define pf(a) printf("%d\n",(a))
#define pfc(a) printf("%c",(a))
#define pf64(a) printf("%I64d\n",(a))
#define pff(a) printf("%lf\n",(a))
#define pfs(a) printf("%s\n",(a))
#define pf2(a,b) printf("%d %d\n",(a),(b))
#define pf2s(a,b) printf("%s%s\n",(a),(b));
#define pf2f(a,b) printf("%lf %lf\n",(a),(b))
#define pf264(a,b) printf("%I64d %I64d\n",(a),(b))
#define pfn printf("\n")
#define pfk printf(" ")
#define LL long long

const int N=1010;
const int M=1000010;
const int MOD=1000000007;
const int INF=0x7fffffff;
const int dir4[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int dir8[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
const double eps=1e-8;
const double PI=acos(-1.0);

inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
/*************************/

char s1[110];
char s2[110];
int K,L,S;
int mx, tot, ans;
char ss[110];

void dfs(int pos)
{
	if(pos == S)
	{
		tot++;
		int b = 0;
		for(int t=0;t<=S-L;t++)
		{
			int i=0;
			for(;i<L;i++)
				if(s2[i] != ss[t+i])
					break;
			if(i == L)
				b++;
		}
		ans+=b;
		if(b > mx)
			mx = b;
		return ;
	}
	for(int i=0;i<K;i++)
	{
		ss[pos]=s1[i];
		dfs(pos+1);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T,cas=1;
    sf(T);
    while(T--)
    {
    	printf("Case #%d: ",cas++);
    	scanf("%d%d%d",&K,&L,&S);
    	scanf("%s%s",s1,s2);
		tot=0,ans=0,mx=0;
		dfs(0);
		printf("%.7f\n",mx-ans*1.0/tot);
    }
	return 0;
}
