#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	for (int j=1; j<=n; j++)
	{
		int row;
		cin >> row;
		
		int col;
		cin >> col;

		int lawn[row][col];

		for (int i=0; i<row; i++)
		{
			for (int e=0; e<col; e++)
			{
				int x;
				cin >> x;
				lawn[i][e] = x;
			}
		}

		bool fail = false;
		
		for (int i=0; i<row && !fail; i++)
		{
			for (int e=0; e<col && !fail; e++)
			{
				int x = lawn[i][e];		
				
				bool failOnce = false;
				
				for (int ii=0; ii<row && !failOnce; ii++)
				{
					if (lawn[ii][e] > x)
					{						
						failOnce = true;
					}
				}	

				for (int ee=0; ee<col && failOnce && !fail; ee++)
				{
					if (lawn[i][ee] > x)				
					{
						fail = true;
					}
				}				
			}
		}
		
		
		if (!fail)
		{
			cout << "Case #" << j << ": YES\n";
		}
		else
		{
			cout << "Case #" << j << ": NO\n";
		}
	}	
}

