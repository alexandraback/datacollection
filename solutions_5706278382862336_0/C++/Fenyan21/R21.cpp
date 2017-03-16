#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <utility>
#include <sstream>
using namespace std;


// a <= b
long long lcm(long long a, long long b){
	if( a == 0 )
		return b;
	else
		return lcm(b%a,a);
}



// p < q
int solve(long long p, long long q){
	long long d = lcm(p,q);
	p = p / d;
	q = q / d;
	long long ck = q;
	while( (ck%2) == 0 ){
		ck = ck/2;
	}
	if( ck !=1 )
		return 0;

	int ret = 1;
	while( p*2 < q){
		ret++;
		p*=2;
	}
	return ret;



}

int main(){
	ifstream is("f1.in");
//	std::istream& is = std::cin;
	ofstream os("answer.txt");
	
	int cnum;
	is >> cnum;
	for( int cc = 1; cc <=cnum; cc++){
		long long p;
		long long q;
		string str;
		is>>str;
		int pos = str.find_first_of('/');
		string cnum = str.substr(0,pos);
		stringstream ss;
		ss << cnum;
		ss >> p;
		cnum = str.substr(pos+1);
		ss.clear();

		ss << cnum;
		ss >> q;

		int ans = solve(p,q);
		if( ans == 0 )
			os<<"Case #"<<cc<<": impossible"<<endl;
		else
			os<<"Case #"<<cc<<": "<<ans<<endl;
	}


	is.close();
	os.close();
}
