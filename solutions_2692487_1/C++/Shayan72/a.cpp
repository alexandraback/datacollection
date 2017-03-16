#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main()
{
	ll T,A,N;
	ll o = 1;
	
	cin >> T;
	
	while( T-- )
	{
		cin >> A >> N;
		vector <ll> motes;
		ll temp;
		
		for (ll i = 0; i < N; i++)
		{
			cin >> temp;
			motes.PB(temp);
		}
		
		sort( motes.begin(), motes.end() );
		ll count = 0;
		ll keep = -1;
		for (ll i = 0; i < N; i++)
		{
			if( A > 1000000 || A > motes.back()  )
				break;
				
			if( keep != -1 && A > motes[keep] )
			{
				for (ll j = keep; j < i; j++)
				{
					if( A > motes[j] )
					{
						A += motes[j];
						if( j != i-1 )
							keep++;
						else
							keep = -1;
					}
				}
				
			}
				
			if( A > motes[i] )
			{
				keep = -1;
				A += motes[i];
			}
			else if( motes[i] >= A+A-1 )
			{
				count++;
				A+=A-1;
				if( keep == -1 )
					keep = i;
			}
			else
			{
				A+=A-1;
	
				if( keep != -1 && A > motes[keep] )
				{
					for (ll j = keep; j < i; j++)
					{
						if( A > motes[j] )
						{
							A += motes[j];
							if( j != i-1 )
								keep++;
							else
								keep = -1;
						}
					}
					
				}

				A+=motes[i];
				keep = -1;
				count++;
			}
		}
		
		cout << "Case #" << o << ": " << count << endl;
		o++;
	}
	
	return 0;
}
