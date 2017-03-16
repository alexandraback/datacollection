//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE
LL a,b,k;
int i,j;
int t;
int cs;
LL dp[50][8];
LL hitung(LL i, LL typ) {
	//processing a-th bit
	LL pa, pb, pk;
	pa = a & ((1LL << (i+1))-1);
	pb = b & ((1LL << (i+1))-1);
	pk = k & ((1LL << (i+1))-1);
	if (i==-1)
		return 1;
	LL &ret = dp[i][typ];
	if (ret>=0)
		return ret;
	ret = 0;
		LL aone, azero, bone, bzero;
		aone = 0;
		azero = 0;
		bone = 0;
		bzero = 0;
		if ((typ & 1) == 0) {
			if ((1LL << i) <= pa) {
				//can set to one
				aone = pa - (1LL << i) + 1;
				azero = (1LL << i);
			}
			else {
				aone = 0;
				azero = pa + 1;
			}
		}
		else {
			aone = (1LL << i);
			azero = (1LL << i);
		}
		if ((typ & 2) == 0) {
			if ((1LL << i) <= pb) {
				bone = pb - (1LL << i) + 1;
				bzero = (1LL << i);
			}
			else {
				bone = 0;
				bzero = pb + 1;
			}
		}
		else {
			bone = (1LL << i);
			bzero = (1LL << i);
		}
	if ((1LL << i) <= pk) {
		ret += aone * bzero;
		ret += azero * bone;
		ret += bzero * azero;
		//set both to 1 if possible
		if (aone > 0 && bone > 0)
			ret += hitung(i-1, typ);
	}
	else {
		//set a one b zero, follows
		if (aone > 0)
		{
			if (bzero == (1LL << i)) {
				ret += hitung(i-1, typ | 2);
			}
			else
				ret += hitung(i-1, typ);
		}
		//set b one a zero, follows
		if (bone > 0) {
			if (azero == (1LL << i)) 
				ret += hitung(i-1, typ | 1);
			else
				ret += hitung(i-1, typ);
		}
		//set both to be zero
		LL newtyp = typ;
		if (azero == (1LL << i))
			newtyp = newtyp | 1;
		if (bzero == (1LL << i))
			newtyp = newtyp | 2;
		ret += hitung(i-1, newtyp);
	}
	return ret;
}
int main()
{
	scanf("%d",&t);
	while (t--) {
		printf("Case #%d: ",++cs);
		scanf("%lld %lld %lld",&a,&b,&k);
		--a;--b;--k;
		memset(dp,-1,sizeof(dp));
		LL res = 0;
		printf("%lld\n",hitung(40,0));
			
	}
}
