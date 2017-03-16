#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <sstream>

#define F(i,n) for(int i=0, n_=(n); i<n_; i++)
#define FS(i,s,n) for(int i=(s), n_=(n); i<n_; i++)
#define FR(i,n) for(int i=(n)-1; i>=0; i--)

#define AA first
#define BB second
#define XX first.first
#define YY first.secomd
#define ZZ second

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VF;
typedef pair<int, int> PRI;
typedef pair<PRI, int> TRI;

template<typename T> inline void updatemin(T &a, T b) { if(a>b) a=b; }
template<typename T> inline void updatemax(T &a, T b) { if(a<b) a=b; }
template<typename T> inline T gcd(T a, T b) { 
	T d; 
	while(b!=0) d=a, a=b, b=d%b; 
	return a;
}

int pow10[8] = {1,10,100,1000,10000,100000,1000000,10000000};

short ndigits(int a){
	if(a>=pow10[4])
		if(a>=pow10[5])
			if(a>=pow10[6]) return 7;
			else return 6;
		else return 5;
	else
		if(a>=pow10[2])
			if(a>=pow10[3]) return 4;
			else return 3;
		else 
			if(a>=pow10[1]) return 2;
			
	return 1;
}

int cycle(int a, short m, short n=-1){
	if(n==-1) n = ndigits(a);
	int last_digit = a%pow10[m];
	a/=pow10[m];
	a += last_digit*pow10[n-m];
	return a;
}

bool check_cycle(int a, short c, short n = -1){
	if(n==-1) n = ndigits(a);
	if(n%2) return false;

	int b = a % pow10[c];
	a/=pow10[c];
	while(a>0) if(a%pow10[c] != b) return false; else a/=pow10[c];
	return true;
}

int main(){
	int T, A, B;
	cin>>T;
	F(test,T){
		cin>>A>>B;
		short n = ndigits(A);
		int count = 0;
		FS(x,A,B+1){
			int nn = n;
			if(check_cycle(x,2,n)) nn = 2;
			else if(check_cycle(x,3,n)) nn = 3;
			FS(j,1,nn){
				int y = cycle(x,j,n);
				if(y>x && y<=B) {
					//cout<<x<<"\t"<<y<<endl;
					count++;
				}
			}
		}
		
		cout<<"Case #"<<test+1<<": "<<count<<endl;
	}
}