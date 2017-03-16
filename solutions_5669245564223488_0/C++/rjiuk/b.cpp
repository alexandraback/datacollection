#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

int t,n;
int A[23];
int B[23];
int C[23];
string all[111];
string odd[111];
LL mod = 1000000007;
LL licz()
{
	string calosc="";
	bool ok = 1;
	/*FOR(i,1,n+1)
		cout<<A[i]<<" ";
		cout<<"\n";*/
	FOR(i,1,n+1)
		FOR(j,1,n+1)
			if(A[i]+n == A[j])
				return 0;
	FOR(i,1,n+1)
		odd[i]=all[A[i]];
	FOR(i,1,n+1)
		calosc+=odd[i];
		
	FOR(i,'a','z'+1)
	{
		int was = 0;
		int done = 0;
		FOR(j,0,calosc.size())
			if(calosc[j]==i && was==0)
				was=1;
			else if(calosc[j]==i && was==1 && done==0)
				was=1;
			else if(calosc[j]==i && was==1&& done==1)
				ok=0;
			else if(calosc[j]!=i && was==1)
				done=1; 
	}
	if(ok==1)
		return 1;
	calosc="";
	for(int i =n-1;i>=0;i--) 
		calosc+=odd[i];
		
	FOR(i,'a','z'+1)
	{
		int was = 0;
		int done = 0;
		FOR(j,0,calosc.size())
			if(calosc[j]==i && was==0)
				was=1;
			else if(calosc[j]==i && was==1 && done==0)
				was=1;
			else if(calosc[j]==i && was==1&& done==1)
				return 0;
			else if(calosc[j]!=i && was==1)
				done=1; 
	}
	//cout<<"ok\n";
	return 1;
}

LL permutuj()
{
	FOR(i,1,n+1)
		B[i]=A[i];
	FOR(i,0,n)
		C[i]=i+1;
	LL w = 0;		
	do
	{
		FOR(i,1,n+1)
			A[i]=B[C[i-1]];
		w+=licz();
	}while(next_permutation(C,C+n));
	FOR(i,1,n+1)
		A[i]=B[i];
	return w;
}


LL szukaj()
{
	FOR(i,1,n+1)
		A[i]=i;
	int p = n;
	LL wynik=0;
	while(p>=1)
	{
		wynik+=licz();
		if(A[n]==n*2)p--;
		else p = n;
		if(p>=1)
		{
			for(int i = n ;i>=p;i--)
				A[i]=A[p]+i-p+1;
		}
	}
	return wynik;
}


void dane()
{
	cin>>t;
	FOR(przy,1,t+1)
	{
		cin>>n;
		FOR(i,1,n+1)
			cin>>all[i];
		FOR(i,1,n+1)
		{
			string akt = "";
			for(int j = all[i].size()-1;j>=0;j--)
				akt+=all[i][j];
			all[i+n]=akt;
		}
		cout<<"Case #"<<przy<<": "<<szukaj()<<"\n";	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	dane();
	return 0;
}
