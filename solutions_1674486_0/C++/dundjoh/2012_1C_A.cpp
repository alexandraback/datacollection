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
int		InputSelect		= 5;
string	ProblemLetter	= "A";	
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

const int NMAX=1011;
bool path[NMAX];

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
	
	int N;
	cin>>N;
	vector<vector<int>> inh(N);
	fii(N){
		int M;cin>>M;
		inh[i].resize(M);
		fij(M){ cin>>inh[i][j];
		inh[i][j]--;}
		

	}

	

	fii(N){
		fij(N) path[j]=false;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int k=q.front();
			q.pop();
			auto& inh2 = inh[k];
			fij(inh2.size()){
				int  h=inh2[j];
				if(path[h]){
					cout<<"Yes"<<endl;
					return;
				}
				path[h]=true;
				q.push(h);
			}
		}
	}
	
	cout<<"No"<<endl;

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