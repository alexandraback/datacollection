#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ifstream inFile( "C-small-1-attempt0.in" );
    int caseCount;
    inFile >> caseCount;
    int R, N, M, K;
    inFile >> R >> N >> M >> K;
    
    cout << "Case #1:" << endl;
    for (int i = 1; i <= R; ++i)
    {
        bool mustBe4 = false;
        int maxPow2 = 0;
        int maxPow3 = 0;
        int maxPow5 = 0;
        for (int i = 0; i < K; ++i)
        {
            int pow2 = 0;
            int pow3 = 0;
            int pow5 = 0;

            int num;
            inFile >> num;
            int numOrig = num;
            while (num % 5 == 0)
            {
                pow5++;
                num /= 5;
            }
            while (num % 3 == 0)
            {
                pow3++;
                num /= 3;
            }
            while (num % 2 == 0)
            {
                pow2++;
                num /= 2;
            }
            if (pow2 > maxPow2) maxPow2 = pow2;
            if (pow3 > maxPow3) maxPow3 = pow3;
            if (pow5 > maxPow5) maxPow5 = pow5;
            if (pow2 + pow3 + pow5 > 3) mustBe4 = true;
        }
        if (maxPow5 + maxPow3 == 3)
        {
            for (int i = 0; i < maxPow3; ++i) cout << "3";
            for (int i = 0; i < maxPow5; ++i) cout << "5";
            cout << endl;
            continue;
        }

        if (maxPow5 + maxPow3 == 2)
        {
            if (mustBe4) cout << "4";
            else cout << "2";
            for (int i = 0; i < maxPow3; ++i) cout << "3";
            for (int i = 0; i < maxPow5; ++i) cout << "5";
            cout << endl;
            continue;
        }
        
        if (maxPow5 + maxPow3 == 1)
        {
            if (maxPow2 >= 4) cout << "44";
            else if (maxPow2 == 3) cout << "24";
            else cout << "22";
            for (int i = 0; i < maxPow3; ++i) cout << "3";
            for (int i = 0; i < maxPow5; ++i) cout << "5";
            cout << endl;
            continue;
        }
        if (maxPow5 + maxPow3 == 0)
        {
            if (maxPow2 >= 6) cout << "444";
            else if (maxPow2 == 5) cout << "244";
            else if (maxPow2 == 4) cout << "224";
            else cout << "222";
            cout << endl;
            continue;
        }
        cout << "ERROR" << endl;
    }
    
    inFile.close();
    return 0;
}
