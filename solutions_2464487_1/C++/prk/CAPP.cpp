// CAPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"//visual studio
#include<stdio.h>
#include<conio.h>
#include"ttmath\ttmath.h"
#include <iostream>
using namespace std;

// Big<exponent, mantissa>
typedef ttmath::Big<19,5> MyBig;//Online ttmath library www.ttmath.org
#include<conio.h>
       

#define iout(X) //printf("%s:",#X); cout<<X<<endl;
void fileinput()
{//Downloads
	freopen("C:\\Users\\prk\\Downloads\\A-large.in","r",stdin);
	freopen("d:\\Output.txt","w",stdout);//*/
}
int main()
{fileinput();
	MyBig r,t,n,rt;
	int T,_t=0;
	cin>>T;

	while(++_t<=T)
	{
		cin>>r>>t;
		rt=r*2-1;
		n=-rt;
		rt.Pow(2);
		MyBig b=t*8+rt ;
		iout(t*8)
			iout(rt)
			iout(rt.Pow(2))
		iout(b)
		b.Sqrt();
		n+=b;
		iout(n)
		n/=4;
		
		cout<<"Case #"<<_t<<": "<<n.ToUInt()<<endl;
	}
}

