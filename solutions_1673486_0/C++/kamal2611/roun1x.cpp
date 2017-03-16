#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;
double ENTER = 1.0;
double BACK = 1.0; 

int main()
{
    int t;    
    cin >> t;
    for(int tr = 0; tr < t ; tr++)
    {
            int enNum,tNum;
            cin >> enNum;
            cin >> tNum;
            double retyp = tNum + ENTER;
            double res = ENTER + retyp;
            double pTotal = 1;
            for(int pNum = 0; pNum < enNum; pNum++)
            {
                    double pEn;
                    double backNum = enNum - (1.0 + pNum);
                    
                    cin >> pEn;
                    pTotal *= pEn;
                    double keepTy = backNum + backNum + ENTER + (tNum - enNum);
                    double tempres = pTotal * (keepTy) + (1.0 - pTotal)*(keepTy + retyp);
                    if(tempres*10000 < res*10000)
                    {
                         res = tempres;             
                    }
                    
            }
            cout << fixed;
            cout << "Case #"<< tr + 1 <<": " << setprecision(6) << res << endl; 
    
    }
    return 0;
}
