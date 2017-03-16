/*
	Author: Pankaj Jindal
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <math.h>
#include <cassert>
#include <string.h>

using namespace std;

#define DEBUG if(0)

//Numberic Functions
template<class T> inline T gcd(T a, T b){
	if(a<0)return gcd(-a,b); if(b<0)return gcd(a,-b); return (b==0)?a:gcd(b,a%b);
}
template<class T> inline T lcm(T a, T b){
	if(a<0)return lcm(-a,b); if(b<0)return lcm(a,-b); return a*(b/gcd(a,b));
}
template<class T> inline T euclide(T a, T b, T &x, T &y){
	if(a<0){T d=euclide(-a,b,x,y); x=-x; return d;}
	if(b<0){T d=euclide(a,-b,x,y); y=-y; return d;}
	if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}
}

template<class T> inline bool isPrimeNumber(T n){
	if(n<=1)return false;for(T i=2;i*i<=n;i++) if(n%i==0) return false;return true;
}
template<class T> inline T eularFunction(T n){
	vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;
}

//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for(int i = (int)(s); i < (int)(e); i++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define pb push_back
#define mp make_pair

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const double PT = acos(-1.0);
const double EPS = 1e-11;

#define MAXL 101

char ar[MAXL];

int main(){
	int i, j, k, t, T, cnt, n;
	long long ans;
	bool tr;

	scanf("%d", &T);
	REP(i, T){
		scanf("%s %d", &ar, &n);
		cnt = 0;
		ans = 0;
		//tr= false;
		k=-1;
		t = strlen(ar);

		REP(j, t){
			if(ar[j]=='a' or  ar[j]=='e' or ar[j]=='o' or ar[j]=='i' or ar[j]=='u'){//not a consonant
				//ans = ans+ans;
				ans = ans + MAX(0, k-n+1);
				cnt = 0;
			}
			else{
				cnt++;
				if(cnt>=n){
					ans = ans + j+1-n + 1;
					k = j+1;
				}
				else{
					ans = ans + MAX(0, k-n+1);
				}
			}
		}

		printf("Case #%d: %lld\n", i+1, ans);
	}
	return 0;
}
