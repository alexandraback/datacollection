#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main()
{
	int T;
	cin >> T;
	
	for( int o = 1; o <= T; o++ )
	{
		ll x,y;
		
		cin >> x >> y;
		
		ll xp = x>0?x:x*-1;
		ll yp = y>0?y:y*-1;
		
		ll xpy = xp+yp;
		
		ll sum = 0;
		ll men = -1;
		ll i;
		for ( i = 1;; i++)
		{
			sum += i;
			
			if( sum == xpy )
			{
				break;
			}
			
			if( sum > xpy && !(sum-xpy&1) )
			{
				men = (sum-xpy)/2;
				break;
			}
		}

		vector<ll> greedySeries;
		int find = 0;
		ll start = i;
		
		if( xp <= start )
		{
			start = xp;
		}
		
		int kk = xp;
		
		for (ll j = start; j >= 1; j--)
		{
			if( j != men && j <= kk )
			{
				greedySeries.PB( j );
				kk -= j;
			}
			
			if( kk == 0 )
				break;
		}
		if( kk == 0 )
		{
			find = 1;
		}
		
		if( find == 0 )
		{
			greedySeries.clear();

			start = i;
			
			if( yp <= start )
			{
				start = yp;
			}
			
			int kk = yp;
			
			for ( ll j = start; j >= 1; j--)
			{
				if( j != men && j <= kk )
				{
					greedySeries.PB( j );
					kk -= j;
				}
				
				if( kk == 0 )
					break;
			}
			if( kk == 0 )
			{
				find = 2;
			}
		}

		sort( greedySeries.begin(), greedySeries.end() );

		// cout << i << endl;
		// cout << find << endl;
		// //
		// cout << "----------" << endl;
		// for (int h = 0; h < greedySeries.size(); h++)
		// {
			// cout << greedySeries[h] << endl;
		// }
		// cout << "----------" << endl;
		// cout << men << endl;

		cout << "Case #" << o << ": ";
		
		int counter = 0;
		for (int j = 1; j <= i; j++)
		{
			if( counter >= greedySeries.size() || greedySeries[counter] != j )
			{
				if( j != men )
				{
					if(find==1)
					{
						y>=0?cout<< "N":cout << "S";
						// cout<< "N";
					}
					else if( find == 2 )
					{
						x>=0?cout << "E": cout << "W";
						// cout<< "E";
					}
				}
				else
				{
					if(find==1)
					{
						y>=0?cout<< "S":cout << "N";
					}
					else if( find == 2 )
					{
						x>=0?cout << "W": cout << "E";
					}
				}
			}
			else // vaghti greedy Ast
			{
				if( find==1 )
				{
					x>0?cout << "E": cout << "W";
				}
				else if( find == 2 )
				{
					y>0?cout<< "N":cout << "S";
				}
				counter++;
			}
		}
				
		cout << endl;
	}
	
	
	return 0;
}
