#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
#define N 1000

int a[N][N];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)           
            for(int j = 0; j < n; ++j)
                a[i][j]=0;
        for(int i = 0; i < n; ++i)
        {
            int count;
            cin >> count;
            for(int j = 0; j < count; ++j)
            {
                int m;
                cin >> m;
                a[i][m-1]++;
            }
        }
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(a[i][k] > 0 && a[k][j] > 0)
                        a[i][j]++;
        bool found = false;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(a[i][j] >= 2) {
                    found = true;
                    break;
                }
        cout << "Case #" << t + 1 << ": " << (found ? "Yes" : "No") << endl;
    }
    return 0;
}
                                                

                                                                                                                    
                                                                                  
                                                                 
                                                
 
