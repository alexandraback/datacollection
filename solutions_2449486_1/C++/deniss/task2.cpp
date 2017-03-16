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

string check_board(int* board, int N, int M) {
	string ret;
	bool err = false;
	forn(i, N) {
		forn(k, M) {
			// check if they are lower or higher values on both horizontal and vertical
			bool is_hor = true;
			bool is_vert = true;
			forn (l, M) {
				if (k != l && board[i*M+k] < board[i*M+l]) {
					is_hor = false;
				}
			}
			forn (l, N) {
				if (i != l && board[i*M+k] < board[l*M+k]) {
					is_vert = false;
				}
			}
			if (!is_vert && !is_hor) {
				err = true;
				break;
			}
		}
		if (err) break;
	}

	if (err) {
		ret = "NO";
	} else {
		ret = "YES";
	}

	return ret;
}

int main(){
	freopen("c:\\jam\\2013\\b.in","r",stdin);
	freopen("c:\\jam\\2013\\b.out","w",stdout);

	int tc;
	cin>>tc;
	
	string res;
	forn(q,tc){
		int N, M;
		int board[10001];
		cin >> N;
		cin >> M;

		forn(i, N) {
			forn(k, M) {
				cin >> board[i*M+k];
			}
		}

		string out = check_board(board, N, M);
		cout <<"Case #"<<q+1<<": "<<out<<endl;		
	}

	return 0;
}
