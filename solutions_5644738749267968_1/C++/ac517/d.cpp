#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <queue>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)  for(int i = (a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define S           size()
#define PB          push_back
#define ALL(a)      a.begin(),a.end()
#define MP          make_pair
#define V           vector
#define VI          V < int > 
#define VVI         V < VI >
#define VVVI		V < VVI >
#define VL			V < long long > 
#define VVL			V < VL >
#define VD          V < double >
#define VVD			V < VD >
#define VD          V < double >
#define VS			V < string >


void rot(VD& v)
{
	reverse(v.begin(),v.end()-1);
	reverse(ALL(v));
}

int nextHi(VD& v, double f)
{
	auto it = lower_bound(ALL(v),f);
	return it-v.begin();
}

void print1d(VD& v)
{
	REP(i,v.S)
	{
		cout << setprecision(3) << fixed;
		cout <<  v[i] << " ";
	}
	cout << endl;
}

bool isDom(VD& n, VD& k)
{
	REP(i,n.S)
	{
		if(k[i]>n[i]) return false;
	}
	return true;
}

string check(VD n, VD k)
{
	sort(ALL(n));
	sort(ALL(k));
	int ns=0,ks=0;
	
	int i=0,j=0;
	while(i<n.S && j<k.S)
	{
		while(j<k.S && n[i]>k[j])
		{
			++j;
		}
		if(j<k.S) {++i; ++j;}
	}
	ns = n.S-i;
	ks = k.S-ns;
	
	//get ken to throw away his hi blocks until naomi dominates him block for block
	while(k.S>0)
	{
		if(isDom(n,k)) break;
		n.erase(n.begin(),n.begin()+1);
		k.erase(k.end()-1,k.end());
	}
	
	stringstream ss;
	ss << n.S << " " << ns << endl;
	return ss.str();

}

int main(int argc, char** argv)
{
	int n;
	++argv;
	ifstream in(*argv);
	
	in >> n;
	VS res;
	
	int k;
	
	REP(i,n)
	{
		VD N,K;
		in >> k;
		REP(j,k)
		{
			double block;
			in >> block;
		//	cout << block << endl;
			N.PB(block);
		}
		REP(j,k)
		{
			double block;
			in >> block;
		//	cout << block << endl;
			K.PB(block);
		}
		res.PB(check(N,K));
	}
				
	
	stringstream ss;
	REP(i,res.S)
	{
		ss << "Case #" << i+1 << ": " << res[i];
	}
	
	cout << ss.str();




}


