#pragma warning(disable : 4996)
#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
typedef std::vector<string> vs;
typedef std::vector<double> vd;

#define sz(a) int(a.size())
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i,a) for(int i = 0; i < sz(a); ++i)

inline bool isdig(int a){return unsigned(a-'0') < 10;}
template<class T> static inline T getnum(){
   unsigned i; T j;
   do i = getchar(); while(!isdig(i));
   j = i-'0';  i=getchar() ;
   while(isdig(i)){ j = (j<<1)+(j<<3)+(i-'0'); i = getchar(); }
   return j;
}

int N, T;

char orig[] = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char dst[] = "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

char buf[10000000];
int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("d:/home/code/GCJ/Aa.txt","r",stdin);
		if( out){
			freopen("d:/home/code/GCJ/Out.txt","w",stdout);
		}
	#endif
	char conv[256]; memset(conv,0,sizeof(conv));
	char inv[256]; memset(inv,0,sizeof(conv));
	for(int i = 0; orig[i] != 0; ++i){
		conv[orig[i]] = dst[i];
		inv[dst[i]] = orig[i];
	}
	conv['z'] = 'q';
	inv['q'] = 'z';
	int k = 0;
	for(int j = 'a'; j <= 'z'; ++j){
		if( conv[j] == 0 )
			k ++;
	}
	for(int j = 'a'; j <= 'z'; ++j){
		if( inv[j] == 0 )
			k ++;
	}
	int nt = getnum<int>();
	for(int j = 1; j <= nt; ++j){
		gets(buf);
		for(int i = 0; buf[i] != 0; ++i){
			buf[i] = conv[buf[i]];
		}
		printf( "Case #%d: ", j);
		printf("%s\n", buf);
		fflush(stdout);
	}
	return 0;
}
