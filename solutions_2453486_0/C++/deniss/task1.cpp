#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <ctime>
using namespace std;

#define pii pair<int,int>
#define MPII make_pair<int,int>
#define PLL pair<lng,lng>
#define MPLL make_pair<lng,lng>
#define PI 3.1415926535897932384626433832795
#define DEG2RAD (PI/180.0)
#define RAD2DEG (1.0/DEG2RAD)
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define forn1(i,n) for(int i=0;i<n+1;++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define forvr(i,v) for(int i=v.size()-1;i>=0;--i)
#define fors(i,s) for(int i=0;i<s.length();++i)
#define EPS 1e-12
#define eps EPS
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)
#define maxll ((1LL<<62)-1+(1LL<<62))
#define SQ(a) ((a)*(a))
#define SWAP(t,a,b) {t ____tmpasdasdasd=(a);(a)=(b);(b)=____tmpasdasdasd;}
#define abs(a) ((a)<0?-(a):(a))
#define ALL(a) (a).begin(),(a).end()

long long n;
long long pd;
long long pg;

string check_board(char* a) {
	string ret;
	bool f = false;
	bool s = false;

	bool f_d1 = true;
	bool f_d2 = true;
	bool s_d1 = true;
	bool s_d2 = true;

	forn(i, 4) { 
		bool f_h = true;
		bool s_h = true;
		bool f_v = true;
		bool s_v = true;


		forn(k, 4) { 
			if (a[i*4+k] != 'X' && a[i*4+k] != 'T')  {
				f_h = false;				
			}
			if (a[i*4+k] != 'O' && a[i*4+k] != 'T')  {
				s_h = false;				
			}
			if (a[k*4+i] != 'X' && a[k*4+i] != 'T')  {
				f_v = false;
			}
			if (a[k*4+i] != 'O' && a[k*4+i] != 'T')  {
				s_v = false;
			}			
		}

		if (a[i*4+i] != 'X' && a[i*4+i] != 'T')  {
			f_d1 = false;
		}

		if (a[i*4+i] != 'O' && a[i*4+i] != 'T')  {
			s_d1 = false;
		}

		if (a[i*4+3-i] != 'X' && a[i*4+3-i] != 'T')  {
			f_d2 = false;
		}

		if (a[i*4+3-i] != 'O' && a[i*4+3-i] != 'T')  {
			s_d2 = false;
		}

		if (!f) {
			f = f_h || f_v;
		}
		if (!s) {
			s = s_h || s_v;
		}
	}

	if (!f) {
		f = f_d1 || f_d2;
	}
	if (!s) {
		s = s_d1 || s_d2;
	}
	
	if (f && s) {
		ret = "Draw";
	}
	if (f) {
		ret = "X won";
	}
	if (s) {
		ret = "O won";
	}
	if (!f && !s) {
		bool is_draw = true;
		forn(i,16) {
			if (a[i] == '.') {
				is_draw = false;
				break;
			}
		}
		if (is_draw) {
			ret = "Draw";
		} else {
			ret = "Game has not completed";
		}
	}
	return ret;
}

int main(){
	freopen("c:\\jam\\2013\\a.in","r",stdin);
	freopen("c:\\jam\\2013\\a.out","w",stdout);

	int tc;
	cin>>tc;
	
	string res;
	
	forn(q,tc){
		std::getline(std::cin, res);
		char board[16];
		forn(k, 4) {
			std::getline(std::cin, res);
			forn (i, 4) board[k*4 + i] = res[i];
		}

		string out = check_board(board);
		cout <<"Case #"<<q+1<<": "<<out<<endl;		
	}

	return 0;
}
