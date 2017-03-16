#include <iostream>
#include <string>
#include <vector>
using namespace std; 


typedef unsigned long long ULLT;
vector<ULLT> VV;


ULLT llmt = 10000ull;
int a[1000] = {0};
ULLT N,M;
bool Check(ULLT x)
{
    if (x%10 == 0) return false;
    int t = 0;
    while(x > 0)
    {
        a[t++] = x%10;
        x/= 10;
 
    }
    
    for (int i = 0; i < t/2; i++)
    {
        
        if (a[i] != a[t - i - 1 ]) return false;
    }
    return true;
}


int main()
{
   // freopen("C-small-attempt0.in", "r", stdin);
 //   freopen("C-small-attempt0.out", "w", stdout);
    for (ULLT i= 1 ; i * i <= llmt; i++)
    {
        ULLT XX = i*i;
        if (Check(XX) && Check(i)) 
        {
            VV.push_back(XX);
      
        }    
    }
    
  
    int T = 0; 
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N>> M;
        int ret = 0;
        
        for (int i = 0; i < VV.size(); i++)
        {
            if (VV[i] >= N && VV[i] <= M) ret++;
        }
    
        cout << "Case #"<<t<<": "<< ret <<endl;
 
    }
    
    //while(1);
}
