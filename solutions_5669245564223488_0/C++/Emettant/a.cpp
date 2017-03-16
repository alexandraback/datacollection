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
		
		int const N = 105;
		int const ALF = 257;
		string a[N], z;
		cin>>n;
		rep(i,n) 
			cin>>a[i];
		
		
		int lused[ALF];
		int rused[ALF];
		int used[ALF];
		int whole[ALF];
		rep(i,ALF) lused[i] = rused[i] = whole[i] = used[i] = 0;
		int bad = 0;
		ll all = 0;
		
		rep(i,n){
				
			int is_whole = 1;
			rep(j,a[i].length()) if (a[i][j] != a[i][0]) {is_whole = 0; break;}
			
			if (is_whole) whole[ a[i][0] ]++;
			else{
				
				char cur = '#';
				int locu[ALF]; 
				rep(j,ALF) locu[j] = used[j];
				rep(j,a[i].length()) if (cur != a[i][j]) {
					cur = a[i][j];
				
					if (locu[cur]) bad = 1;
					else used[cur] = locu[cur] = 1;
					
					if (bad) break;
				}
				if (bad) break;
				
				used[a[i][0]] = 0;
				if (lused[a[i][0]]) bad = 1;
				else lused[a[i][0]] = 1;
				
				used[a[i][ a[i].length()-1 ]] = 0;
				if (rused[a[i][ a[i].length()-1 ]]) bad = 1;
				else rused[a[i][ a[i].length()-1 ]] = 1;
				
				if (bad) break;
				//if (rused[a[i][0]] == 0 && lused[a[i][a[i].length() - 1]] == 0) all++;
				
			}
			
		}

		ll res = 1;
		
		if (!bad){



			char u = 'a';
			p = 0;
			rp(u, 'a', 'z' + 1){
				if (rused[u] ^ lused[u]) p++;
				//cout <<(char)u <<rused[u] << " " << lused[u] << endl;
			}
			if (p & 1) bad = 1;

			all = p >> 1;

			ll fac[N];
			int const MOD = 1e9 + 7;
			fac[0] = 1;
			rp(i, 1, N) fac[i] = i * fac[i - 1] % MOD;


			u;
			rp(u, 'a', 'z' + 1){
				res *= fac[whole[u]];
				res %= MOD;
				if (rused[u] == 0 && lused[u] == 0 && whole[u])
					all++;
			}



			res *= fac[all];
			res %= MOD;

		}
		printf("Case #%d: ",_T-_t);
		cerr<<"Log: Test number "<<_T-_t<<endl;
		//answer here
		if (bad) cout<<0<<endl;
		else cout<<res<<endl;
		
		
	}
	return 0;
}


int main() {

	//freopen("C:\\Olimp2014\\JAM14_1C_B\\input.txt","r",stdin);
	//freopen("C:\\Olimp2014\\JAM1_14_B\\input.txt","r",stdin);
	 freopen("B-small-attempt1.in","r",stdin);freopen("output-small-attempt.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
	// freopen("B-large.in","r",stdin);freopen("output-large.txt","w",stdout);
	//freopen("B-small-practice.in","r",stdin);freopen("output-small-practice.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
	//freopen("B-large-practice.in","r",stdin);freopen("output-large-practice.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
	GoogleSolve();
return 0;
}