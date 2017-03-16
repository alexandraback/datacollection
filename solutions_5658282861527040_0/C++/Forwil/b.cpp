/*
ID: forwil11
PROG: 
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,t,T;

int main(void){
	int a,b,c,ans = 0;

	cin >> T;
	for(int t =1;t<=T;t++)
	{
		cout << "Case #"<<t<<": ";
		cin >> a >> b >> c;
		ans =0;
		for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if((i & j) < c)
				ans += 1;
		cout << ans << endl;
	}
	return 0;
}
