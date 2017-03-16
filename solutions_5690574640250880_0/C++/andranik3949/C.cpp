#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("C-small-attempt0.in");
ofstream cout("C-small-attempt0.out");

void horizontal( int height, int width, int free, vector < vector < char> >& field )
{
	int count = 0;
	for( int i = 0; i < width; ++i )
	{
		for( int j = 0; j < height; ++j )
		{
			if( i < 1 )
			{
				if( count < free )
				{
					field[j][i] = '.';
					count++;
					if( count < free )
					{
						field[j][i + 1] = '.';
						count++;
					}
					else
					{
						field[j-1][i] = '*';
						field[j-1][i+1] = '*';
						field[j][i] = '*';
						field[0][i+2] = '.';
						field[1][i+2] = '.';
						field[2][i+2] = '.';
						return;
					}
				}
				else
					return;
				if( j == height - 1 )
					i = 1;
			}
			else
			{
				if( count < free )
				{
					field[j][i] = '.';
					count++;
				}
				else
				{
					if( j == 1 )
					{
						if( i == 2 )
						{
							field[height - 1][0] = '*';
							field[height - 1][1] = '*';
							field[j][i] = '.';
							field[j+1][i] = '.';
							return;
						}
						else
						{
							field[height - 1][i-1] = '*';
							field[j][i] = '.';
							return;
						}
					}
					else
						return;
				}
			}
		}
	}
}

void vertical( int height, int width, int free, vector < vector < char> >& field )
{
	int count = 0;
	for( int j = 0; j < height; j++ )
	{
		for( int i = 0; i < width; i++ )
		{
			if( j < 1 )
			{
				if( count < free )
				{
					field[j][i] = '.';
					count++;
					if( count < free )
					{
						field[j+1][i] = '.';
						count++;
					}
					else
					{
						field[j][i-1] = '*';
						field[j][i] = '*';
						field[j+1][i-1] = '*';
						field[2][0] = '.';
						field[2][1] = '.';
						field[2][2] = '.';
						return;
					}
				}
				else
					return;
				if( i == width - 1 )
					j = 1;
			}
			else
			{
				if( count < free )
				{
					field[j][i] = '.';
					count++;
				}
				else
				{
					if( i == 1 )
					{
						if( j == 2 )
						{
							field[0][width - 1] = '*';
							field[1][width - 1] = '*';
							field[j][i] = '.';
							field[j][i+1] = '.';
							return;
						}
						else
						{
							field[j-1][width - 1] = '*';
							field[j][i] = '.';
							return;
						}
					}
					else
						return;
				}
			}
		}
	} 
}

int main()
{
	int num;
	cin >> num;
	for ( int i = 0; i < num; i++ )
	{
		cout << "Case #" << i + 1 << ':' << endl; 
		int height, width, mines;
		cin >> height >> width >> mines;
		int free = height * width - mines;
		if ( width == 1 || height == 1 )
		{
			for ( int j = 0, count = 0; j < height; j++ )
			{
				for ( int k = 0; k < width; k++ )
				{
					if ( count == 0 )
					{
						cout << 'c';
						count++;
						continue;
					}
					if( count < free )
						cout << '.';
					else
						cout << '*';
					count++;
				}
				cout << endl;
			}
			continue;
		}
		if ( free == 1 )
		{
			cout << 'c';
			for ( int j = 0; j < height; j++ )
			{
				for ( int k = 0; k < width; k++ )
				{
					if ( j == 0 && k == 0 )
						continue;
					cout << '*';
				}
				cout << endl;
			}
			continue;
		}
		if ( free == 2 || free == 3 || free == 5 || free == 7 )
		{
			cout << "Impossible" << endl;
			continue;
		}
		if ( ( height == 2 || width == 2 ) && free % 2 == 1 )
		{
			cout << "Impossible" << endl;
			continue;
		}
		vector < vector < char> > field( height, vector < char > ( width, '*') );
		if ( height < width )
			horizontal( height, width, free, field );
		else
			vertical( height, width, free, field );
		for ( int j = 0; j < height; j++ )
		{
			for ( int k = 0; k < width; k++ )
				if( j == 0 && k == 0 )
					cout << 'c';
				else
					cout << field[j][k];
			cout << endl;
		}
	}
	return 0;
}