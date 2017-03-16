#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <cstring>

using namespace std;

#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)


typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;


typedef ull T;
#define LARGE1
#ifdef	LARGE1
const int		MAX_DIGITS=15;
#endif



const T targetList[]={
	1				 ,
	4				 ,
	9				 ,
	121				 ,
	484				 ,
	10201			 ,
	12321			 ,
	14641			 ,
	40804			 ,
	44944			 ,
	1002001			 ,
	1234321			 ,
	4008004			 ,
	100020001		 ,
	102030201		 ,
	104060401		 ,
	121242121		 ,
	123454321		 ,
	125686521		 ,
	400080004		 ,
	404090404		 ,
	10000200001		 ,
	10221412201		 ,
	12102420121		 ,
	12345654321		 ,
	40000800004		 ,
	1000002000001	 ,
	1002003002001	 ,
	1004006004001	 ,
	1020304030201	 ,
	1022325232201	 ,
	1024348434201	 ,
	1210024200121	 ,
	1212225222121	 ,
	1214428244121	 ,
	1232346432321	 ,
	1234567654321	 ,
	4000008000004	 ,
	4004009004004	 
};
const int targetNum=sizeof(targetList)/sizeof(T);

inline int getParindomeNum(ull num)
{
	if(num==0)return 0;
	rep(i,targetNum){
		if(targetList[i]>num) return i;
	}
	return targetNum;
}


inline void alg(){

	ull A,B;
	cin >>A;
	cin >>B;
	int sizeB=getParindomeNum(B);
	int sizeA=getParindomeNum(A-1);

	cout << sizeB-sizeA;

}

int main(int argc, char** argv)
{	
	if(argc<2)return 0;

	string in_file=argv[1];
	freopen(in_file.c_str(),"r",stdin);
	freopen((in_file.substr(0,in_file.find_last_of("."))+".out").c_str(),"w",stdout);

	int n_cases;
	cin >> n_cases;cin.ignore();
	rep(i,n_cases){
		cout << "Case #" << i+1 << ": ";
		alg();
		cout << endl;
	}
	return 0;
}
