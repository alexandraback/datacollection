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
#include<queue>
#include<string>
#include<map>
using namespace std;

//debuggery
#define NDEBUG
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
typedef mint ans_t; //answer type

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
int N;
struct tribe{
	int d,n,w,e,s,dd,dp,ds;
};
struct dates{
bool operator()(tribe a, tribe b){
	return a.d < b.d;
}};
priority_queue<tribe,vector<tribe>,dates> q;
map<int, int> wall;

void read(istream& in){
	//! read input vars here !//
	cin>>N;
	while(q.size())
		q.pop();
	
	for(int i=0;i<N;i++){
		int d,n,w,e,s,dd,dp,ds;
		cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
		q.push({d,n,w,e,s,dd,dp,ds});
	}
	//! clear dyars if necessary here !//
	wall.clear();
}


ans_t solve(){
	ans_t rv = 0;
	
	while(!q.empty()){
		map<int, int>twall;
		
		queue<tribe> t;
		t.push(q.top());
		q.pop();
		while(!q.empty() && t.back().d == q.top().d){
			t.push(q.top());
			q.pop();
		}
		
		bool success = false;
		while(!t.empty()){
			tribe temp = t.front();
			t.pop();
			
			//what if two tribes attack at the same time?
			
			for(int i=temp.w;i<=temp.e;i++){
				if(wall[i]<temp.s)
					success = true;
				
				twall[i] = max(wall[i],temp.s);
			}
			
			//advance
			temp.n--;
			temp.d+=temp.dd;
			temp.w+=temp.dp;
			temp.e+=temp.dp;
			temp.s= max(temp.s+temp.ds,0);
			if(temp.n>0)
				q.push(temp);
		}
		if(success)
			rv++;
		for(auto pp:twall){
			if(pp.second){
				wall[pp.first] = max(wall[pp.first],pp.second);
			}
		}
	}
	
	return rv;
}

//precomputation and such
void init(){
	//! if there is a sample input, set it here !//
	input = "";
	//! if there is precomputation, do it here !//
	
}

