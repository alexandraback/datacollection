
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> words;

bool tryword(string& s, int& index, int& error, string& word, int& errc)
{
    int ws = word.size();
    for (int i = 0; i < ws; ++i)
    {
        if (s[index+i] != word[i])
        {
            if ((index+i)-error >= 5)
            {
                error = index+i;
                ++errc;
            }
            else
            {
                return false;
            }
        }
    }
    index += ws;
    return true;
}

int lookup[5000][10];

unsigned solve(string& s, int ss, int index, int error)
{
    if (index == ss) return 0;
    if (index > ss) return -1;
    
    int id = index-error-1;
    if (id > 4) id = 5;
    if (lookup[index][id] != 0)
        return lookup[index][id]-2;
    
    unsigned best = -1;
    for (string& word : words)
    {
        int newindex = index;
        int newerror = error;
        int errc = 0;
        if (tryword(s, newindex, newerror, word, errc))
        {
            unsigned v = solve(s, ss, newindex, newerror);
            if (v != -1) best = min(best, v+errc);
            if (best == 0) break;
        }
    }
    
    lookup[index][id] = best+2;
    
    return best;
}

int main()
{
    ifstream dict("garbled_email_dictionary.txt");
    words.reserve(521196);
    while (dict)
    {
        string word;
        dict >> word;
        if (!word.empty()) words.push_back(word);
    }

    int total;
    cin >> total;
    for (int current = 0; current < total; ++current)
    {
        cout << "Case #" << current+1 << ": ";
        
        string s;
        cin >> s;
        memset(lookup, 0, 5000*10*sizeof(int));
        
        int index = 0;
        int error = -10;
        int ss = s.size();
        
        int r = solve(s, ss, index, error);
        cout << r << endl;
        
    }
}
