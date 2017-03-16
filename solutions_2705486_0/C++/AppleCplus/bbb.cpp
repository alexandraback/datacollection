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
#define pss pair<string,string>
#define psi pair<string,int>
#define X first 
#define Y second
#define pb push_back
#define mp make_pair
#define ab(x) ((x)<0?(-(x)):(x))
#define xx(x) ((x)*(x))
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pi>
#define ALL(x) (x).begin(),(x).end()
#define Max (1<<30)
#define LLMAX (1ll<<60)
#define MM 2000000000000000000ll
#define mod 1000000007
template<class T>string ToString(T t){stringstream s;s<<t;return s.str();}
template<class T>void ToOther(T&t,string a){stringstream s(a);s>>t;}

int N= 521196 ;

FILE *DIC=fopen("temp.txt","r");
int rst;

bool can[4444][11][11][11];
int d[4444][11];

vs dic[11];
string s;
int n;

int go(int idx,int rest){

	if(rest<0)rest=0;

	if(idx==n)return 0;

	int &r=d[idx][rest];
	if(r>=0)return r;
	r=Max;

	for(int L=1;L<=10;L++){
		if(idx+L>n)break;
		for(int A=0;A<=10;A++)for(int B=0;B<=10;B++){
			if(can[idx][L][A][B]){
				if(A==0 && B==0)r=min(r,go(idx+L, rest-L));
				else{
					if(rest<A){
						int cnt=2;
						int last=B;
						if(B==0)cnt=1,last=A;
						r=min(r, cnt + go(idx+L,4+last-L) );
					}
				}
			}
		}
	}

	return r;
}

int main(){
	char bur[33];
	
	for(int i=0;i< 521196 ;i++){
		fscanf(DIC,"%s",bur);
		string t=bur;
		dic[t.size()].pb(t);
	}
	
//	dic[4].pb("code");
//	dic[3].pb("jam");
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int Test;
	cin>>Test;
	for(int C=1;C<=Test;C++){
		memset(can,0,sizeof(can));
		cin>>s;
		n=s.size();
		for(int i=0;i<n;i++){
			for(int L=1;L<=10;L++){
				if(i+L>n)break;

				
				for(int k=0;k<dic[L].size();k++){

					int A=-1,B=-1;

					for(int t=0;t<L;t++)if(s[i+t]!=dic[L][k][t]){
						 if(A==-1){
							 A=t;
						 }else if(B==-1){
							 B=t;
						 }else{
							 goto NO;
						 }
					}
					if(B-A>=5)can[i][L][A+1][B+1]=1;
					if(B==-1)can[i][L][A+1][B+1]=1;
					if(A==-1)can[i][L][A+1][B+1]=1;
					NO:;
				}

			}
		}

		memset(d,-1,sizeof(d));
		int rst=go(0,0);
		cout<<"Case #"<<C<<": "<<rst<<endl;
	}
}