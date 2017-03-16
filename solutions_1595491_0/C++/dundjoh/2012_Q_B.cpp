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
string	ProblemLetter	= "B";	
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

int m[102][102];

void main2()
{ 
	int N,S,p;
	cin>>N>>S>>p;

	for(int i=0;i<=N;i++)
		for(int s=0;s<=100;s++) 
			m[i][s]=-1000000;

	m[0][0]=0;

	for(int i=1;i<=N;i++)
	{
		int t;cin>>t;

		int r=t%3;
		int b=t/3;
		int ws;
		int wos;
		int d;

			switch(r){
			case 0:
				wos = b>=p ? 1 : 0;
				if(b==0){
					d=0;
					ws=wos;
				}else{
					ws = b+1>=p ? 1 : 0;
					d = 1;
				}
				break;
			case 1:
				wos= b+1>=p ? 1 : 0;
				if(b==0){
					d=0;
					ws=wos;
				}else{
					ws = b+1>=p ? 1 : 0;
					d = 1;
				}
				break;
			case 2:
				wos= b+1>=p ? 1 : 0;
				ws = b+2>=p ? 1 : 0;
				d = 1;
				break;
			}

			m[i][0]=wos+m[i-1][0];

			for(int s=1;s<=100;s++)
				m[i][s] = max(ws+m[i-1][s-d],wos+m[i-1][s]);
			

	}
	//printf("%.12lf\n",middle);
	cout<<m[N][S]<<endl;	
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