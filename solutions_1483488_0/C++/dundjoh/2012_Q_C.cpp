#if 1
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>	
#include <list>
#include <queue>
#include <climits>
#include <hash_set>
#include <hash_map>
#include <array>
#include <ctime>
//#include "BinaryTree.h"
//#include "numrep.h"
using namespace std;

string	Directory = "C:\\";
string	files[]={	"-test.txt",			//0
					"-small-practice.in",	//1
					"-large-practice.in",	//2
					"-small.in",			//3
					"-large.in",			//4
					"-small-attempt",		//5
					"-large-attempt"		//6
					};
int		InputSelect		= 5;
string	ProblemLetter	= "C";	
bool	FileOutput		= 1;	//stdout is redirected into a file
bool	SeperateOutput	= 0;	//Produce a seperate output file for each input
string	Attemp			= "1";

#define fii(a) for( int i=0;i< ( a );i++)
#define fij(a) for( int j=0;j< ( a );j++)
#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )


typedef				__int64		int64;
typedef unsigned	__int64		uint64;
typedef unsigned	__int32		uint;

typedef list<int> li;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int64> vl;
typedef map<int,int> mii;
typedef mii::iterator miiit;
typedef multimap<int,int> mmii;
typedef mmii::iterator mmiiit;


//initianlization depending on the number of cases
void init(int T)
{
	 
}

const uint N=7;
typedef array<uint,N> at;

uint load(uint A,uint& p)
{
	uint r=0;
	p=0;
	while(A)
	{
		r|=(A%10)<<(p++*4);
		A/=10;
	}
	return r;
}

template<int p>
struct check{
	static void go(uint& i,uint& po){
		auto j= i&(15<<(p*4));
		if(j == 10<<(p*4)){
			i &= 0xFFFFFFFF - (15<<(p*4));
			i += 16<<(p*4);
			if(p>=po-1) po++;
		}
		check<p+1>::go(i,po);
	}
};

template<>
void check<N>::go(uint& i,uint& po){}

void main2()
{ 
	uint A,B;
	cin>>A>>B;

	uint count=0,a,b;
	uint p;
	
	b=load(B,p);
	a=load(A,p);

	cerr<<hex<<a<<" "<<p<<endl;
	cerr<<hex<<b<<endl;

	for(uint i=a;i<b;i++)
	{
		check<0>::go(i,p);
		uint j=i;
		while(1){
			j|= (j&15)<<(p*4);
			j>>=4;
			if(j==i) break;
			//cout<<hex<<i<<" "<<j<<" "<<p<<endl;
			if(i<j && j<=b) count++;
		}
	}
	
	cout<<count<<endl;	
}


int main()
{	
	if(InputSelect>=5)
		files[InputSelect]+=Attemp+".in";

	if(freopen( (Directory+ProblemLetter+files[InputSelect]).data(), "r", stdin )==NULL)
	{
		cout  << "FILE NOT FOUND"  << endl;
		cerr  << "FILE NOT FOUND"  << endl;
		cerr<<Directory+ProblemLetter+files[InputSelect]<<endl;
		exit(1);
	}

	if(FileOutput)
		if(SeperateOutput)
			freopen( (Directory+"Output-"+ProblemLetter+files[InputSelect]).data() ,"w",stdout);
		else
			freopen( (Directory+"Output.txt").data() ,"w",stdout);
			
	clock_t start = clock();

	int T,i;
	scanf_s("%d\n", &T) ;
	init(T);
	fo(i,1,T+1) {
		cerr << "Case #" << i <<endl;		
		cout << "Case #" << i << ": ";
		main2();
	}

	cerr<<"Elapsed:"<<(clock()-start)*1.0/CLOCKS_PER_SEC<<endl;
	
	return 0;
}

#endif