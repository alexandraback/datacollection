#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>


using namespace std;
int main()
{
    int T;
    cin >> T;
    double pcorrect[100001];
    double p_upto[100001];
    double c[100001];
    for (int t = 0; t < T; t++)
    {
        int A , B;
        cin >> A >> B;
        for (int i = 0; i < A; i++)
        {
            cin >> pcorrect[i];
        }
        
        c[0] = 0.0;
        if (A>0)
        {
            c[1] = 1-pcorrect[0];
        }
        if (A>1)
        {
            c[2] = (1-pcorrect[0])*pcorrect[1] + (1-pcorrect[1])*pcorrect[0];
        }
        if (A>2)
        {
            c[3] = (1-pcorrect[0])*pcorrect[1]*pcorrect[2] + (1-pcorrect[1])*pcorrect[0]*pcorrect[2] + (1-pcorrect[2])*pcorrect[0]*pcorrect[1] + 
                    (1-pcorrect[2])*(1-pcorrect[0])*pcorrect[1]+(1-pcorrect[1])*(1-pcorrect[0])*pcorrect[2]+(1-pcorrect[2])*(1-pcorrect[1])*pcorrect[0] 
                    + (1-pcorrect[2])*(1-pcorrect[0])*(1-pcorrect[1]);
        }
        
        
        for (int i = 0; i <= A; i++)
        {
            double temp = 1.0;
            for (int j = 0; j < i; j++)
            {
                temp *= pcorrect[j];
            }
            p_upto[i] = temp;
        }
        
        double res = double(B+2);
        
        cerr << "Case " << t+1 << endl;
        for (int i = 0; i <= A ; i++)
        {
            cerr << p_upto[i] << " " ;
        }
        cerr << endl;
        double expect_goon_erasing[100001];
        for (int i = 0; i < A+1; i++)
        {
            expect_goon_erasing[i] = double(2*i-A) + (1.0+c[A-i])*double(B+1);
            if (expect_goon_erasing[i] < res)
            {
                res = expect_goon_erasing[i];
                cerr <<  i << " " << expect_goon_erasing[i] << endl;
            }
        }
        
        cout << "Case #" << t+1 << ": " << res << endl;
    }
    
    return 0;
}
