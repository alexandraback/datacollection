#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
#include <sstream>
#include <set>
using namespace std;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define fz(a) fr( z, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

int main()
{
	ofstream fout ("salida.out");
    ifstream fin ("entrada.in");
    if (!fin){ cout<<"prob in"<<endl;}
	if (!fout){ cout<<"prob out"<<endl;}
	
	int t;
	fin>>t;
	cout.setf(ios::fixed, ios::floatfield);
	fk(t)
		{
		int n;
		fin>>n;
		long double j[n];
		long double y[n];
		long double score=0;
		long double x=0.0;
		long double aux=0;
		long double finalRestar;
		long double acumuladoRestar;
		long double imprimir;
		set<int> myset;
		int contador;
		fi(n)
			{
			fin>>aux;
			j[i]=aux;
			x+=aux;
			//cout<<aux<<endl;
			}
		score=(2.0*x)/n;
		//cout<<"score: "<<score<<" x "<<x<<endl;
		fout<<"Case #"<<k+1<<": ";
		acumuladoRestar=0;
		contador=0;
		fi(n)
			{
			y[i]=(score-j[i])/x;
			if(y[i]<0) 
				{
				acumuladoRestar-=y[i];
				y[i]=0;
				contador++;
				myset.insert(i);
				}
			finalRestar=acumuladoRestar/(n-contador);
			}
			
		fi(n)
			{
			if(myset.find(i)==myset.end())
				{imprimir= (y[i]-finalRestar)*100.0;}
			else
				{
				imprimir= (y[i])*100.0;
				}
			fout<<imprimir;	
			if (i!=n-1)
			fout<<" ";
			}
		fout<<endl;
		}
	
	
	return 0;
}

























