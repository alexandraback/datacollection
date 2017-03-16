#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define FORR(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FORE(i,n) for(int i=0;i<=(int)(n);++i)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int> ipair;
typedef long long int64;
#define MF(X,val) memset(X,val,sizeof(X))
const double eps=1.0e-6;


//const int MAX_N=1000001;
const int MAX_N=1001;

double A[MAX_N];
double B[MAX_N];

int dWarScore(int n){
	int m=0;
	int pos=0;
	FOR(i,n){
		if(A[i]>B[pos]){
			m++;
			pos++;
		}
	}
	return m;
}

int warScore(int n){
	int m=0;
	int pos=0;
	FOR(i,n){
		if(B[i]>A[pos]){
			m++;
			pos++;
		}
	}
	return n-m;
}

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TC;
	cin>>TC;
	int n;
	REP(tc,1,TC+1){
		cin>>n;
		FOR(i,n)cin>>A[i];
		FOR(i,n)cin>>B[i];
		int y,z;
		sort(A,A+n);
		sort(B,B+n);
		y=dWarScore(n);
		z=warScore(n);
		printf("Case #%d: %d %d\n",tc,y,z);
	}
	return 0;
}