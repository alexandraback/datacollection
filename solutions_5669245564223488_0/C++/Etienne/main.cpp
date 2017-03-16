#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int mod = 1000000007;

void buildConnectedComponents(vector<string> &cars, vector<vector<string> > &components)
{
    components.clear();
    map<char, int> compmap;

    int numcomponents=0;
    for(int i=0; i<cars.size(); i++)
    {
        for(int j=0; j<cars[i].length(); j++)
        {
            map<char, int>::iterator it = compmap.find(cars[i][j]);
            if(it == compmap.end())
                compmap[cars[i][j]] = numcomponents++;
        }
    }

    for(int i=0; i<cars.size(); i++)
    {
        for(int j=0; j<cars[i].length()-1; j++)
        {
            if(compmap[cars[i][j]] != compmap[cars[i][j+1]])
            {
                int canonical = min(compmap[cars[i][j]], compmap[cars[i][j+1]]);
                int other = max(compmap[cars[i][j]], compmap[cars[i][j+1]]);

                for(map<char, int>::iterator it = compmap.begin(); it != compmap.end(); ++it)
                {
                    if(it->second == other)
                        compmap[it->first] = canonical;
                }
            }
        }
    }

    map<int, int> outmap;
    for(map<char, int>::iterator it = compmap.begin(); it != compmap.end(); ++it)
    {
        int comp = it->second;
        map<int, int>::iterator it2 = outmap.find(comp);
        if(it2 == outmap.end())
        {
            outmap[comp] = components.size();
            components.push_back(vector<string>());
        }
    }

    for(int i=0; i<cars.size(); i++)
        components[outmap[compmap[cars[i][0]]]].push_back(cars[i]);
}

int countComponentWays(vector<string> &cars)
{
    set<char> letters;
    for(int i=0; i<cars.size(); i++)
    {
        for(int j=0; j<cars[i].length(); j++)
            letters.insert(cars[i][j]);
    }

    if(letters.size() == 1)
    {
        int result = 1;
        for(int i=1; i<=cars.size(); i++)
            result = (result*i)%mod;
        return result;
    }

    set<char> suffixes;
    for(int i=0; i<cars.size(); i++)
    {
        for(int j=0; j<cars[i].length(); j++)
        {
            if(cars[i][j] != cars[i][0])
            {
                suffixes.insert(cars[i][j]);
            }
        }
    }

    if(letters.size() - suffixes.size() != 1)
        return 0;

    char prefix;
    for(set<char>::iterator it = letters.begin(); it != letters.end(); ++it)
        if(suffixes.count(*it) == 0)
        {
            prefix = *it;
            break;
        }

    int ways = 1;
    char curc = prefix;
    set<char> doneletters;
    while(doneletters.size() < letters.size())
    {
        int swapcars = 0;
        for(int i=0; i<cars.size(); i++)
        {
            if(cars[i][0]==curc && cars[i][cars[i].length()-1]==curc)
            {
                for(int j=0; j<cars[i].length(); j++)
                {
                    if(cars[i][j] != curc)
                        return 0;
                }
                swapcars++;
            }
        }
        if(swapcars > 0)
        {
            for(int i=1; i<=swapcars; i++)
            {
                ways = ways*i % mod;
            }
        }

        doneletters.insert(curc);
        bool found = false;
        int numdups = 0;
        for(int i=0; i<cars.size(); i++)
        {
            if(cars[i][0] == curc && cars[i][cars[i].length()-1] != curc)
            {
                numdups++;
            }
        }
        if(numdups > 1)
            return 0;
        for(int i=0; i<cars.size(); i++)
        {
            if(cars[i][0] == curc && cars[i][cars[i].length()-1] != curc)
            {
                found = true;
                int j=0;
                while(cars[i][j] == curc)
                    j++;
                for(;j<cars[i].length(); j++)
                {
                    if(cars[i][j] != curc)
                    {
                        doneletters.insert(curc);
                        curc = cars[i][j];
                        if(doneletters.count(curc))
                            return 0;
                    }
                }
            }
        }
        if(!found && doneletters.size() != letters.size())
            return 0;
    }

    return ways;
}

void testCase()
{
    int n;
    vector<string> cars;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string car;
        cin >> car;
        cars.push_back(car);
    }

    vector<vector<string> > components;
    buildConnectedComponents(cars, components);

    int ways=1;
    for(int i=0; i<components.size(); i++)
    {
        ways = (ways*countComponentWays(components[i]))%mod;
    }
    for(int i=1; i<=components.size(); i++)
    {
        ways = (ways*i)%mod;
    }
    cout << " " << ways << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << "Case #" << i+1 << ":";
        testCase();
    }
}


