#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>
using namespace std;

////////////////////////////////////////////////////
#define TRY
#define SMALL
//#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
void Per(int pos,int n);
string S(string a);
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("D-small-attempt0.in","rt",stdin);
	freopen("D-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("D-large.in","rt",stdin);
	freopen("D-large.txt","wt",stdout);
#endif

	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		//cout<<"Case #"<<test<<":"<<endl;
		Solve();
	}
}
void Solve(){
	int X,R,C;
	cin>>X>>R>>C;
	
	/*
	if(X==1){
		cout<<"GABRIEL"<<endl;
	}
	else if(X==2){
		cout<<"GABRIEL"<<endl;
	}
	else if(X==3){
		if(R==1 || C==1) cout<<"RICHARD"<<endl;
		else cout<<"GABRIEL"<<endl;
	}
	else if(X==4){
		if(R==1 || C==1) cout<<"RICHARD"<<endl;
	}
	//*/
	int mi = min(R,C);
	int ma = max(R,C);
	if( (R*C) % X !=0){cout<<"RICHARD"<<endl;}
	else if(X > ma) {cout<<"RICHARD"<<endl;}
	else if(X >= 7) {cout<<"RICHARD"<<endl;}
	else if(X==1) {cout<<"GABRIEL"<<endl;}
	else if(X==2) {cout<<"GABRIEL"<<endl;}
	else if(X==3 && mi==1) {cout<<"RICHARD"<<endl;}
	else if(X==4 && (mi==1 || mi==2)) {cout<<"RICHARD"<<endl;}
	else if(X==5 && (mi==1 || mi==2)) {cout<<"RICHARD"<<endl;}
	else if(X==6 && (mi==1 || mi==2 || mi==3)) {cout<<"RICHARD"<<endl;}
	else cout<<"GABRIEL"<<endl;
}