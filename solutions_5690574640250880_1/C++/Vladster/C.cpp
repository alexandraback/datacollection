#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "input.txt"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

void zzz(vector<vector<char> > &data, int r, int c) {
    rp(i, r) {
        rp(j, c) {
            data[i][j] = '.';
        }
    }
    data[0][0] = 'c';
}
void show(vector<vector<char> > &data) {
    rp(i, data.size()) {
        rp(j, data[i].size()) {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
}

void solve(int r, int c, int m) {
    int d = r*c-m;
    vector<vector<char> > data(r, vector<char>(c , '*'));
    if (d==0) { show(data); return; }
    if (d==1) { data[0][0]='c'; show(data); return; }
    if (r==1) { zzz(data, r, d); show(data); return; }
    if (c==1) { zzz(data, d, c); show(data); return; }
    for(int col = 2; col <= c; ++col) {
        int row = d / col;
        int ost = d % col;
        if (ost == 0 && 2 <= row && row <= r) { 
            zzz(data, row, col); show(data); return;
        }
        if (ost >= 2 && 2 <= row && row+1 <= r) { 
            zzz(data, row, col);zzz(data, row+1, ost); show(data); return;
        }
        //ost --- 1
        if (2 < col && 2 < row && row+1 <= r) { 
            zzz(data, row-1, col);
            zzz(data, row, col-1);
            zzz(data, row+1, ost+1); show(data); return;
        }
    }
    for(int row = 2; row <= r; ++row) {
        int col = d / row;
        int ost = d % row;
        if (ost == 0 && 2 <= col && col <= c) { 
            zzz(data, row, col); show(data); return;
        }
        if (ost >= 2 && 2 <= col && col+1 <= c) { 
            zzz(data, row, col);zzz(data, ost, col+1); show(data); return;
        }
        if (2 < col && 2 < row && col+1 <= c) { 
            zzz(data, row-1, col);
            zzz(data, row, col-1);
            zzz(data, ost+1, col+1); show(data); return;
        }
    }
    /*if (d!=2 && d!=3 && d!=5 && d!=7 && r!=2 && c!=2) {
        printf("%d %d %d\n",r,c,m);
    }*/
    printf("Impossible\n");
}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

    //for(int r = 1; r < 20; ++r) {
    //    for(int c = 1; c< 20; ++c ) {
    //        for(int  m=0; m<=r*c; ++m) {
    //            solve(r,c,m);
    //        }
    //    }
    //}

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int r,c,m; cin>>r>>c>>m;
		printf("Case #%d:\n",tst);
        solve(r,c,m);
	}
	
	return 0;
}