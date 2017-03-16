#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string.h>
#pragma comment(linker, "/STACK:10000000") 
#define md 1000000007

using namespace std;

int ls,test,t,p,i,n,a[1000005];
long long ans;
char b[1000005];

bool isLetter(int a)
{
	return (a>=97 && a<=122);
}

bool cons(int a)
{
	return (a!=97 && a!=101 && a!=105 && a!=111 && a!=117);
}
int main()
{
	ifstream f("input.txt");
	ofstream g("output.txt");
	
	f>>t;
	
	while (!isLetter(f.peek())) f.ignore();
	for (test = 1; test<=t;test++)
	{
		i=0;
		while (isLetter(f.peek()))
			b[i++] = f.get();
		b[i]='\0';
		f.get();
		f>>p;
		while (!isLetter(f.peek()) && !f.eof()) f.ignore();
		
		ans = 0;
		n = strlen(b);
		a[0]=0;
		
		for (i=1;i<=n;i++) if (cons(b[i-1])) a[i] = a[i-1]+1;
		else a[i]=0;
		
		ls = 0;
		for (i=1;i<=n;i++)
		{
			if (a[i]>=p) ls = i-p+1;
			ans = ans + ls;	
		}
		g<<"Case #"<<test<<": "<<ans<<endl;
	}
}
