#include<iostream>
#include<cstring>
using namespace std;

int list[52];
int r,c,m;

const int d[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

bool check()
{
	int map[52][52];
	memset( map , 0 , sizeof( map ) );
	for ( int i=0; i<r; i++)
	{
		for ( int j=0; j<list[i]; j++)
			map[i][j] = -1;
	}
	for (int i=0; i<r; i++)
		for ( int j=list[i]; j<c; j++)
			for (int k=0; k<8; k++)
			{
				int p = i+d[k][0];
				int q = j+d[k][1];
				if ( p>=0 && q>=0 && p<r && q<c && map[p][q]==-1 )
				{
					map[i][j]=1;
					break;
				}
			}


	if ( m < r*c -1 )
	{
		for (int i=0; i<r; i++)
			for ( int j=list[i]; j<c; j++)
				if ( map[i][j] == 1 )
				{
					bool flag = false;
					for (int k=0; k<8; k++)
					{
						int p = i+d[k][0];
						int q = j+d[k][1];
						if ( p>=0 && q>=0 && p<r && q<c && map[p][q]==0 )
							flag = true;
					}
					if (!flag)
						return false;
				}
	}

	bool flag = false;
	for (int i=0; i<r; i++)
	{
		for (int j=0; j<c; j++)
			if ( map[i][j]==-1 )
				cout<<'*';
			else if ( map[i][j]==1 )
				if ( m< r*c -1 )
					cout<<'.';
				else
					cout<<'c';
			else if ( !flag )
			{
				flag = true;
				cout<<'c';
			}
			else
				cout<<'.';
		cout<<endl;
	}
	return true;
}


bool search( int r0 , int upb , int m )
{
	if ( m<0 )
		return false;
	if ( r0>=r && m==0 )
		return check();
	if ( upb * ( r-r0 ) < m ) return false;
	for ( int i=upb; i>=0; i--)
	{
		list[ r0 ] = i;
		if ( search( r0+1 , i , m-i ) )
			return true;
	}

	return false;
}

void work( int n )
{
	cin>>r>>c>>m;
	memset( list , 0 , sizeof( list ) );
	cout<<"Case #"<<n<<":\n";
	if ( ! search( 0 , c , m ) )
		cout<<"Impossible\n";
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		work( i );
}

