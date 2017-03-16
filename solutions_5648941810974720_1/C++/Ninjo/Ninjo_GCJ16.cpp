// __________ AUTHOR INFO __________
// Name/    Khaled Alam
// Email/   khaledalam.net@gmail.com
// Insta/   @MrKhaledAlam
// Twitter/ @Mr_KhaledAlam
// Website/ KhaledAlam.net
//__________________________________

#include <bits/stdc++.h>

/*
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
*/

//____________________
using namespace std;


#define I   int
#define UI  unsigned int
#define LL  long long
#define ULL unsigned long long
#define V   vector
#define oo  ((const I)1e9)
#define MOD ((const I)1e9+7)
#define PI  ((const double)2*acos(0.0));
#define SZ(X) (int)X.size()
#define FI first
#define SE second
#define PB push_back
#define PF push_front
#define MP make_pair
#define ODD(n)  (n&1)
#define ONES(N) __builtin_popcountp((LL)N)
#define ALL(C)  C.begin(), C.end()
#define rALL(C) C.rbegin(), C.rend()
#define rSORT(C) sort(ALL(C), std::greater<LL>())
#define FOR(V,A,Z,P)   for(LL V=A; V<Z;  V+=P)
#define FORe(V,A,Z,P)  for(LL V=A; V<=Z; V+=P)
#define rFOR(V,A,Z,P)  for(LL V=A; V>Z;  V-=P)
#define rFORe(V,A,Z,P) for(LL V=A; V>=Z; V-=P)
#define IOS ios_base::sync_with_stdio(0)
#define SET(A,V) memset(A,(typeof(V))V,sizeof(A))
#define iFILE(N) freopen(#N, "r", stdin)
#define oFILE(N) freopen(#N, "w", stdout)
#define TM cerr<<"Time elapsed: "<<clock()<<" ms\n";
#define scan(n) scanf("%d",&n)
#define scanll(n) scanf("%lld",&n)
#define For(i,a,b) for(i=a;i<b;i++)
#define fill(a,b) memset(a,b,sizeof(a))
#define swap(a,b) a=a+b;b=a-b;a=a-b;
#define ll long long int
#define pb push_back
#define MAX 1000000007
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
//#define MX
//I vis[100];


int main()
{

	iFILE(input.txt);
	oFILE(output.txt);
	I coun[100];
		I t , p =0;
		string s;
		cin>>t;
		while(t--)
		{
			p++;
			map<char,int>a;
			cin>>s;
			for(int i =0 ;i<s.length();i++)
				a[s[i]]++;
			coun[0] = max(0 , a['Z']);
			coun[6] = max(0 , a['X']);
			coun[8] = max(0 , a['G']);
			coun[4] = max(0 , a['U']);
			coun[2] = max(0 , a['W']);
			coun[3] = max( 0  , a['T'] - a['W'] - a['G']);
			coun[7] =  max(0 , a['S'] - a['X']);
			coun[5] = max(0 , a['V'] - coun[7]);
			coun[1] = max(0 , a['O'] - coun[2] - coun[4] - coun[0]);
			coun[9] = (max(0 , a['N'] - coun[1] - coun[7]))/2;
			cout<<"Case #"<<p<<": ";
			for(int i =0 ;i<=9;i++)
			{
				for(int j =0 ;j<coun[i];j++)
				cout<<i;
			}
			cout<<endl;
		}
	}
