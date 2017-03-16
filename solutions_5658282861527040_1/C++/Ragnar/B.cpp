#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


struct Param{
	long A;
	long B;
	long K;
	int d;

	Param(long nA,long nB,long nK,long nd): d(nd) {
		long long dd = 1LL<<(nd);
		A=max(nA,nB);
		B=min(nA,nB);
		K=nK;

		if(A>dd)
			A=dd+1;
		if(B>dd)
			B=dd+1;
		if(K>dd)
			K=dd+1;
	}

	inline bool operator<(const Param& r) const{
		if(A<r.A)
			return true;
		if(A>r.A)
			return false;
		if(B<r.B)
			return true;
		if(B>r.B)
			return false;
		if(K<r.K)
			return true;
		if(K>r.K)
			return false;
		if(d<r.d)
			return true;
		if(d>r.d)
			return false;
		return false;
	}
};

class Solver{
public:
	long long A,B,K;


	ifstream &in;
	int N;
	static map<Param, long long> cache;

	Solver(ifstream &input):in(input){
		in>>A>>B>>K;
	}

	Solver(ifstream &input,bool b):in(input){
	}

	long long f(Param p){
		if(cache.find(p)!=cache.end())
			return cache[p];
		if(p.d==0)
			return 1;
		long long dd = 1LL<<(p.d-1);
		long long r=0;
		if(p.K>dd && p.A>dd && p.B>dd)
			r+=f(Param(p.A-dd,p.B-dd,p.K-dd,p.d-1));
		if(p.A>dd)
			r+=f(Param(p.A-dd,p.B,p.K,p.d-1));
		if(p.B>dd)
			r+=f(Param(p.A,p.B-dd,p.K,p.d-1));
		r+=f(Param(p.A,p.B,p.K,p.d-1));

		cache.insert(make_pair(p,r));
		return r;
	}

	long long solve(){
		long long a=A;
		int c=1;
		while(a>>=1 > 0)
			++c;
		int d=c;
		a=B;
		c=1;
		while(a>>=1 > 0)
			++c;
		d=max(d,c);
		a=K;
		c=1;
		while(a>>=1 > 0)
			++c;
		d=max(d,c);

		return f(Param(A,B,K,d));
	}

	void print(){

		for( A=0;A<10;++A){
			for( B=0;B<10;++B){
				for( K=0;K<10;++K){
					cout<<solve();
					cout<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n\n";
		}


	}
};

map<Param, long long> Solver::cache = map<Param, long long>();

int main(){
	ifstream in;
	ofstream out;
	string fileName = "B-large";
	in.open(fileName+".in");
	out.open(fileName+".out");

	int T;
	in>>T;
	for(int i=1;i<=T;++i){
		cout<< "Case #"<<i<<": ";
		Solver solver(in);
		long long result=solver.solve();
		cout<<result<<"\n";
		out << "Case #"<<i<<": "<<result<<"\n";
	}
	Solver s(in,false);

	return 0;
}

