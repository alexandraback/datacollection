#include<iostream>
#include<stdio.h>
#include<list>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<map>
#define ff first
#define ss second
#define ll long long int 
#define mod 1000000007
using namespace std;
int gcd(int a ,int b)
{
	if(a%b==0)
	return a;
	else
	return gcd(b,a%b);
}
ll read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

int main() {
	freopen("abc.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	ll t, row, col, wid;
	cin >> t;
	for (int casex = 0; casex<t; casex++)
	{
		ll xex = 0;
		//cin >> row >> col >> wid;
           row=read_int();
           col=read_int();
           wid=read_int();
 
		xex = col / wid *row;
 
		xex += wid - 1;
		if (col%wid != 0)
			xex++;
		cout << "Case #" << casex + 1 << ": " << xex << endl;
	}
 
	return 0;
}
