#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>
#include <list>
#include <queue>

using namespace std;


#define infi 987654321
#define FUCK(i,n) for(i=0;i<n;i++)
#define FUCKI(i,j,n) for(i=j;i<n;i++)

long long power(long long C,long long y,long long m)
{
	long long temp;
	if( y == 0)
		return 1;
	temp = power(C,y/2,m)%m;
	if (y%2 == 0)
		return ((temp % m)*(temp% m))%m;
	else
		return (((((C)*(temp))%m)*(temp))%m)%m;
}

int main()
{
	long long n,m,i,j,k;
	int t,C;
	cin>>t;
	for(C = 1;C <= t;C++){
		
		long long ans = 0;
		string a;
		long long e;
		cin>>e>>n;
		if(n>0){
			FUCK(i,n){
				a.push_back('S');
				a.push_back('N');
			}
		}
		if(n<0){
			FUCK(i,(abs(n))){
				a.push_back('N');
				a.push_back('S');
			}
		}
		if(e>0){
			FUCK(i,e){
				a.push_back('W');
				a.push_back('E');
			}
		}
		if(e<0){
			FUCK(i,abs(e)){
				a.push_back('E');
				a.push_back('W');
			}
		}
		cout<<"Case #"<<C<<": "<<a<<endl;
	}
	return 0;
}
