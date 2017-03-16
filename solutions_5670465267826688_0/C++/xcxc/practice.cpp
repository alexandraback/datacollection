/*
ID: xiaoche4
PROG: skidesign
LANG: C++
*/
//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int T,L,X;
string S;
int mul[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int divv[5][5]={{0,0,0,0,0},{0,1,-2,-3,-4},{0,2,1,4,-3},{0,3,-4,1,2},{0,4,3,-2,1}};
int val[10000];
int m(int a,int b){
	bool sign=a*b<0;
	a=abs(a); b=abs(b);
	a=mul[a][b];
	return sign ? -a:a;
}
int d(int a,int b){
	bool sign=a*b<0;
	a=abs(a); b=abs(b);
	a=divv[a][b];
	return sign ? -a:a;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	//freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T; string get;
	for(int k=1;k<=T;k++){
		cin>>L>>X>>get;
		if(L*X<3){
			fout<<"Case #"<<k<<": NO"<<endl;
			continue;
		}
		for(int i=0;i<get.length();i++){
			if(get[i]=='i') get[i]='2';
			if(get[i]=='j') get[i]='3';
			if(get[i]=='k') get[i]='4';
		}
		for(int i=0;i<X;i++)
			S.append(get);
		val[0]=S[0]-'0';
		for(int i=1;i<S.length();i++){
			val[i]=m(val[i-1],S[i]-'0');
		}
		bool sign=false;
		for(int i=0;i<S.length();i++){
			if(val[i]!=2) continue;
			for(int j=S.length()-1;j>i+1;j--){
				if(d(val[S.length()-1],val[j-1])!=4) continue;
				if(d(val[j-1],val[i])==3){
					sign=true;
					break;
				}
			}
			if(sign) break;
		}
		if(sign){
			fout<<"Case #"<<k<<": YES"<<endl;
		}else{
			fout<<"Case #"<<k<<": NO"<<endl;
		}
		S.clear();
		cout<<k<<" ok"<<endl;
	}

	return 0;
}