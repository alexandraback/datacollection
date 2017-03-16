#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	int tc;
	cin >> tc;
	for(int nt=1; nt<=tc; nt++)
	{
		
		int n, m;
		cin >> n >> m;
		
		int tab[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> tab[i][j];
		
		int can=1;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				int canr=1, canc=1;
				for(int k=0; k<n; k++)
					if(tab[k][j]>tab[i][j])
						canc=0;
						
				for(int k=0; k<m; k++)
					if(tab[i][k]>tab[i][j])
						canr=0;
				can&=(canc|canr);
			}
		
		cout << "Case #" << nt << ": ";
		
		if(can)
			cout << "YES";
		else
			cout << "NO";
			
		cout << endl;
	}
}
