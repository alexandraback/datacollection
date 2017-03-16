//Template

// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vs;
typedef pair< int ,int > pii;
typedef vector <ll> vll;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

ll a[20],a2[20];
int cnt[10];
int main() {
	int r,n,m,k;
	scanf("%d%d",&r,&r);
	scanf("%d%d%d",&n,&m,&k);
	printf("Case #1:\n");
	while(r--) {
		rep(i,k) scanf("%lld",&a[i]),a2[i]=a[i];
		rep(i,9) cnt[i] = 0;
		for(int i=m; i>=2; i--) {
			rep(j,k) {
				int lo = 0;
				while(a[j]%i==0) { a[j]/=i; lo++; }
				cnt[i] = max(lo,cnt[i]);
			}
		}
		cnt[0] = cnt[1] = 0;
		int cc = 0,flag=0;
		rep(i,m+1) cc += cnt[i];
		// printf("%d \n",cc);
		//4->2 +1
		//6->2,3 +1
		//8->2 +2
		//8->4 +1
		while(n-cc>0 && cnt[8]) {
			cnt[8]--;
			cnt[4]++; cnt[4]++;
			cc++;
		}
		while(n-cc>0 && cnt[6]) {
			cnt[6]--;
			cnt[2]++; cnt[3]++;
			cc++;
		}
		while(n-cc>0 && cnt[4]) {
			cnt[4]--;
			cnt[2]++; cnt[2]++;
			cc++;
		}
		// printf("%d \n",cc);
		if(n-cc==0) {
			// int sf = 1;
			// rep(i,k) {
				// for(int j=m+1; j>=2; j--) {
					// rep(kk,cnt[j]) if(a2[i]%j==0) a2[i]/=j;
				// }
				// if(a2[i]>1) sf=0;
				// printf("%lld ",a2[i]);
			// }
			// if(sf==0) printf("REPORT\n");
			for(int i=m+1; i>=2; i--) {
				while(cnt[i]>0) { printf("%d",i); cnt[i]--; }
			}
		}
		else {
			rep(i,n) printf("%d",2);
		}
		printf("\n");
	}
	return 0;
}