#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;


struct Word
{
    char first;
    char last;
    string complete; 
};

long long int MOD = 1000000007;

long long int fact(long long int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n-1)) % MOD;
}

int main(int argc, char** argv)
{
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    long long int nLines = boost::lexical_cast<long long int>(line); 

    for (long long int caseNo=0; caseNo < nLines; ++caseNo)
    {
        out << "Case #" << caseNo+1 << ": ";
      
        long long int nWords;
        in >> nWords;

        std::vector<Word> words(nWords);

        for (long long int i=0; i<nWords; ++i)
        {
            in >> words[i].complete;
                
            words[i].first = *words[i].complete.begin();
            words[i].last = *words[i].complete.rbegin();
        }

        map<char, long long int> starts;
        map<char, long long int> ends;
        map<char, long long int> usedinternal;
        map<char, long long int> repeaters;
        map<char, char> followup;

        bool isIllegal = false;

        for (auto& word: words)
        {
            if (word.first == word.last)
            {
                for (auto c: word.complete)
                {
                    if (c != word.first)
                    {
                        isIllegal = true;
                    }
                }
                repeaters[word.first]++;
            }
            else
            {
                starts[word.first]++;
                ends[word.last]++;

                followup[word.first] = word.last;

                auto iter = word.complete.begin();
                
                while (*iter == word.first && iter != word.complete.end())
                    ++iter;
                
                char lastchar = 0;

                while (*iter != word.last && iter != word.complete.end())
                {
                    if (lastchar != *iter)
                    {
                        usedinternal[*iter]++;
                        lastchar = *iter;
                    }
                    ++iter;
                }

                while (iter != word.complete.end())
                {
                    if (*iter != word.last)
                    {
                        isIllegal = true;
                    }
                    ++iter;
                }
            }
        }
            
        long long int letterStart = 0;
        long long int letterStartHandled = 0;

        long long int totalPoss = 1;
        long long int totalGroup = 0;

        for (char t = 'a' ; t <= 'z' ; ++t)
        {
            if ( usedinternal[t] > 1 || 
                (usedinternal[t] == 1 && (starts[t] > 0 || ends[t] > 0 || repeaters[t] > 0)) ||
                (starts[t] > 1) ||
                (ends[t] > 1))
            {
                isIllegal = true;
            }

            if (starts[t] == 1)
            {
                letterStart++;
            }
            
            if (starts[t] == 0 && ends[t] == 0 && repeaters[t] > 0)
            {
                totalPoss *= fact(repeaters[t]) % MOD;
                totalGroup++;
            }

            if (ends[t] == 0 && starts[t] == 1)
            {
                totalGroup++;

                char startchar = t;
                while (startchar != 0)
                {
                    letterStartHandled++;
                    totalPoss *= fact(repeaters[startchar]);
                    totalPoss %= MOD;
                    startchar = followup[startchar];
                }
            }

        }
        
        long long int groupFact = fact(totalGroup);
       
        long long int allTogether = 1;

        for (long long int i=0; i < groupFact; ++i)
        {
            allTogether *= totalPoss;
            allTogether = allTogether % MOD;
        }

        
        if (isIllegal)
        {
            out << "0";
        }
        else
        {
            out << allTogether;
        }

        out << endl;
    }


    return 0;
}

