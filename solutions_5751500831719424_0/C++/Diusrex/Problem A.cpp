#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int CountNumber(const vector<string>& words, vector<string::iterator>& positions, bool& possible)
{
    char letter = *positions[0];
    
    int highestCount(0), lowestCount(-1);
    
    vector<int> counts(words.size(), 0);
    
    for (int currentWord = 0; currentWord < words.size(); ++currentWord)
    {
        if (*positions[currentWord] != letter)
        {
            possible = false;
            return 0;
        }
        
        while (positions[currentWord] != words[currentWord].end() && *positions[currentWord] == letter)
        {
            ++counts[currentWord];
            ++positions[currentWord];
        }
        
        if (counts[currentWord] > highestCount)
            highestCount = counts[currentWord];
        
        if (counts[currentWord] < lowestCount || lowestCount == -1)
            lowestCount = counts[currentWord];
    }
        
    return abs(counts[0] - counts[1]);
}


int main()
{
    int T, N;
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        
        vector<string> words(N);
        vector<string::iterator> positions(N);
        
        bool possible = true, allFinished = false, oneFinished = false;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> words[i];
            positions[i] = words[i].begin();
        }
        
        int count = 0;
        
        while (possible && !oneFinished)
        {
            count += CountNumber(words, positions, possible);
            
            allFinished = true;
            oneFinished = false;
            
            for (int word = 0; word < N; ++word)
            {
                if (positions[word] == words[word].end())
                    oneFinished = true;
                
                else
                    allFinished = false;
            }
            
            
        }
        
        if (!allFinished || !possible)
        {
            cout << "Case #" << t << ": Fegla Won\n";
        }
        
        else
            cout << "Case #" << t << ": " << count << '\n';
    }
    
    
}