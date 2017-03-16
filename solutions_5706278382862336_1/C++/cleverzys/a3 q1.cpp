#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>

using namespace std;
#define RR 50
#define CC 50
char str[RR][CC];
//#define TRY
//#define SMALL
#define LARGE
int Solve();
long long Gcd(long long a,long long b);
int main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	int Numcase;
	cin>>Numcase;
	char c;
	string a;
	getline(cin,a);
	//*
	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		int p=Solve();
		if(p==-1)
			cout<<"impossible"<<endl;
		else

			cout<<p<<endl;
	}
	//*/
	

}
int Solve()
{
	string str,b,c;
	getline(cin,str);
	//cout<<str;
	int l=str.size();
	int i;
	for(i=0;i<l;i++){
		if(str[i]=='/')
			break;
		b=b+str[i];
	}
	i++;
	for(;i<l;i++){
		c+=str[i];
	}
	
	long long cc,bb;
	std::stringstream sstr;
	sstr<<b;
	sstr>>bb;
	sstr.clear();//
	sstr<<c;
	sstr>>cc;
	sstr.clear();//
	//cout<<bb<<" "<<cc<<endl;
	//bb = atoi(b.c_str());
	//cc = atoi(c.c_str());
	//cout<<bb<<" "<<cc<<endl;
	long long temp=Gcd(bb,cc);
	
	bb=bb/temp;
	cc=cc/temp;
	
	double p,q;
	double tem;
	double bbb=bb;double ccc=cc;
	while(ccc!=1)
	{
		ccc=ccc/2;
		if(ccc!=(long long)ccc)
			return -1;
	}
	int j=1;
	while(cc>=1){
		if(bb-cc/2>=0)
			return j;
		j++;
		cc=cc/2;
	}
	

}
long long Gcd(long long a,long long b)
{
	long long r=a;
	while(r!=0)
	{a=b;b=r;r=a%b;}
	return b;
}