#include "HelperFunctions.h"
#include <sstream>
#include <unordered_set>

using namespace std;

int main()
{
    auto lines = GetLines("small.input");
    vector<string> solutions;
    for(auto i = 1; i < lines.size(); ++i)
    {
        auto start = stoi(lines[i]);
        if(start == 0)
        {
            stringstream oss;
            oss << "Case #" << i << ": Insomnia";
            solutions.push_back(oss.str());
            continue;
        }

        stringstream working;
        unordered_set<char> found;
        auto value = 0;
        auto counter = 0;
        while(found.size() < 10)
        {
            counter++;
            value = counter * start;
            printf("%d\n", value);
            working.str("");
            working << value;
            for(auto c : working.str())
            {
                found.insert(c);
            }
        }

        stringstream oss;
        oss << "Case #" << i << ": " << value;
        solutions.push_back(oss.str());
    }

    PrintLines("small.output", solutions);
}