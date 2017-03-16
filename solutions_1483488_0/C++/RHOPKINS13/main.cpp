#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool MatchingPair(int n, int m);

int main()
{
    int t;  // Number of Test Cases
    cin >> t;
    for(int i = 0; i < t; i++)
    {
       int A;
       int B;
       int result = 0;
       cin >> A;
       cin >> B;

       for(int n = A; n < B; n++)
       {
           for(int m = n + 1; m <= B; m++)
            {
                if (MatchingPair(n,m)) result = result + 1;
            }
       }


        cout << "Case #" << i + 1 << ": " << result << endl;
    }

    return 0;
}


bool MatchingPair(int n, int m)
{
    stringstream ns, ms;
    string nstring;
    string mstring;

    ns << n;
    nstring = ns.str();
    ms << m;
    mstring = ms.str();

    for(int i = 1; i < nstring.length(); i++)
        {
            if ((nstring.substr(i, nstring.length() - i) + nstring.substr(0,i)) == mstring) return true;
        }
    return false;
}
