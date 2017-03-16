#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      int n, m;
      cin >> n >> m;
      int arr[n][m];
      for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	  cin >> arr[i][j];

      bool yes = true;

      //rows
      for(int i = 0; i < n; i++)
	{
	  int max = 0;
	  for(int j = 0; j < m; j++)
	    if(arr[i][j] > max)
	      max = arr[i][j];

	  for(int j = 0; j < m; j++)
	    if(arr[i][j] < max)
	      for(int k = 0; k < n; k++)
		if(arr[k][j] > arr[i][j])
		  yes = false;
	}

      //cols
      if(yes)
	for(int i = 0; i < m; i++)
	  {
	    int max = 0;
	    for(int j = 0; j < n; j++)
	      if(arr[j][i] > max)
		max = arr[j][i];
	    
	    for(int j = 0; j < n; j++)
	      if(arr[j][i] < max)
		for(int k = 0; k < m; k++)
		  if(arr[j][k] > arr[j][i])
		    yes = false;
	  }
      
      cout << "Case #" << tc << ": ";
      if(yes)
	cout << "YES\n";
      else
	cout << "NO\n";
      //
    }
  return 0;
}
