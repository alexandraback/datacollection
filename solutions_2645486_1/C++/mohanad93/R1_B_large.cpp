#include <iterator>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
using namespace std;

#define SZ(v)                   (int)v.size()
#define FOR(i,a,b)				for(int i=(a);i<(b);++i)
#define rev(i,a,b)				for(int i=(b);i>=(a);--i)
#define sz(v)                   (int)v.size()
#define all(v)					v.begin(), v.end()
#define rall(v)					v.rbegin(), v.rend()
#define pb						push_back
#define mp						make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
const int OO = 1 << 28;

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
#define Nd 0
#define Ed 1
#define Sd 2
#define Wd 3

long long A[100000]; // the array of data
int n,E,R;
int m[100000][17]; // array[n][log(n , 2)]
void RMQIntialize_ONLOGN(){
        for(int i= 0 ; i< n ; i++)m[i][0] = i;
        for(int j = 1  ; (1<<j)<=n ; j++ )
                for(int i = 0 ; i+(1<<j)-1<n ; i++)
                        m[i][j] = A[m[i][j-1]] <= A[m[(1<<(j-1))+i][j-1]] ? m[i][j-1]: m[(1<<(j-1))+i][j-1];
}

int RMQQuery_O1(int  i , int j){
        int k = (int)(log(j-i+1) / log(2));
        int k_2 = (int)pow(2.0 , k);
        return A[m[i][k]]<=A[m[j-k_2+1][k]] ? m[i][k]: m[j-k_2+1][k];
}


int mnE[100000];

void conq(int st, int end){
	if(st >= end)
		return ;
	int mx = RMQQuery_O1(st,end);
	int cur = E-R;
	rev(i,st,mx-1){
		mnE[i] = max(mnE[i],cur);
		cur -= R;
	}
	conq(st,mx-1);
	conq(mx+1,end);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
		freopen("out.out", "wt", stdout);
#endif
	int cas;
	cin >> cas;
	FOR(cs,1,cas+1){
		cin >> E >> R >> n;
		FOR(i,0,n){
			cin >> A[i];
			A[i]*=-1;
		}
		RMQIntialize_ONLOGN();
		memset(mnE,0,sizeof  mnE);
		conq(0,n-1);
		ll res = 0;
		ll en = E;
		FOR(i,0,n){
			res += max((en-mnE[i]) * -1 * A[i],0LL);
			en = (en >= mnE[i])?mnE[i]:en;
			en += R;
		}
		cout << "Case #" << cs <<": " << res << "\n";

	}
	return 0;
}




