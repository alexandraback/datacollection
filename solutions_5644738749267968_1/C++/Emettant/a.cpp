#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <tuple>
#include <cassert>
#include <cstring>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rp(i,s,n) for((i)=(s);(i)<(n);(i)++)	
#define fore(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)
#define repe(it,a) for(auto (it) = (a).begin();(it)!=(a).end();++(it))

#define ll long long
#define MP make_pair 
#define MT make_tuple
#define PB push_back
#define X first
#define Y second
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) (a).size()
#define LEN(s) (s).length() 
#define uset unordered_set
#define umap unordered_map
#define IT iterator

#pragma comment(linker,"/STACK:100000000")

using namespace std;			

#define NUMBERS(a,b) { int _i_; vector<int> _A_(((b))-(a)); rep(_i_,_A_.size()) _A_[_i_] =_i_+(a); out(_A_);}

template <class T> void out(map<char,T> & a,string s="(%3c ->%3d)"){repe(it,a) printf(s.c_str(),it->X,it->Y);printf("\n");}

template <class T>void out(vector<T> & a,string s="%3d "){int i,n=a.size();rep(i,n) printf(s.c_str(),a[i]);printf("\n");}

template <class T>void out(T * a,int n,string s="%3d "){int i;rep(i,n) printf(s.c_str(),a[i]);printf("\n");} 


ll i,j,N,M,n,m,k,p;


int GoogleSolve(){
	int _T,_t;
	cin>>_t;
	_T = _t;
	while(_t--){
		
		cin>>n;
		double z;
		vector<pair<double, int> > a(2*n);
		rep(i,n) cin>>z, a[i] = MP(z,0);
		rep(i,n) cin>>z, a[n+i] = MP(z,1);
		sort(ALL(a));
		
		//rep(i,2*n) cout<<a[i].Y<<" ";cout<<endl;
		
		i =0; j = 0;
		int h = 0;
		while(1){
			while(i<2*n && a[i].Y != 0) i++;
			j = max(i+1,j);
			while(j<2*n && a[j].Y != 1) j++;
			if (j>=2*n) break;
			i++, j++, h++;
		}
		int f = n - h;
		//cout<<h<<endl;
		//while(i<2*n) if (a[i++].Y == 0) f++;

		i =0; j = 0;
		h = 0;
		while(1){
			while(i<2*n && a[i].Y != 1) i++;
			j = max(i+1,j);
			while(j<2*n && a[j].Y != 0) j++;
			if (j>=2*n) break;
			i++, j++, h++;
		}
		int f2 = h;
		printf("Case #%d: ",_T-_t);
		
		//answer here
		cout<<f2<<" "<<f<<endl;
		
	}
	return 0;
}


int main() {

	freopen("input.txt","r",stdin);
	// freopen("D-small-attempt0.in","r",stdin);freopen("output-small-attempt.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
	 freopen("D-large.in","r",stdin);freopen("output-large.txt","w",stdout);
	GoogleSolve();
return 0;
}