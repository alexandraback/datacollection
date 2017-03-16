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

int in[122];
int main() {
	int ans = 122;
	int a,n,t,cur;
	scanf("%d",&t);
	rep(test,t) {
		ans = 122;
		printf("Case #%d: ",test+1);
		scanf("%d%d",&a,&n);
		rep(i,n) scanf("%d",&in[i]);
		sort(in,in+n);
		int i=0;
		while(i<n && in[i]<a) {
			a += in[i];
			i++;
		}
		
		if(i==n) { printf("0\n"); continue; }
		
		cur = 0;
		while(i<n) {
			//take i and see
			ans = min(ans, cur+n-i);
			if(a==1) break;
			while(in[i]>=a) {
				cur++;
				a += (a-1);
			}
			while(i<n && in[i]<a) {
				a += in[i];
				i++;
			}
			ans = min(ans, cur+n-i);
		}
		printf("%d\n",ans);
	}
	return 0;
}