#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long A,B,D,N,V,VYSL;
int T;

long long GCD(long long x,long long y)
	{
	 long long t;
	 while (y!=0)
	 	{
	 	 t=y;
	 	 y=x%y;
	 	 x=t;
	 	}
	 return x;
	}

long long naj(long long b) //najblizsia mocnina dvoch >=b
	{
	 //return 2^x
	 long long o;
	 o=0;
	 while (pow(2,o)<b)
	 	{
	 	 o++;
	 	}
	 return o;
	}

long long vys(long long r,long long b)
	{
	 long long zv;
	 long long vysledok=-1;
	 zv=(long long)(pow(2,r)) % b;
	 while ((r<=40)&&(zv!=0))
	 	{
	 	 r++;
	 	 zv*=2;
	 	 zv=zv%b;
	 	}
	 if (zv==0) {vysledok=r;}
	 return vysledok;
	}

int vypis(long long h,int p)
	{
	 //Case #1: 1
	 cout<<"Case #"<<p<<":"<<" ";
	 if (h==-1) {cout<<"impossible";}
	 else {cout<<h;}
	 cout<<endl;
	 return 0;
	}

long long pocitaj(long long A,long long B)
	{
	 int pocitadlo=1;
	 if (A==B) {return 0;}
	 while(A<B/2)
	 	{
	 	 B/=2;
	 	 pocitadlo++;
	 	}
	 return pocitadlo;
	}

int main() {
	cin>>T;
	for (int u=1;u<=T;u++)
		{
		 cin>>A;
		 char o;
		 scanf("%c",&o);
		 cin>>B;
		 D=GCD(A,B);
		 A=A/D;
		 B=B/D;
		 //A a B su v zakladnom tvare
         N=naj(B);
         //2^N je najblizsia >= mocnina dvoch
         V=vys(N,B);
		 //2^V je cislo, ktore moze byt delene B-ckom
         if ((V==-1)||(A==0)) {vypis(-1,u);}
         else
          {
           A*=pow(2,V)/B;
           B=pow(2,V);
           VYSL=pocitaj(A,B);
           vypis(VYSL,u);
          }
		}
	return 0;
}
