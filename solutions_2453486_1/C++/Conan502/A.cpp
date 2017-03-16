#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rp(i,l,r) for ( int i=(int)(l); i<=(int)(r); ++i )
#define dp(i,l,r) for ( int i=(int)(l); i>=(int)(r); --i )

typedef long long LL;

int Case;
int tot;
bool Owin,Xwin;
char c[5][5];

bool C_row( int x , char key )
{
	rp( i,1,4 ) if ( c[x][i]!=key && c[x][i]!='T' ) return false;
	return true;
}

bool C_col( int x , char key )
{
	rp( i,1,4 ) if ( c[i][x]!=key && c[i][x]!='T' ) return false;
	return true;
}

bool C_rig( char key )
{
	rp( i,1,4 ) if ( c[i][i]!=key && c[i][i]!='T' ) return false;
	return true;
}

bool C_lef( char key )
{
	rp( i,1,4 ) if ( c[i][4-i+1]!=key && c[i][4-i+1]!='T' ) return false;
	return true;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin >> Case ;
	rp( _Case,1,Case )
	{
		Owin=false;
		Xwin=false;
		tot=0;
		rp( i,1,4 ) rp( j,1,4 ) cin >> c[i][j];
		rp( i,1,4 ) rp( j,1,4 ) tot+=c[i][j]=='.';
		rp( i,1,4 )
		{
			if ( C_row(i,'X') ) Xwin=true;
			if ( C_row(i,'O') ) Owin=true;
			if ( C_col(i,'X') ) Xwin=true;
			if ( C_col(i,'O') ) Owin=true;
		}
		if ( C_rig('X') ) Xwin=true;
		if ( C_rig('O') ) Owin=true;
		if ( C_lef('X') ) Xwin=true;
		if ( C_lef('O') ) Owin=true;
		cout << "Case #" << _Case << ": " ;
		if ( Xwin ) cout << "X won" << endl; else
		if ( Owin ) cout << "O won" << endl; else 
		if ( !tot ) cout << "Draw"  << endl; else
		cout << "Game has not completed" << endl;
	}
}
