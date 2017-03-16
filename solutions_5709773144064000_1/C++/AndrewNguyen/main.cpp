//
//  main.cpp
//  Cooker Clicker Alpha
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int ncases;
    scanf("%d", &ncases);
    
    for (int i = 0; i < ncases; ++i)
    {
        double C, F, X;
        //vector<double> s;
        
        scanf("%lf %lf %lf", &C, &F, &X);
        double s[2];
        
        s[0] = X / 2.0;
        s[1] = C / 2.0 + X / (2.0 + F);
        int idx1 = 0, idx2 = 1;
        double tail = C / 2.0;
        int n = 1;
        while (true)
        {
            if (s[idx1] < s[idx2])
            {
                printf("Case #%d: %.7lf\n",i+1, s[idx1]);
                break;
            }
            else
            {
                n++;
                int tmp = idx1;
                idx1 = idx2, idx2 = tmp;
                tail += C / (2.0 + F*(n-1));
                s[idx2] = tail + X / (2.0 + F*n);
            }
        }
    }
    
    return 0;
}

