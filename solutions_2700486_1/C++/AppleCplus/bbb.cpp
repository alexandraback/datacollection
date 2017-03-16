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




ll x,y;
ll n;
ll need;
ll lev;
ll h;
double d[2100][2100];
bool ck[2100][2100];

double go(int L,int R){

	
	if(R==y+1)return 1.0;
	if(L+R>=n)return 0.0;
	if(ck[L][R])return d[L][R];
	ck[L][R]=1;

	double r=0.0;

	if(L==h-1){
		r=go(L,R+1);
	}else if(R==h-1){
		r=go(L+1,R);
	}else{
		r=go(L+1,R)*0.5 + go(L,R+1)*0.5;
	}
	return d[L][R]=r;
}

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int Test;
	cin>>Test;
	for(int C=1;C<=Test;C++){
		cin>>n>>x>>y;
		x=ab(x);
		y=ab(y);

		double rst=0.0;
		if(x==0 && y==0){
			cout<<"Case #"<<C<<": ";
			printf("%.9lf",1.0);
			cout<<endl;
			continue;
		}

		lev=(x+y)/2;
		h=0;
		need=0;
		for(int i=0;i<=lev;i++){
			if(i==0)
				need=1ll,h=1ll;

			else {
				h+=2;
				need=h*2ll-1ll;

			}
			if(i==lev)break;
			n-=need;
			if(n<=0)break;
		}

		if(n<=0){
			cout<<"Case #"<<C<<": ";
			printf("%.9lf",0.0);
			cout<<endl;
			continue;
		}
		if(n>=need){
			cout<<"Case #"<<C<<": ";
			printf("%.9lf",1.0);
			cout<<endl;
			continue;
		}

		memset(ck,0,sizeof(ck));
		memset(d,0,sizeof(d));

		rst=go(0,0);

		cout<<"Case #"<<C<<": ";
		printf("%.9lf",rst);
		cout<<endl;
	}
}