#include <fstream>

using namespace std;

long long sol, last_sol;
int i, l, k, t, n, test;
string s;

bool vowel(char x)
{
    return (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u');
}

int main()
{
    ifstream fi("test.in");
    ofstream fo("test.out");
    fi >> t;
    while(t--)
    {
        test++;
        fi >> s >> n;
        l = s.length();
        k = 0;
        sol = last_sol = 0;
        for(i = 0; i < l; i++)
        {
            if(!vowel(s[i])) k++; else k = 0;
            if(k >= n)
            {
                sol += i + 1 - (n-1);
                last_sol = i + 1 - (n-1);
            }
            else sol += last_sol;
        }
        fo << "Case #" << test << ": " << sol << "\n";
    }
    return 0;
}
