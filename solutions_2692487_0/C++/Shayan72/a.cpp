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
	int T,A,N;
	int o = 1;
	
	cin >> T;
	
	while( T-- )
	{
		cin >> A >> N;
		vector <int> motes;
		int temp;
		
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			motes.PB(temp);
		}
		
		sort( motes.begin(), motes.end() );
		int count = 0;
		int keep = -1;
		for (int i = 0; i < N; i++)
		{
			if( A > 100 )
				break;
				
			if( keep != -1 && A > motes[keep] )
			{
				for (int j = keep; j < i; j++)
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
					for (int j = keep; j < i; j++)
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
