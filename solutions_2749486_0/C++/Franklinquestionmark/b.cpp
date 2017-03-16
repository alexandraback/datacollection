#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<limits>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<array>
#include<string>
#include<map>
using namespace std;

//debuggery
// #define NDEBUG
#ifdef NDEBUG
	//These will turn off cerr statements
	//This is due to short-circuit evaluation:
	//http://en.wikipedia.org/wiki/Short-circuit_evaluation
	#define cerr false&&cerr
	#define fprintf false&&fprintf
#endif
typedef long long lint;
typedef unsigned long long ull;
typedef long long int mint; //my integer
typedef long double dbl; //my double
typedef string ans_t; //answer type

//integer arrays
typedef vector<mint> vi;
typedef vector<vi> vvi;
//double arrays
typedef vector<dbl> vd;
typedef vector<vd> vvd;
//dynamic array types
typedef map<mint,ans_t> da;
typedef map<mint,da> dda;
typedef map<mint,dda> ddda;

typedef istringstream iss;
typedef ostringstream oss;
typedef stringstream ss;

string input; //sample input
void init();
void read(istream& in);
ans_t solve();
template<class Int> Int gcd(Int a, Int b){ return a==0?b:gcd(b%a,a); }
template<class Int> Int combination(int n, int k){
//breaks at 68 choose 34.
	k = min(k,n-k);
	if( k <= 0 ) return k==0?1:0;
	static vector<vector<Int>> dyar;
	while(dyar.size() < n)
		dyar.push_back(vector<Int>((dyar.size()+1)/2));
	if(dyar.at(n-1).at(k-1) == 0)
		dyar[n-1][k-1] = combination<Int>(n-1,k) + combination<Int>(n-1,k-1);
	if(dyar[n-1][k-1] == 0)
		dyar[n-1][k-1] = combination<Int>(n-1,k) + combination<Int>(n-1,k-1);
	return dyar[n-1][k-1];
}
ull (*comb)(int, int) = combination<ull>;

//position of highest bit (counts 0 and 1 as 0)
template<class Int>int lg(Int n){
	int rv=0;
	while(n>>=1)
		rv++;
	return rv;
}


int main(int argc, char** argv){
	init();
	ifstream fin; ofstream fout; iss sin(input);
	if(argc>1)
		fin.open(argv[1]), fout.open(argv[1]);
	istream& in = argc>1? fin: input.empty()? cin: sin;
	ostream& out = argc>1? fout: cout;
	
	int t; in>>t;
	for(int i = 0; i<t; i++){
		read(in); //get input
		ans_t ans = solve(); //solve
		out<<"Case #"<<(i+1)<<": "<<ans<<endl; //output
		cerr<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
	return 0;
}

//// write input vars here ////
int x,y;

void read(istream& in){
	//! read input vars here !//
	in>>x>>y;
	//! clear dyars if necessary here !//
	// cout<<"test";
}

ans_t rv;
void move(char c, int i){
	rv+=c;
	switch(c){
	case 'E':x+=i;break;
	case 'W':x-=i;break;
	case 'N':y+=i;break;
	case 'S':y-=i;break;
	}
}

ans_t solve(){
	rv="";
	//reverse 
	x=-x;
	y=-y;
	
	int i=1;
	for(;x!=0;i++){
		if((x>0 && x-i>=0) ||x+i>0)
			move('W',i);
		else
			move('E',i);
	}
	for(;y!=0;i++){
		if((y>0 && y-i>=0) ||y+i>0)
			move('S',i);
		else
			move('N',i);
	}
	// if(x%2==0){
		// rv+='N';
		// y+=1;
	// }else{
		// rv+='E';
		// x+=1;
	// }
	
	
	// for(int i=2; x != 0 || y != 0 ;i++){
		// if(abs(x)>abs(y)){
			// if((x>0&&x<=i) || x>=-i){
				// rv+='W';
				// x-=i;
			// }else{
				// rv+='E';
				// x+=i;
			// }
		// }
		// else{
			// if((y>0&&y<=i) || y>=-i){
				// rv+='S';
				// y-=i;
			// }else{
				// rv+='N';
				// y+=i;
			// }
		// }
		// cerr<<rv<<endl;
	// }
	
	return rv;
}

//precomputation and such
void init(){
	//! if there is a sample input, set it here !//
	// input = "2 3 4 -3 4";
	//! if there is precomputation, do it here !//
	
}

