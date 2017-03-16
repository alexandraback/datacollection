#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define DEBUG
#define pf printf
#define sf scanf
#ifdef DEBUG
#define iout(X) printf("@Line:%d,%s:%d\n",__LINE__,#X,X);
#define vout(c,X) printf("@Line:%d,%s:",__LINE__,#X);printf(#c,X);printf("\n");
#define dstat(...) __VA_ARGS__
#define ndstat(...)
#define dpf pf
#define CL printf("Continue frm line :%d\n",__LINE__);
#else
#define CL
#define iout(X) 
#define vout(c,X) 
#define dstat(...) 
#define dpf(...)
#define ndstat(...) __VA_ARGS__
#endif
#include<string.h>
void fileinput()
{//Downloads
	freopen("C:\\Users\\prk\\Downloads\\A-small-attempt0.in","r",stdin);
	//freopen("C:\\Users\\prk\\Downloads\\A-large-practice (4).in","r",stdin);
	freopen("d:\\Output.txt","w",stdout);//*/
}

	char c[1000000];long int n,L;
	long int no=0;
int isc(char c)
{
	char *v="aeiou";
	int i=-1;
	while(++i<5) if(c==v[i]) return 0;
	return 1;
}

int noc(char *X,int x)
{
	//n tho!
	int i=0;long int times=0;
	while(i<=x)
	{
		if(isc(X[i])) times++;
		else times=0;
		if(times==n) return 1;
		i++;
	}
	return 0;
}
void dotraverse()
{
	long int x=0,j;
	for(;x<=L-n;x++)
	{
		for(j=n-1;j<L-x;j++)
			if(noc(c+x,j)) {no++;break;}
		for(j++;j<L-x;j++) no++;
	}
}
int main()
{fileinput();
	int T,t=0;
	cin>>T;
	gets(c);//Dummy
	while(++t<=T)
	{
		no=0;
		cin>>c;
		L=strlen(c);
		cin>>n;
		dotraverse();
		cout<<"Case #"<<t<<": "<<no<<endl;
	}
}
