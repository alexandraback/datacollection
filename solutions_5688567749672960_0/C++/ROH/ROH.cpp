// ROH.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<map>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<bitset>
#include<fstream>
#include<set>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<math.h>
#include<time.h>
using namespace std;

#define scan scanf_s
#define sscan sscanf_s
#define get gets_s
#define print printf 
#define mod 1000000007
#define ll long long
#define init int i,j,k,l,m,n,test
#define pause system("pause")
#define inf 1000000000

int reverse(int x)
{
	int i,j,k;
	j=0;i=0;
	k=x;
	while(k>0)
	{
		k/=10;
		j++;
	}
	j--;
	while(x>0)
	{
		i+=(x%10)*pow(10,j);
		x/=10;
		j--;
	}
	return i;
}
int a[1000009];
int main()
{
	init;
	ifstream in("C:\\Users\\Ray\\Desktop\\google\\1\\A-small-attempt0.in");
	ofstream out("C:\\Users\\Ray\\Desktop\\google\\1\\1_out.txt");
	in>>test;
	a[1]=1;
	for(i=0;i<1000009;i++)
		a[i]=inf;
	a[1]=1;
	//cout<<reverse(1065)<<endl;;
	for(i=2;i<1000002;i++)
	{
		a[i]=min(a[i],a[i-1]+1);
		a[reverse(i)]=min(a[reverse(i)],a[i]+1);
	}
	k=1;
	while(test--)
	{
		in>>n;
		out<<"Case #"<<k++<<": "<<a[n]<<endl;

	}
	
	
	pause;
	
}