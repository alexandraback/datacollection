#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;
    
int main()
{
    int cases, n, m, k = 1, maxh;
    cin >> cases;
    
    while(cases--) 
    {
        cin >> n >> m;
        int ar[n][m], rmax1[n][m], rmax2[n][m], cmax1[n][m], cmax2[n][m];
        bool r = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> ar[i][j];             
        
        for(int i = 0; i < n; i++)
        {    
            maxh = -1;
            for(int j = 0; j < m; j++)
            {
                rmax1[i][j] = maxh;
                maxh = max(maxh, ar[i][j]);
            }
        }
        
        for(int i = 0; i < n; i++)
        {    
            maxh = -1;
            for(int j = m-1; j >= 0; j--)
            {
                rmax2[i][j] = maxh;
                maxh = max(maxh, ar[i][j]);
            }
        }
        
        for(int j = 0; j < m; j++)
        {    
            maxh = -1;
            for(int i = 0; i < n; i++)
            {
                cmax1[i][j] = maxh;
                maxh = max(maxh, ar[i][j]);
            }
        }
        
        for(int j = 0; j < m; j++)
        {    
            maxh = -1;
            for(int i = n-1; i >= 0; i--)
            {
                cmax2[i][j] = maxh;
                maxh = max(maxh, ar[i][j]);
            }
        }
        
        for(int i = 0; i < n; i++)
        {    
            for(int j = 0; j < m; j++)
            {
                if( (ar[i][j] < rmax1[i][j] || ar[i][j] < rmax2[i][j]) && (ar[i][j] < cmax1[i][j] || ar[i][j] < cmax2[i][j]) )
                    r = 0;
            }
        }
        
        /*if(cases == 0)
        {
            
            for(int i = 0; i < n; i++)
            {    
                for(int j = 0; j < m; j++)
                    cout << rmax2[i][j] << " ";
                cout << endl;
            }
        }*/
        
        cout << "Case #" << k++ << ": ";
        switch(r) 
        {
            case 0: cout << "NO" << endl; break;
            case 1: cout << "YES" << endl; break;
        }
    }
    return 0;
}
