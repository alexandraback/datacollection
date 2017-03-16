#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("Text.txt","a",stdout);
	int tc;
	cin >> tc;
	for ( int i = 1 ; i <= tc ; i++ )
	{
		char ar[4][4];
		bool po = false;
		for ( int p = 0 ; p < 4 ; p++ )
			for ( int o = 0 ; o < 4 ; o++ )
			{
				cin >> ar[p][o];
				if ( ar[p][o] == '.' )
					po = true;
			}
		cin.ignore();
		string h;
		getline(cin,h);
		cout<<"Case #"<<i<<": ";
		bool bx = false;
		bool bo = false;
		for ( int p = 0 ; p < 4 ; p++ )
		{
			int sumx = 0;
			int sumo = 0;
			for ( int o = 0 ; o < 4 ; o++ )
			{
				if ( ar[p][o] == 'X' || ar[p][o] == 'T' )
				{
					sumx++;
				}
				if ( ar[p][o] == 'O' || ar[p][o] == 'T' )
				{
					sumo++;
				}
			}
			if ( sumx == 4 )
			{
				bx = true;
			}
			if ( sumo == 4 )
			{
				bo = true;
			}
		}
		if ( bx )
		{
			cout<<"X won"<<endl;
			continue;
		}
		if ( bo )
		{
			cout<<"O won"<<endl;
			continue;
		}

		for ( int p = 0 ; p < 4 ; p++ )
		{
			int sumx = 0;
			int sumo = 0;
			for ( int o = 0 ; o < 4 ; o++ )
			{
				if ( ar[o][p] == 'X' || ar[o][p] == 'T' )
				{
					sumx++;
				}
				if ( ar[o][p] == 'O' || ar[o][p] == 'T' )
				{
					sumo++;
				}
			}
			if ( sumx == 4 )
			{
				bx = true;
			}
			if ( sumo == 4 )
			{
				bo = true;
			}
		}
		if ( bx )
		{
			cout<<"X won"<<endl;
			continue;
		}
		if ( bo )
		{
			cout<<"O won"<<endl;
			continue;
		}
		int cox=0;
		int coo=0;
		for ( int p = 0 ; p < 4 ; p++ )
		{
			if ( ar[p][p] == 'X' || ar[p][p] == 'T' )
				cox++;
			if ( ar[p][p] == 'O' || ar[p][p] == 'T' )
				coo++;
		}
		if ( cox == 4 )
		{
			cout<<"X won"<<endl;
			continue;
		}
		if ( coo == 4 )
		{
			cout<<"O won"<<endl;
			continue;
		}
		int e=0;
		int wx=0;
		for ( int p = 3 ; p >=0 ; p-- )
		{
			if ( ar[e][p] == 'X' || ar[e][p] == 'T' )
			{
				wx++;
			}
			e++;
		}
		if ( wx == 4 )
		{
			cout<<"X won"<<endl;
			continue;
		}
		int r=0;
		int wo=0;
		for ( int p = 3 ; p >=0 ; p-- )
		{
			if ( ar[r][p] == 'O' || ar[r][p] == 'T' )
			{
				wo++;
			}
			r++;
		}
		if ( wo == 4 )
		{
			cout<<"O won"<<endl;
			continue;
		}
		if ( po ) 
		{
			cout<<"Game has not completed"<<endl;
		}
		else
		{
			cout<<"Draw"<<endl;
		}
				
	}
	return 0;
}