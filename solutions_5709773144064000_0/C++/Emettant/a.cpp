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
		
		double C,F,X;
		cin>>C>>F>>X;
		double g = 2, ng = -1, time = 0;
		while(1){
			ng = g + F;
			double ntime1 = X / ng + C / g;
			double ntime2 = X / g;
			
			if (ntime2 < ntime1) {
				time += ntime2;
				break;
			}
			else time += C / g;
			
			g = ng;
		}
		
		
		printf("Case #%d: ",_T-_t);
		printf("%0.9lf\n",time);
		//answer here
		
		
	}
	return 0;
}


int main() {

//	freopen("input.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
	
	GoogleSolve();
return 0;
}