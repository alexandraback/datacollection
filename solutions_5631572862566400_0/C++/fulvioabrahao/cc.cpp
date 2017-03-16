#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long long int ll;
typedef unsigned long long int  ull;

int n;
int v[1010];



int main(){

	int n,t, ca = 1;
	cin>>t;
	while(t--){
		printf("Case #%d: ",ca++);
		cin>>n;
		for(int i =  1;i<=n;i++)
			cin>>v[i];
		int ans= 0;
		vector<int> aux;
		for(int i = 1;i<=n;i++)
			aux.push_back(i);
		
		do{

			for(int i = 1;i<n;i++){
				bool ok = true;
				for(int j = 0;j<=i;j++){
					if(!(v[aux[j]] == (aux[(j-1+(i+1))%(i+1)]) || v[aux[j]] == (aux[(j+1+(i+1))%(i+1)])))
						ok = false;
				}
				if(ok){
					ans = max(ans,(i+1));
				}
			}

		}while(next_permutation(aux.begin(), aux.end()));
		cout<<ans<<endl;
	}
	

	return 0;
}
