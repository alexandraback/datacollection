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

//*
#define TRY
//	#define SMALL
		#define LARGE

typedef long long ll;
#define N 1000000007



void Solve();

int r,c;
bool b[102][102];
bool f[102][102]={false};
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};

void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("C-large.txt","wt",stdout);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.txt","wt",stdout);
#endif
	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";

		Solve();
	}
}


void Solve(){
	long long b,m;
	cin>>b>>m;
	bool a[52]={false};
	long long total = 1;
	
	long long ma = total<<(b-2);
	if(ma < m){
		cout<<"IMPOSSIBLE"<<endl;return;
	}
	else{
		cout<<"POSSIBLE"<<endl;
		long long flag = b - 1;
		
		while(m!=0){
			if(m != 0 && m>=ma/2){
				a[flag] = true;
				m -= (ma+1)/2;
			}
			ma /= 2;
			flag -= 1;			
		}
	}
	char ans[52][52]={'0'};
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			if(i<j && j!=b-1) ans[i][j]='1';
			else ans[i][j]='0';
		}
	}
	for(int i=1;i<=b;i++){
		if(a[i]){
			ans[i-1][b-1]='1';
			
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
}