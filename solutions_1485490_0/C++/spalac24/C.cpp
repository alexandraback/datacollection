using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

unsigned long long n,m;
unsigned long long arrn [105][2];
unsigned long long arrm[105][2];

unsigned long long fun (int starttoy, int startbox) {
	//cout<<"fun "<<starttoy<<" "<<arrn[starttoy][0]<<" "<<startbox<<" "<<arrm[startbox][1]<<endl;
	if (starttoy == n || startbox == m) return 0;
	unsigned long long ret = 0;
	if (arrn[starttoy][0] == 0) return fun (starttoy+1,startbox);
	if (arrm[startbox][0] == 0) return fun (starttoy,startbox+1);
	if (arrn[starttoy][1] == arrm[startbox][1]){
		unsigned long long _min = min(arrn[starttoy][0],arrm[startbox][0]);
		arrn[starttoy][0] -= _min;
		arrm[startbox][0] -= _min;
		ret = fun(starttoy,startbox)+_min;
		arrn[starttoy][0] += _min;
		arrm[startbox][0] += _min;
		return ret;
	}
	ret = max(ret,fun(starttoy,startbox+1));
	ret = max(ret,fun(starttoy+1,startbox));
	
	return ret;		
}

int main(){
	
	int t;
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cout<<"Case #"<<cas<<": ";
		cin>>n>>m;
		for (int i = 0; i < n; ++i) {
			cin>>arrn[i][0]>>arrn[i][1];	
		}
		for (int i = 0; i < m; ++i) {
			cin>>arrm[i][0]>>arrm[i][1];	
		}
		/*for (int i = 0; i < n; ++i) cout<<arrn[i][0]<<" ";
		cout<<endl<<endl;*/
		cout<<fun(0,0)<<endl;
		//for (int i = 0; i < n; ++i) cout<<arrn[i][0]<<" ";	cout<<endl<<endl;
	
	}
return 0;
}
