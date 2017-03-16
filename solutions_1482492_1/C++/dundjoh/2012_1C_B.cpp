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
#include <functional>
#include <iterator>	
#include <numeric>
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
string	ProblemLetter	= "B";	
bool	FileOutput		= 1;	//stdout is redirected into a file
bool	SeperateOutput	= 0;	//Produce a separate output file for each input
string	Attemp			= "0";

#define fii(a) for( int i=0;i< ( a );i++)
#define fij(a) for( int j=0;j< ( a );j++)
#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define MP make_pair;
#define MT make_tuple;

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
	
	int N,A;
	double d;
	
	cin>>d>>N>>A;
	vector<double> t,x,as(A);
	bool done=false;
	fii(N){
		double t2,x2;
		cin>>t2>>x2;
		if(!done){
			if(x2 > d){
				if(i>0){
					double x1=x.back(),t1=t.back();
					t2=(d*(t1 - t2) + t2*x1 - t1*x2)/(x1 - x2);
				}
				x2=d;
				done=true;
			}
			t.push_back(t2);
			x.push_back(x2);
		}
	}
	fii(A) cin>>as[i];
	
	cout<<endl;
	fii(A){
		double a=as[i],mx=0,v=0;
		for(uint j=1;j<t.size();j++){
			double dt=t[j]-t[j-1];
			mx += 0.5*a*dt*dt + v*dt;
			if(x[j] < mx){ //must not overtake
				mx = x[j];
				v = (x[j]-x[j-1])/(t[j]-t[j-1]);
			}else
				v+=a*dt;
		}
		double r=t.back();
		if(mx<d)
			r+=(-v+sqrt(2*a*d - 2*a*mx + v*v))/a;
		cout<<setprecision (15)<<r<<endl;
	}
	//printf("%.12lf\n",middle);
//	cout<<setprecision (15)<<endl;	
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