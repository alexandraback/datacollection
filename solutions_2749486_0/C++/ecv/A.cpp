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
typedef long long int Int;

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
char buf[1000002];
const int LIM = 2001, CEN= 1000;
int cnt[LIM][LIM];
char dir[LIM][LIM];
ii prv[LIM][LIM];
int main(int argc, char *argv[]){
	bool out = true;
	#ifndef ONLINE_JUDGE
		freopen("A.txt","r",stdin);
		if( out){
			freopen("Out.txt","w",stdout);
		}
	#endif
	int nt;
	scanf( "%d ", &nt);
	for(int numt = 1; numt <= nt; ++numt){
		memset(cnt,-1,sizeof(cnt));cnt[CEN][CEN] = 0;
		int x,y;
		scanf("%d %d ", &x, &y);
		ii dst = ii(y+CEN,x+CEN);
		queue<ii> Q; Q.push(ii(CEN,CEN));
		string res;
		while(!Q.empty()){
			ii pos = Q.front(); Q.pop();
			if( pos == dst ){
				while( cnt[pos.first][pos.second] != 0 ){
					res = string(1,dir[pos.first][pos.second])+res;
					pos = prv[pos.first][pos.second];
				}
				break;
			}
			int J = cnt[pos.first][pos.second]+1;
			if( pos.first + J < LIM && cnt[pos.first+J][pos.second] == -1){
				cnt[pos.first+J][pos.second] = J;
				Q.push(ii(pos.first+J,pos.second));
				cnt[pos.first+J][pos.second] = J;
				dir[pos.first+J][pos.second] = 'N';
				prv[pos.first+J][pos.second] = pos;
			}
			if( pos.first - J >= 0  && cnt[pos.first-J][pos.second] == -1){
				Q.push(ii(pos.first-J,pos.second));
				cnt[pos.first-J][pos.second] = J;
				dir[pos.first-J][pos.second] = 'S';
				prv[pos.first-J][pos.second] = pos;
			}
			if( pos.second - J >= 0  && cnt[pos.first][pos.second-J] == -1){
				Q.push(ii(pos.first,pos.second-J));
				cnt[pos.first][pos.second-J] = J;
				dir[pos.first][pos.second-J] = 'W';
				prv[pos.first][pos.second-J] = pos;
			}
			if( pos.second + J < LIM  && cnt[pos.first][pos.second+J] == -1){
				Q.push(ii(pos.first,pos.second+J));
				cnt[pos.first][pos.second+J] = J;
				dir[pos.first][pos.second+J] = 'E';
				prv[pos.first][pos.second+J] = pos;
			}
		}
		printf( "Case #%d: ", numt);
		printf( "%s\n", res.c_str());
		fflush(stdout);
	}
	return 0;
}
