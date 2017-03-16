// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
// }}}

int N,M;
int a[110][110];
int row[110],col[110];

bool suspect(){
	REP(b,M){
//		dump(b);
		//col b is max
		REP(i,N){
			row[i]=a[i][b];
		}
		REP(j,M)col[j]=INF;
		bool valid=true;
		for(int i=0;valid and i<N;i++){
			for(int j=0;valid and j<M;j++){
				if(row[i]<a[i][j]){
					valid=false;
				}else if(row[i]==a[i][j]){

				}else{
					if(col[j]==INF)col[j]=a[i][j];
					else{
						if(min(row[i],col[j])!=a[i][j])valid=false;
					}
				}
			}
		}
		if(valid){
			REP(i,N)REP(j,M){
				if(min(row[i],col[j])!=a[i][j])valid=false;
			}
		}
		if(valid)return true;
	}
	REP(b,N){
		//row b is max
		REP(j,M){
			col[j]=a[b][j];
		}
		REP(i,N)row[i]=INF;
		bool valid=true;
		for(int j=0;valid and j<M;j++){
			for(int i=0;valid and i<N;i++){
				if(col[j]<a[i][j]){
					valid=false;
				}else if(col[j]==a[i][j]){

				}else{
					if(row[i]==INF)row[i]=a[i][j];
					else{
						if(min(row[i],col[j])!=a[i][j])valid=false;
					}
				}
			}
		}
		if(valid){
			REP(i,N)REP(j,M){
				if(min(row[i],col[j])!=a[i][j])valid=false;
			}
		}
		if(valid)return true;
	}
	return false;
}

bool beta_suspect(){
	const int B=(1<<(N+M));
	REP(b,B){
		REP(i,N)row[i]=(b&(1<<i))?1:2;
		REP(j,M)col[j]=(b&(1<<(j+N)))?1:2;
		bool valid=true;
		REP(i,N)REP(j,M){
			if(min(row[i],col[j])!=a[i][j])valid=false;
		}
		if(valid){
			REP(i,N)cerr<<row[i]<<" ";
			cerr<<endl;
			REP(j,M)cerr<<col[j]<<" ";
			cerr<<endl;
			return true;
		}
	}
	return false;
}

void main2(){
	cin>>N>>M;
	REP(i,N)REP(j,M)cin>>a[i][j];
	bool r=suspect();
	if(r)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
//	if(r!=beta_suspect())assert(false);
}

//{{{ main function
int main() {
	int T;scanf("%d", &T);
	REP(ct, T){
		printf("Case #%d: ",ct+1);
		main2();
	}
	return 0;
}
//}}}
