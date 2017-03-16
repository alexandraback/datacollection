#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pii pair<int,pi>
#define X first
#define Y second
#define pb push_back
#define ab(x) ((x)<0?(-(x)):(x))
#define xx(x) ((x)*(x))
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vpi vector<pi>
#define vpll vector<pll>
#define ALL(x) (x).begin(),(x).end()
#define Max (1<<30)
#define LLMax (1ll<<60)
template<class T>string ToString(T t){stringstream s;s<<t;return s.str();}
template<class T>void ToOther(T&t,string a){stringstream s(a);s>>t;}

int n,m,cnt;
char r[55][55];
char a[55][55];

void FireTruck(char k){for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<((i+j==0)?'c':k);cout<<endl;}}
void WhatThe(int k){
	int c=0;
	for(int i=0;i<n;i++){for(int j=0;j<m;j++){
		k--;
		if(k>=0)cout<<(c==0?'c':'.'),c++;
		else cout<<'*';
	}cout<<endl;}
}

void go(int y,int x){
	if(y==0 && x==0)a[y][x]='c';
	else a[y][x]='.';

	for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++){
		int ny=y+i;
		int nx=x+j;

		if(ny<0 || ny>=n || nx<0 || nx>=m)continue;
		if(r[ny][nx]=='*')return;
	}
	for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++){
		int ny=y+i;
		int nx=x+j;

		if(ny<0 || ny>=n || nx<0 || nx>=m)continue;
		if(a[ny][nx]=='*')go(ny,nx);
	}
}
void Siiiiiiiiiii(){
	int need=n*m-cnt-1;

	if( need < 3 ) {cout<<"Impossible"<<endl; return;}
	need-=3;
	r[0][1]=r[1][0]=r[1][1]='.';

	int x=2,y=2;
	while(1){
		int flag=0;
		if(x<m && need>=2){
			flag++;
			r[0][x]=r[1][x]='.';
			x++;	need-=2;
		}
		if(y<n && need>=2){
			flag++;
			r[y][0]=r[y][1]='.';
			y++;	need-=2;
		}
		if(flag==0)break;
	}
	for(int i=0;i<y;i++)for(int j=0;j<x;j++)if(r[i][j]=='*' && need){
		need--;r[i][j]='.';
	}
	if(need){cout<<"Impossible"<<endl; return;}
	for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<r[i][j];cout<<endl;}

	go(0,0);

}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int CC=0;
	int Test; cin>>Test; while(Test--){
		CC++;
		memset(r,(int)'*',sizeof(r));
		r[0][0]='c';

		memset(a,(int)'*',sizeof(a));

		cin>>n>>m>>cnt;
		cout<<"Case #"<<CC<<": "<<endl;

		if(cnt==0)FireTruck('.');
		else if(n*m-cnt==1)FireTruck('*');
		else if(n==1 || m==1)WhatThe(n*m-cnt);
		else Siiiiiiiiiii();

	}
}