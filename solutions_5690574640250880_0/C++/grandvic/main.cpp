#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
 
using namespace std;

void draw_hor(int R, int C, int r, int c, int rem)
{
	vector<string> a(1);
	for(int i=0; i<C; ++i)a[0].push_back('*');
	for(int i=1; i<R; ++i)a.push_back(a[0]);

	for(int y=0; y<r; ++y)
		for(int x=0; x<c; ++x)
			a[y][x] = '.';
	for(int i=0; i<rem; ++i)
		a[r][i] = '.';
	a[0][0] = 'c';

	if(rem==1)
	{
		a[r-1][c-1] = '*';
		a[r][1] = '.';
	}

	for(int i=0; i<R; ++i)
		cout<<a[i]<<endl;
}

void draw_vert(int R, int C, int r, int c, int rem)
{
	vector<string> a(1);
	for(int i=0; i<C; ++i)a[0].push_back('*');
	for(int i=1; i<R; ++i)a.push_back(a[0]);

	for(int y=0; y<r; ++y)
		for(int x=0; x<c; ++x)
			a[y][x] = '.';
	for(int i=0; i<rem; ++i)
		a[i][c] = '.';
	a[0][0] = 'c';

	if(rem==1)
	{
		a[r-1][c-1] = '*';
		a[1][c] = '.';
	}

	for(int i=0; i<R; ++i)
		cout<<a[i]<<endl;
}

void solve()
{
	int R, C, M; cin>>R>>C>>M;
	int E = R*C-M;

	if(E==1)
	{
		draw_vert(R, C, 1, 1, 0);
		return;
	}
	else if(R==1)
	{
		draw_vert(R, C, 1, E, 0);
		return;
	}
	else if(C==1)
	{
		draw_hor(R, C, E, 1, 0);
		return;
	}

	int rr=-1, cc=-1, rem=-1;
	for(int r=2; r<=R; ++r)
	{
		int c = E/r;
		rem = E%r;

		if(rem==1 && (c<3 || r<3)){continue;}
		if((c+(bool)rem)>C){continue;}
		if(c<2){continue;}
		rr=r; cc=c; break;
	}
	if(rr!=-1)
	{
		draw_vert(R, C, rr, cc, rem);
		return;
	}


	for(int c=2; c<=C; ++c)
	{
		int r = E/c;
		rem = E%c;

		if(rem==1 && (r<3 || c<3)){continue;}
		if(r>R){continue;}
		if((r+(bool)rem)>R){continue;}
		if(r<2){continue;}
		rr=r; cc=c; break;
	}
	if(rr!=-1)
	{
		draw_hor(R, C, rr, cc, rem);
		return;
	}

	cout<<"Impossible"<<endl;
	//cout<<R<<" "<<C<<" "<<M<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": "<<endl;
		solve();
	}
 
	return 0;
} 