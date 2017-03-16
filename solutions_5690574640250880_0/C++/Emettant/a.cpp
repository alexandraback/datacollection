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



void change(string&a, int u, int w,int n, int m, vector<pair<int, int> >& ret){
	if (-1<u && u<n && -1<w && w<m) if (a[u*m + w] == '*') {
		a[u*m + w] = '.';
		ret.push_back(MP(u, w));
	}
}

void brush(string &a, int t1, int t2, int n, int m, vector<pair<int, int> > & br){
	int i = -1, j = -1;
	rp(i, t1 - 1, t1 + 2) rp(j, t2 - 1, t2 + 2) change(a, i, j, n, m, br);
}

void copy(vector<vector<char> >&a, vector<vector<char> >&b){
	int i, j;
	int n = a.size();
	int m = a[0].size();
	b.resize(n, vector<char>(m));
	rep(i, n) rep(j, m) b[i][j] = a[i][j];
}
ll i, j, N, M, n, m, k, p;

int GoogleSolve(){
	int _T,_t;
	cin>>_t;
	_T = _t;
	while(_t--)
	{
		
		ll n, m, mines;
		cin >> n >> m >> mines;


		string d(n*m, '*');
		d[0] = '.';
		
		vector<pair<int, int> > temp;
		
		string v = d;
		queue<string> q;
		int ok = 0;
		if (n*m - mines == 1) ok = 1;
		else{
			brush(d, 0, 0, n, m, temp);

			q.push(d);
			uset<string> used;
			used.insert(d);
			
			while (q.size()){
				v = q.front();

				ll k = 0;
				rep(i, n*m) if (v[i] == '.') k++;
				if (k == n*m - mines) {
					ok = 1; break;
				}

				rep(i, n) rep(j, m) if (v[i*m + j] == '.') {
					vector<pair<int, int> > temp;
					brush(v, i, j, n, m, temp);
					if (temp.size() && used.count(v) == 0){
						string buf = v;
						used.insert(buf);
						q.push(buf);
						/*rep(i, 5) {
							rep(j, 5) cout << d[i*m + j];
							cout << endl;
							}
							cout << endl;*/
					}
					for (auto el : temp) v[el.X*m + el.Y] = '*';
				}
				q.pop();
			}

		}

		
		printf("Case #%d: \n",_T-_t);
		
		//answer here
		if (ok) {

			v[0] = 'c';

			rep(i, n){
				rep(j, m) printf("%c",v[i*m + j]);
				printf("\n");
			}
		}
		else {
			printf("Impossible\n");
		}
		
	}
	return 0;
}


int main() {

	//freopen("C:\\Olimp2014\\JAM14_C\\input.txt","r",stdin);
	freopen("C-small-attempt4.in","r",stdin);freopen("output-small-attempt.txt","w",stdout);//FILE * f, *g; f = fopen ("input.txt","r");//g = fopen ("output.txt","w");
	// freopen("B-large.in","r",stdin);freopen("output-large.txt","w",stdout);
	GoogleSolve();
return 0;
}