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

string getInverse(string str)
{
	const char* number=str.c_str();
	int i = str.size();
	stringstream stm;
	while(i>0){
		stm << number[--i];
	}
	return stm.str();
}
inline bool isParindome(ull num)
{
	stringstream stm;
	stm <<num;
	string normal,inverse;
	normal = stm.str();
	inverse= getInverse(normal);
	if(normal==inverse) return true;
	return false;
}
inline void alg(){
	ull A,B;
	cin >>A;
	cin >>B;
	ull floorSqrtA	=sqrt(double(A));
	ull ceilSqrtB	=ceil(sqrt(double(B)));
	int count=0;
	for(ull i=floorSqrtA;i<=ceilSqrtB;++i){
		if(isParindome(i)==false)continue;
		ull i2=i*i;
		if(isParindome(i2)==false)continue;
		if(A<=i2 && i2<=B){
			++count;
		}
	}
	cout << count;

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
