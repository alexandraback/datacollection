#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define LL long long

using namespace std;

int checkWord(string word)
{
    for(int i = 1;i < word.size();i++)
    {
        if(word[i] == word[0])
        {
            int j = i;
            for(;j < word.size();j++)
            {
                if(word[j - i] == word[j])
                    continue;
                else
                    break;
            }
            if(j == word.size())
                return i;
        }
    }
    return -1;
}

int main()
{
    int t, k, l, s, sum, alph[26] = {0};
    string keys, word;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        bool found = true;
        cin >> k >> l >> s >> keys >> word;
        for(int j = 0;j < word.size();j++)
        {
            if(keys.find(word[j]) == string::npos)
            {

                found = false;
                break;
            }
        }
        if(found == false){
            cout << "Case #" << i + 1 << ": 0.0" << endl;
            continue;
        }
        for(int j = 0;j < keys.size();j++)
            alph[keys[j] - 'A']++;
        int pos = checkWord(word);
        int counter = 1,
            len = 0;
        len += word.length();
        if(pos != -1)
            while(len < s)
            {
                len += pos;
                counter++;
            }
        else
            counter = s / word.length();
        double answer = 1;
        for(int j = 0;j < word.size();j++)
        {
            answer *= ((double)alph[word[j] - 'A'] / (double)keys.size());
        }
        cout << "Case #" << i + 1 << ": " << (double)(counter - answer*counter) << endl;
    }
    return 0;
}
