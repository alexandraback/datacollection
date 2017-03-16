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

size_t solve(ifstream & in)
{
    string s;

    in >> s;


    size_t n;
    in >> n;

    cout << s << endl;
    cout << n << endl;
    size_t prevIndex = 0;
    size_t total = 0;
    bool prev = false;
    size_t cCount = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isCons(s[i]))
        {
            cCount++;
        }
        else
        {
            cCount = 0;
        }

        if (cCount == n)
        {
            //cout << s.size() - i << " " << i - n - prevIndex + 2 << endl;

            total += (s.size() - i) * (i - n - prevIndex + 2);
            cCount = n-1;
            prevIndex = i - (n-1) + 1;
        }
    }

    //cout << "total: :" << total << endl;

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
