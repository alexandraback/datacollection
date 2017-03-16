#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef unsigned long long ul;
typedef pair<int,int> pii;
vector<int> fn(5001,0);

void calcfn()
{
	fn[0]=1;
	for(int i=1;i<5001;i++)
	{
		fn[i]=fn[i-1]+4*i+1;
	}
}

double calc(int n, int c, int m)
{
	double p;
	double comb=1;
	if(n>c)
		return (double)(c-n+m)/(2*c-n+1);
		
	for(int i=0;i<=m-1;i++)
	{
		if(i!=0)
		    comb=comb*(n-i+1)/i;
		if(n-c>i)
			continue;
		p+=comb/pow(2,n);
	}	
	
	return 1-p;
}

double judge(int N, int X, int Y)
{
	if(N==1)
	{
		if(X==0&&Y==0)
			return 1;
		else
			return 0;
	}
	int ui=upper_bound(fn.begin(),fn.end(),N)-fn.begin();
	int li=ui-1;
        int lx=li*2, ux=ui*2;
	if(Y<=lx-X && Y<=lx+X)
		return 1;
	if(Y>ux-X || Y> ux+X)
		return 0;

	int cap=fn[ui]-fn[li];
	int halfcap=(cap-1)/2;
	int rem=N-fn[li];
	if(X==0)
		return	rem==cap?1:0;
	int binseq=(X>0)?ux-X+1:ux+X+1;
	if(halfcap+binseq<=rem)
		return 1;
	else
		return calc(rem,halfcap,binseq);
}


int main() {
 
        int T;
        cin>>T;
        int count=1;
	calcfn();
        while(T--)
        {
		int N,X,Y;
		cin>>N>>X>>Y;
                cout<<"Case #"<<count++<<": "<<judge(N,X,Y)<<endl;
        }



        return 0;
}
