#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int digits( int n )
{
    if (1 <= n && n <= 9)
    {
        return 1;
    }
    if (10 <= n && n <= 99)
    {
        return 2;
    }
    if (100 <= n && n <= 999)
    {
        return 3;
    }
    if (1000 <= n && n <= 9999)
    {
        return 4;
    }
}

bool isPal( int number )
{
    static int pow10[] = {1, 10, 100, 1000, 10000};
    int dig = digits(number);
    bool res = true;
    for (int i = 0; i < dig / 2; ++i)
    {
        int a = (number / pow10[dig - i - 1]) % 10;
        int b = (number / pow10[i]) % 10;
        if (a != b)
        {
            res = false;
            break;
        }
    }
    
    return res;
}

int main()
{
    ifstream inFile( "C-small-attempt0.in" );
    ofstream outFile( "C-small-attempt0.out" );
    int caseCount;
    inFile >> caseCount;
  
    for (int caseIx = 1; caseIx <= caseCount; ++caseIx)
    {
        int A;
        inFile >> A;
        int B;
        inFile >> B;
        int from = (int)sqrt(A) - 1;
        int to = (int)sqrt(B) + 1;
        int counter = 0;
        for (int test = from; test <= to; ++test)
        {
            int test2 = test * test;
            if (isPal(test) && isPal(test2) && test2 >= A && test2 <= B)
            {
                ++counter;
            }
        }
        cout << "Case #" << caseIx << ": " << counter << endl;
        outFile << "Case #" << caseIx << ": " << counter << endl;
    }

    
    inFile.close();
    outFile.close();
    return 0;
}
