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
typedef vector<int> vi;
typedef vector<int64> vl;
typedef map<int,int> mii;
typedef mii::iterator miiit;
typedef multimap<int,int> mmii;
typedef mmii::iterator mmiiit;


string G;
string S;


//initianlization depending on the number of cases
void init(int T)
{
	G="y qeeejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	S="a zooour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	for(char c='a';c<'z';c++){
		uint j;
		for(j=0;j<G.length();j++){
			if(S[j]==c)
				break;
		}
		if(j==G.length()){
			S+=c;
			G+="z";
			cerr<<c<<endl;
			return;
		}
	}
}


void main2()
{ 
	char c[200];
	cin.getline(c,200);
	//cout<<c<<endl;
	for(int i=0;c[i];i++){
		uint j;
		for(j=0;j<G.length();j++){
			if(G[j]==c[i]){
				cout<<S[j];
				break;
			}
		}
		if(j==G.length())
			cerr<<"not oc"<<c[i]<<endl;
	}
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