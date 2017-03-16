#if 1
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>	
#include <list>
#include <queue>
#include <array>
#include <climits>
#include <hash_set>
#include <hash_map>
#include <limits>
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
int		InputSelect		= 4;
string	ProblemLetter	= "A";	
bool	FileOutput		= 1;	//stdout is redirected into a file
bool	SeperateOutput	= 0;	//Produce a seperate output file for each input
string	Attemp			= "2";

#define fii(a) for( int i=0;i< ( a );i++)
#define fij(a) for( int j=0;j< ( a );j++)
#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )


typedef				__int64		int64;
typedef unsigned	__int64		uint64;
typedef unsigned	__int32		uint;

typedef list<int> li;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<int64> vl;
typedef map<int,int> mii;
typedef mii::iterator miiit;
typedef multimap<int,int> mmii;
typedef mmii::iterator mmiiit;


//initialization depending on the number of cases
void init(int T)
{
	 
}


vector<int> a;
int N,s;


bool elim(double y,int i){
	double score=a[i]+s*y;
	double rest=1.0-y;
	for(int j=0;j<N;j++){
		if(i!=j){
			rest-=max(0.0,(score-a[j])/s);
			if(rest<0) return false;
		}
	}
	return true;
}

void main2()
{ 
	
	/*
	stringstream ss;
	char c[200];
	cin >> s;
	ss=stringstream(s);
	ss.getline(c,200,',');
	x = atoi(c);
	*/
	a.clear();
	
	cin>>N;
	for(int i=0;i<N;i++){
		int t;cin>>t;
		a.push_back(t);
	}
	
	s=accumulate(a.begin(),a.end(),0);

	for(int i=0;i<N;i++){
		double y=0;

		if(elim(y,i)){
			double mi=0,ma=1;	
			while(ma >= mi+ 1e-8){
				double mid=(ma+mi)*0.5;
				if(!elim(mid,i))
					ma=mid;
				else
					mi=mid;
			}
			y=(ma+mi)*0.5;
		}

		printf("%.12lf ",100*y);
	}
//printf("%.12lf\n",middle);
//	cout<<setprecision (15)<<endl;	
	cout<<endl;	
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