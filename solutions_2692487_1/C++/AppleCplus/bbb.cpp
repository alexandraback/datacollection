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




ll a[105];
ll n;
ll s;

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int Test;
	cin>>Test;
	for(int C=1;C<=Test;C++){


		cin>>s>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		ll p;

		ll rst=Max;
		for(p=0;p<n;p++){
			if(s>a[p])s+=a[p];
			else break;
		}
		rst=n-p;

		ll now=0;
		for(int k=1;k<=1000;k++){
			now++;
			s=s+s-1;
			for(;p<n;p++){
				if(s>a[p])s+=a[p];
				else break;
			}
			rst=min(rst,now+n-p);
			if(p==n)break;
		}

		cout<<"Case #"<<C<<": "<<rst<<endl;
	}
}