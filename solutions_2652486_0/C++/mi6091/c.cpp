#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

//map<int, set<int> > cool;
int a[520][10000], b[520];
int res[10000];
vector <int> all; 
int r, n, m , k; 

void solve ()
{
    cin >> r >> n >> m >> k; 
    
    int i, j, k;
    for (i = 2; i <= 5 ; i ++)
        for (j = 2; j <= 5 ; j ++)
            for (k = 2; k <= 5 ; k ++)
            {
                 int ss = i * 100 + j * 10 + k; 
                 a[i][b[i]++] = ss;
                 a[j][b[j]++] = ss;
                 a[k][b[k]++] = ss;
                 a[i*j][b[i*j]++] = ss;
                 a[i*k][b[i*k]++] = ss;
                 a[j*k][b[j*k]++] = ss;
                 a[i*j*k][b[i*j*k]++] = ss;
                 
                 
                //all.push_back (ss);
                
            }
     
     for (i = 0; i < 512; i++)
         sort (a[i], a[i] + b[i]);
     
    for (i = 0; i < r; i ++)
    {
        bool got_first = false;
        memset (res, 0, sizeof (res));int rs =0 ;
        for (j = 0; j < k; j ++)
        { int p;
            cin >> p;
            if (!got_first && p != 1)
            {memcpy (res, a[p], sizeof (a[p])); rs = b[p]; got_first = 1; }
            else
            {
                if (p!=1)
                rs = set_intersection(res, res + rs, a[p], a[p] + b[p], res) - res;
            }
            
        }
        if (rs == 0)
            cout << "222" << endl;
        else
        cout << res[0] << endl;
    }
    
}

int main ()
{
    int t;
    scanf ("%d", &t);
    
    int i ;
    for (i = 0; i < t; i ++)
    {
        printf ("Case #%d:\n", i+1);
        solve();
    }
    
    
    return 0;
}