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
#include <cstdio>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int main(){
	ifstream be("B-small-attempt2.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int x,y; be>>x>>y;
		
		stringstream ss;
		FOR(i,abs(x)){
			if(x>0)
				ss<<"WE";
			else
				ss<<"EW";
		}
		FOR(i,abs(y)){
			if(y>0)
				ss<<"SN";
			else
				ss<<"NS";
		}
		string r=ss.str();

		ki<<"Case #"<<tt+1<<": "<<r<<endl;
	}
	

	ki.close();
	return 0;
}