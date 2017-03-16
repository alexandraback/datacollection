#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>
#include <utility>    
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

int n, j;
vi ans;

void bt(int col, unsigned int chosen, int zero4, int one4, int two4, int three4, int odd, int even){
	if(ans.size() >= j) return;
	if(__builtin_popcount(chosen) == 12){
		if(zero4 == 2 && one4 == two4 && two4 == three4 && two4 == 3 && odd == even){
			ans.push_back(chosen);
		}
		return;
	}
	if(col == n-1) return;
	bt(col+1, chosen|(1<<col), zero4 + ((col%4) == 0), one4 + ((col%4) == 1), two4 + ((col%4) == 2), three4 + ((col%4) == 3), odd + (col%2), even + !(col%2));
	bt(col+1, chosen, zero4, one4, two4, three4, odd, even);
}

int main(){
	n = 32;
	j = 500;
	bt(1, 0x80000001, 0, 0, 0, 1, 1, 1); 
	cout << "Case #1:\n";
	REP(i, ans.size()){
		REPD(j, n){
			if(ans[i]&(1<<j)) cout << "1";
			else cout << "0";
		}
		REPP(j, 2, 10){
			if(j%2) cout << " 2";  
			else{
				if(j == 6) cout << " 7";
				else cout << " 5";
			}
		}
		cout << " 11\n";
	}
}
