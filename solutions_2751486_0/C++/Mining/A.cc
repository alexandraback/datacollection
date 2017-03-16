#include <string>
#include <iostream>

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

/*
Defn of n-value
Therefore, he announces that the social 
status of a member in the tribe is determined by its n-value, 
which is the number of substrings with at least n consecutive
consonants in the name.

Input

The first line of the input gives the number of test cases, T.
T test cases follow. The first line of each test case gives the name
\f a member as a string of length L, and an integer n. 
Each name consists of one or more lower-case English letters.


Output

For each test case, output one line containing "Case #x: y", 
where x is the case number (starting from 1) 
and y is the n-value of the member's name. 

*/
using namespace std;

bool validSS(string str , int n)
{
    int temp_count = 0;
    int count = 0;
    for(int i = 0; i < str.length(); i++)
    {
        bool b = true;
        for(int j = 0; j < 6; j++)
            if(vowels[j] == str[i])
                b = false;
        if(b)
            temp_count++;
        else
            temp_count = 0;
        count = count > temp_count ? count : temp_count; 
    }
    //cout << str << '\t' << count << '\n';
    if(count >= n)
            return true;
    return false;
}

int nVal(string s, int n)
{
    int count = 0;
    for(int i = 0; i < s.length(); i++)
        for(int j = 0; j < s.length() - i + 1; j++)
        {
            if(validSS(s.substr(i,j), n))
                count++;
        }
    return count;
}


int main()
{
    int nCases;
    cin >> nCases;
    for(int i = 0; i < nCases; i++)
    {
        string s;
        cin >> s;
        int n;
        cin >> n;
        cout << "Case #" << i+1 << ": " << nVal(s,n) <<'\n';
    }
    return 0;
}