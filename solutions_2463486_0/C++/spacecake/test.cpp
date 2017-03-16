#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std; 

typedef vector<int> VI; 
#define i64 long long 
#define pii pair<int,int>
#define mp make_pair
#define ALL(x) (x).begin(), (x).end() 
#define REP(i,n) for(int i = 0;i<(int)n;++i)
#define x first
#define y second

const i64 NMAX = (i64)1e14;
int T;
int A, B;
int N;
i64 values[64] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,
100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,
10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,
1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,
1234567654321,4000008000004,4004009004004};

void computeSquarePalindromes() {
	char val[32];
	for(int i = 1;1ll*i*i <= NMAX;i++) {
		sprintf(val,"%lld",1ll*i);
		int dim = strlen(val);
		bool ok = true;
		for(int j = 0;j + j < dim && ok;++j) {
			if(val[j] != val[dim - j - 1]) {
				ok = false;
			}
		}
		if(ok) {
			sprintf(val,"%lld",1ll*i*i);
			dim = strlen(val);
			for(int j = 0;j + j < dim && ok;++j) {
				if(val[j] != val[dim - j - 1]) {
					ok = false;
				}
			}
			if(ok) {
				values[N++] = 1LL*i*i;
			}
		}
	}

}

void readData() {
	cin>>A>>B;
}

void solve(int t) {
	int ret = 0;
	int posA = 0, posB = 0;
	for(int steps = 64;steps > 0;steps >>= 1 ){
		if(posA + steps < N && values[posA + steps] < A) {
			posA += steps;
		}
		if(posB + steps < N && values[posB + steps] <= B) {
			posB += steps;
		}
	}
	if(A == 1) {
		ret = posB + 1;
	} else {
		ret = posB - posA;
	}
	cout<<"Case #"<<t<<": "<<ret<<"\n";
}

int main()
{
	//freopen("test.in","r",stdin); freopen("test.out","w",stdout);cin.sync_with_stdio(false), cout.sync_with_stdio(false);
	computeSquarePalindromes();
	cin>>T;
	REP(t,T) {
		readData();
		solve(t + 1);
	}
	return 0;
}
