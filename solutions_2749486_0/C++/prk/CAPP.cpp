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
	freopen("C:\\Users\\prk\\Downloads\\B-small-attempt1 (1).in","r",stdin);
	//freopen("C:\\Users\\prk\\Downloads\\A-large-practice (4).in","r",stdin);
	freopen("d:\\Output.txt","w",stdout);//*/
}

typedef int dint;
dint dcx,cy,ddx,dy,n;
char en;
void chalo()
{dint nn;
	if(en=='e' && dcx!=ddx)
	{
		if(dy!=cy) en='n';
		char move=0;
		if(ddx<0)
		{
			move='w';
			nn=-n;
			if(dcx+nn < ddx) {move ='e'; dcx-=nn;}
			else dcx+=nn;
		}
		else
		{
			move='e';
			nn=n;
			if(dcx+nn > ddx) {move ='w'; dcx-=nn;}
			else dcx+=nn;
		}
		cout<<(char)toupper(move);
		n++;
	}
	else if(cy!=dy)
	{
		if(ddx!=dcx) en='e';
		char move=0;
		if(dy<0)
		{
			move='s';
			nn=-n;
			if(cy+nn < dy) {move ='n'; cy-=nn;}
			else cy+=nn;
		}
		else
		{
			move='n';
			nn=n;
			if(cy+nn > dy) {move ='s'; cy-=nn;}
			else cy+=nn;
		}
		cout<<(char)toupper(move);
		n++;
	}
	else en='e';
}
int main()
{fileinput();
	int T,t=0;
	cin>>T;
	
	while(++t<=T)
	{
		n=1;
		dcx=0;cy=0;
		cin>>ddx>>dy;
		if(abs(ddx)<abs(dy)) en='e';else en='n';
		cout<<"Case #"<<t<<": ";
		while(dcx!= ddx || cy!=dy) chalo();
		cout<<endl;
	}
}
