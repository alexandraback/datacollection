#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int main(){
	ifstream be("B-large.in");
	ofstream ki("ki.txt");

	int T; be>>T;
	FOR(tt,T){
		
		int n,s,p; be>>n>>s>>p;
		int norm=p+2*max(p-1,0), surp=p+2*max(p-2,0);
		int cn=0, cs=0;
		FOR(i,n){
			int x; be>>x;
			if(x>=norm)
				cn++;
			if(x>=surp)
				cs++;
		}
		int os=cs-cn;
		int kix=cn+min(os,s);
		
		ki<<"Case #"<<tt+1<<": "<<kix<<endl;
	}

	return 0;
}