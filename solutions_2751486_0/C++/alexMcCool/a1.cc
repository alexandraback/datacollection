#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>

bool isVowel(char c)
{
    switch (c)
    {
        case 'a': return true;
        case 'e': return true;
        case 'i': return true;
        case 'o': return true;
        case 'u': return true;
    
        default: return false;
    }
}

bool isCons(char c)
{
    return !isVowel(c);
}

using namespace std;

int solve(ifstream & in)
{
    string s;

    in >> s;


    int n;
    in >> n;

    cout << s << endl;
    cout << n << endl;
    
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int cCount = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (isCons(s[j]))
            {
                cCount++;
            }

            else
            {
                cCount = 0;
            }

            if (cCount == n)
            {
                for (int k = i; k <= j; k++)
                    cout << s[k];
                cout << s.size() - j << endl;
                cout << endl;
                total += (s.size() - j);
                break;
            }
        }
    }

    return total;
}
        

    
    

int main()
{
    ifstream in;
    in.open("a1.in");
    ofstream out;
    out.open("a1.out");

    size_t T;
    in >> T;
    cout << T << endl;
    for (size_t i = 1; i <= T; i++)
    {
        out << "Case #" << i << ": ";
        out << solve(in) << endl;
    }

    in.close();
    out.close();
    return 0;
}
