#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long uint64;



uint64 gcd(uint64 a, uint64 b) 
{
	uint64 r;
	while (b != 0 )
	{
		r =a%b;
		a = b;
		b = r;
	}
	return a;
}

int get_gen(uint64 a, uint64 b) 
{
	uint64 r=a;
	int n=0;
	while(r>b)
	{
		r/=2;
		++n;
	}
	return n;
}

bool isExp(uint64 a) 
{
	uint64 r1=a,r2=0,r3=0;
	while(r1>1)
	{
		r2=r1/2;
		r3=r1-r2*2;
		if(r3!=0)return false;
		r1=r2;
	}
	return true;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
	int i,j;
    int t2;
    cin >> t2;

	uint64 P,Q;
	uint64 factor;

    for (int t1 = 1; t1 <= t2; ++t1) {
		cout<<"Case #"<<t1<<": ";
		cin >> P;
		cin.ignore(1);
		cin >> Q;
		factor=gcd(Q,P);
		P=(uint64)(P/factor);
		Q=(uint64)(Q/factor);
		if(isExp(Q))
			cout << get_gen(Q,P);
		else 
			cout << "impossible";
		cout<<"\n";
    }
    
    return 0;
}
