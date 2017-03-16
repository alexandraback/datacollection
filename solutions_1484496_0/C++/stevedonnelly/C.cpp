#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ull;

vector<ull> reconstructSet(const map<ull, std::vector<pair<ull, ull> > >& sums, ull sum)
{
    vector<ull> set;
    while(sum != 0)
    {
        std::pair<ull, ull> previous_added = sums.find(sum)->second[0];
        set.push_back(previous_added.second);
        sum = previous_added.first;
    }
    std::reverse(set.begin(), set.end());
    return set;
}

vector<vector<ull> > equalSubsets(const vector<ull>& values)
{
    std::map<ull, std::vector<pair<ull, ull> > > sums;
    sums[0] = std::vector<std::pair<ull, ull> >(1, std::make_pair(0, 0));
    for(int i = 0, size = values.size(); i < size; i++)
    {
        vector<std::map<ull, std::vector<pair<ull, ull> > >::iterator> iterators;
        iterators.reserve(sums.size());
        for(std::map<ull, std::vector<pair<ull, ull> > >::iterator j = sums.begin(), end = sums.end(); j != end; j++)
        {
            iterators.push_back(j);
        }
        for(int k = 0, size = iterators.size(); k < size; k++)
        {
            std::map<ull, std::vector<pair<ull, ull> > >::iterator j = iterators[k];
            ull next = j->first + values[i];
            std::vector<pair<ull,ull> >& next_sums = sums[next];
            next_sums.push_back(std::make_pair(j->first, values[i]));
            if(next_sums.size() == 2)
            {
                vector<vector<ull> > sets(2);
                sets[0] = reconstructSet(sums, next_sums[0].first);
                sets[0].push_back(next_sums[0].second);
                sets[1] = reconstructSet(sums, next_sums[1].first);
                sets[1].push_back(next_sums[1].second);
                return sets;
            }
        }
    }
    return std::vector<std::vector<ull> >();
}

int main()
{
    int number_of_cases;
    cin >> number_of_cases;
    for(int i = 0; i < number_of_cases; i++)
    {
        int number_of_ints;
        cin >> number_of_ints;
        std::vector<ull> values(number_of_ints);
        for(int j = 0; j < number_of_ints; j++)
        {
            cin >> values[j];
        }
        std::vector<std::vector<ull> > results = equalSubsets(values);
        cout << "Case #" << (i + 1) << ":\n";
        if(results.empty())
        {
            cout << "Impossible\n";
        }
        else
        {
            for(int j = 0; j < 2; j++)
            {
                const std::vector<ull>& set = results[j];
                for(int k = 0, size = set.size(); k < size; k++)
                {
                    if(k != 0) cout << " ";
                    cout << set[k];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}


