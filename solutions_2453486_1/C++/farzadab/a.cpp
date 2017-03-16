#include<iostream>
using namespace std;

char ch[5][5];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++)
	{
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				cin >> ch[i][j];
		bool w[2] = { false , false };
		bool full = true;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				if( ch[i][j] == '.' )
					full = false;
		for(int i=0; i<4; i++)
		{
			bool f = true;
			for(int j=0; j<4; j++)
				if( ch[i][j] != 'X' && ch[i][j] != 'T' )
					f = false;
			if( f )
				w[0] = true;


			f = true;
			for(int j=0; j<4; j++)
				if( ch[j][i] != 'X' && ch[j][i] != 'T' )
					f = false;
			if( f ) 
				w[0] = true;


			f = true;
			for(int j=0; j<4; j++)
				if( ch[i][j] != 'O' && ch[i][j] != 'T' )
					f = false;
			if( f )
				w[1] = true;


			f = true;
			for(int j=0; j<4; j++)
				if( ch[j][i] != 'O' && ch[j][i] != 'T' )
					f = false;
			if( f ) 
				w[1] = true;
		}
		bool f1 = true,f2=true;
		for(int i=0; i<4; i++)
		{
			if( ch[i][i] != 'X' && ch[i][i] != 'T' )
				f1 = false;
			if( ch[i][3-i] != 'X' && ch[i][3-i] != 'T' )
				f2 = false;
		}
		if( f1 || f2 )
			w[0] = true;
		f1 = true;f2=true;
		for(int i=0; i<4; i++)
		{
			if( ch[i][i] != 'O' && ch[i][i] != 'T' )
				f1 = false;
			if( ch[i][3-i] != 'O' && ch[i][3-i] != 'T' )
				f2 = false;
		}
		if( f1 || f2 )
			w[1] = true;
		cout << "Case #" << tt+1 << ": ";
		if( w[0] == true )
			cout << "X won" << endl;
		else if ( w[1] == true )
			cout << "O won" << endl;
		else if( full )
			cout << "Draw" << endl;
		else
			cout << "Game has not completed" << endl;
	}
	return 0;
}
