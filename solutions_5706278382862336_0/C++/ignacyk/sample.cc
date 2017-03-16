#include <iostream>
#include<stdio.h>
#include "BigIntegerLibrary.hh"
#include <string>    
   
using namespace std;

BigInteger nwd(BigInteger a,BigInteger b)
{
    BigInteger c;                    
    while(b != 0)            
    {
        c=a % b;             
        a = b;                
        b = c;                
    }
    return a;               
}

int main()
{
int i,j,k,T;
string a,b;
BigInteger ba,bb,bnwd;
ba=1;
BigInteger tab[41];
for (i=0;i<41;i++) {
  tab[i]=ba;
  ba=ba*2;
}


cin>>T;
getline(cin,a);
for (i=1;i<=T;i++) {
	
	cout<<"Case #"<<i<<": ";
 	getline(std::cin,a,'/');
	getline(std::cin,b);
	//cout<<a<<endl;
	ba=stringToBigInteger(a);
	bb=stringToBigInteger(b);
	if (bb<ba) {cout<<"impossible"<<endl;continue;}
	bnwd=nwd(ba,bb);
	//cout<<bnwd<<endl;
	ba=ba/bnwd;
	bb=bb/bnwd;
	for (j=0;j<41;j++) {
		if (bb==tab[j]) break;
		}	
	if (j<41) {
		//cout<<"ba = "<<ba<<endl;
		k=0;
		while (ba>=tab[k] && k<41) k++;
		cout<<j-k+1<<endl;
		}
	else {cout <<"impossible"<<endl;}
  	}
return 0;
}



