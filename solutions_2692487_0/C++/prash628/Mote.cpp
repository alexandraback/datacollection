#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");


int N;
int A[102];
int operations;

void func(int level,unsigned long long motesize,int op);
int opplus;
unsigned long long newmotesize;
int findfunc(unsigned long long motesize,int growupto);

int main()
{
	unsigned long long mote;
	int T;
	int i=0;
	fin>>T;
	int x;

	while(i<T)
	{
		operations=10000;
		fin>>mote;
		fin>>N;
		for(x=0;x<N;x++){fin>>A[x];}
		sort(&A[0],&A[N]);

		func(0,mote,0);
		fout<<"Case #";
		fout<<i+1;
		fout<<": ";
		fout<<operations;


		i++;
		if(i<T){fout<<"\n";}
	}
	return(0);
}

void func(int level,unsigned long long motesize,int op)
{
	int chk;
	//Basecase
	if(level==N)
	{
		            //cout<<level<<"\n";
		if(op<operations){operations=op;}
	}
	else
	{
	  //Case chk:if u can absorb it
	  if(motesize>A[level])
	  {
		motesize=motesize+A[level];
		func(level+1,motesize,op);
	  }
	  else
	  { 
		//Case1:delete it and move on
		func(level+1,motesize,op+1);
		//Case2:grow up to dat size
		chk=findfunc(motesize,A[level]);
		if(chk==1){func(level+1,newmotesize+A[level],op+opplus);}
	  }
	}
}

int findfunc(unsigned long long motesize,int growupto)
{
	//cout<<"i was here!!";
	unsigned long long x=motesize;

	int xtraop=0;

	if(x==1){opplus=10000;newmotesize=x;return(0);}
	else
	{
		while(x<=growupto)
	    {
		x=x+x-1;
		xtraop++;
		if(xtraop>100){return(0);}
	    }
	    opplus=xtraop;
	    newmotesize=x;
		return(1);
	}
}

