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


//a, e, i, o, and u to be vowels
int cons(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 0;
	else 
		return 1;
}


int main(){
	ifstream be("A-large.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		string s; be>>s;
		int l=SZ(s);
		int n; be>>n;
		
		int c=0;
		FOR(i,n)
			c+=cons(s[i]);
		int legut= c==n ? 0 : -1; //hol kezdodik a legutobbi n-hosszu cucc

		LL r=0;
		for(int i=n-1; i<l; i++){ //aktualis substring: i-n+1, i
			if(legut!=-1){
				r+=legut+1;
			}

			//c-t frissit:
			if(i<l-1){
				c-=cons(s[i-n+1]);
				c+=cons(s[i+1]);
				if(c==n)
					legut=i-n+1+1;
			}
		}

		ki<<"Case #"<<tt+1<<": "<<r<<endl;
	}
	

	ki.close();
	return 0;
}