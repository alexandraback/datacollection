// Created by alex_mat21. And it works!

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <string> 
#include <iomanip>
#include <cmath>
#include <utility>
 
#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define vi vector<int>
#define fs first
#define sd second
#define pii pair<int,int>

using namespace std;

int main (){
int t111;
cin >> t111;
int r,c,w,t,m;
int a[22];
int s[22];
for (int i111=0 ; i111<t111; i111++){
	cin >> r >> c >> w;
	t=1 << (c-1);
	m=(c-w+1)*r+w-1;
	for (int i=1; i<t; i++){
		int u=i;
		int x=0;
		int m1=-1;
		s[0]=0;
		a[0]=0;
		for (int j=1; j<=c ; j++){
			if (u-((u >> 1)<< 1) ==0)
				a[j]=0;
			else{
				a[j]=1;
				x++;
				}
			u=u>>1;
			s[j]=s[j-1]+a[j];
		}
		for (int j=1; j+w-1<=c ; j++){
			if (s[j+w-1]-s[j-1]==0){
				m1=-1;
				break;
				}
			else if (s[j+w-1]-s[j-1]==1){
				if ((j>1 && s[j+w-2]-s[j-2]==1) || (j+w-1<c && s[j+w]-s[j]==1)){
					m1=w;
					}
				else 
					m1=w-1;
				}
			//else{
			//	m1=max(m1,w-s[j+w-1]+s[j-1]);
			//	}
			//cout << j << ' ' << m1 << endl;
			}
		if (m1>-1)
			m=min(m,x*r+m1);
			
		//cout << i << ' ' << m << ' ' << x << ' ' << m1 <<endl;
		} 

	cout << "Case #"<< i111 +1 << ": " << m<< endl;
	}
return 0;
}
