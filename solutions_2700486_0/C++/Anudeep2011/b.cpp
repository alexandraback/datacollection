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

map < pii, double > M[21];

void prep() {
	int n;
	//1
	M[1][ mp(0,0) ] = 1;
	//2
	M[2][ mp(0,0) ] = 1;
	M[2][ mp(-2,0) ] = M[2][ mp(2,0) ] = double(1)/2;
	//3
	M[3][ mp(0,0) ] = 1;
	M[3][ mp(-2,0) ] = M[3][ mp(2,0) ] = double(3)/4;
	M[3][ mp(-1,1) ] = M[3][ mp(1,1) ] = double(1)/4;
	//4
	M[4][ mp(0,0) ] = M[4][ mp(-2,0) ] = M[4][ mp(2,0) ] = 1;
	M[4][ mp(-1,1) ] = M[4][ mp(1,1) ] = double(1)/2;
	//5
	n=5;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = 1;
	//6
	n=6;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	//7
	n=7;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = double(1)/2;
	//8
	n=8;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = double(3)/4;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = double(1)/4;
	n=9;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = double(7)/8;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = double(4)/8;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = double(1)/8;
	n=10;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = double(15)/16;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = double(11)/16;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = double(5)/16;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = double(1)/16;
	n=11;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = double(7)/8;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = double(4)/8;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = double(1)/8;
	n=12;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = double(3)/4;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = double(1)/4;
	n=13;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = double(1)/2;
	n=14;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	n=15;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	M[n][ mp(0,4) ] = 1;
	n=16;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	M[n][ mp(0,4) ] = 1;
	M[n][ mp(-6,0) ] = M[n][ mp(6,0) ] = double(1)/2;
	n=17;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	M[n][ mp(0,4) ] = 1;
	M[n][ mp(-6,0) ] = M[n][ mp(6,0) ] = double(3)/4;
	M[n][ mp(-5,1) ] = M[n][ mp(5,1) ] = double(1)/4;
	n=18;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	M[n][ mp(0,4) ] = 1;
	M[n][ mp(-6,0) ] = M[n][ mp(6,0) ] = double(7)/8;
	M[n][ mp(-5,1) ] = M[n][ mp(5,1) ] = double(4)/8;
	M[n][ mp(-4,2) ] = M[n][ mp(4,2) ] = double(1)/8;
	n=19;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	M[n][ mp(0,4) ] = 1;
	M[n][ mp(-6,0) ] = M[n][ mp(6,0) ] = double(15)/16;
	M[n][ mp(-5,1) ] = M[n][ mp(5,1) ] = double(11)/16;
	M[n][ mp(-4,2) ] = M[n][ mp(4,2) ] = double(5)/16;
	M[n][ mp(-3,3) ] = M[n][ mp(3,3) ] = double(1)/16;
	n=20;
	M[n][ mp(0,0) ] = M[n][ mp(-2,0) ] = M[n][ mp(2,0) ] = 1;
	M[n][ mp(-1,1) ] = M[n][ mp(1,1) ] = M[n][ mp(0,2) ] = 1;
	M[n][ mp(4,0) ] = M[n][ mp(-4,0) ] = 1;
	M[n][ mp(3,1) ] = M[n][ mp(-3,1) ] = 1;
	M[n][ mp(-2,2) ] = M[n][ mp(2,2) ] = 1;
	M[n][ mp(-1,3) ] = M[n][ mp(1,3) ] = 1;
	M[n][ mp(0,4) ] = 1;
	M[n][ mp(-6,0) ] = M[n][ mp(6,0) ] = double(31)/32;
	M[n][ mp(-5,1) ] = M[n][ mp(5,1) ] = double(26)/32;
	M[n][ mp(-4,2) ] = M[n][ mp(4,2) ] = double(16)/32;
	M[n][ mp(-3,3) ] = M[n][ mp(3,3) ] = double(6)/32;
	M[n][ mp(-2,4) ] = M[n][ mp(2,4) ] = double(1)/32;
	
}
	
int main() {
	int n,x,y;
	int t;
	prep();
	scanf("%d",&t);
	rep(test,t) {
		scanf("%d%d%d",&n,&x,&y);
		printf("Case #%d: %.8lf\n",test+1,M[n][ mp(x,y) ]);
	}
	return 0;
}