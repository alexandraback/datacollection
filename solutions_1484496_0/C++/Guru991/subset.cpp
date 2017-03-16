#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

vector <int> find_s( int n )
{
	vector <int> sol(20,0);
	for( int i = 0; i < 20 ;i++)
	{
		if( n%2 == 1 )
			sol[i] = 1;
		n /= 2;
	}
	return sol;
}
		



int main()
{
	int t;
	cin>>t;
	int ptr = 1;
	vector <int> nos(20);

	while( t-- )
	{
		map <int,int> tally;
		map <int,int> se;
		int dummu;
		cin>> dummu;
		for( int i = 0; i < 20;i++)
			cin>>nos[i];
		int mask = 0;
		vector <int> sol1, sol2;
		int ans = 0;
		while ( mask < 1048576 )
		{
			vector <int> sset = find_s( mask );
			int ssum = 0;
			for( int i = 0;i < 20;i++)
			{
				if( sset[i] == 1 )
					ssum += nos[i];
			}
			if( tally.find(ssum) != tally.end() )
			{
				sol1 = sset;
				sol2 = find_s( se[ssum] );
				ans = 1;
				break;
			}
			else
			{
				tally[ssum] = 1;
				se[ssum] = mask;
			}
			mask++;
		}
		cout<<"Case #"<<ptr<<":"<<endl;
		ptr++;
		if( ans == 1 )
		{	
			for( int i = 0; i < 20 ; i++)
				if( sol1[i] == 1 )
					cout << nos[i]<<" ";
			cout<<endl;
			for( int i = 0; i < 20 ; i++)
				if( sol2[i] == 1 )
					cout << nos[i]<<" ";
			cout<<endl;
		}
		else
			cout<<"Impossible"<<endl;
	}
	return 0;


					 

	


}
