/*
Don't read this code. I have no idea why it works (or doesn't).

I take no responsibility if reading this code makes you crazy. You have been warned.
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>
#include <map>

template <typename T>
std::string toStr(T value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
}

struct Chest
{
    unsigned int openKey;
    std::vector<unsigned int> contains;
};


const unsigned int maxKey = 40;
std::vector<Chest> chests;
std::vector<int> startKeys;

typedef std::map<unsigned long, std::vector<unsigned int>> Cache;
Cache cache;

std::vector<unsigned int> solve(std::bitset<20>& opened)
{


    auto it = cache.find(opened.to_ulong());

    if(it != cache.end())
        return it->second;

    std::vector<int> keys = startKeys;

    for(unsigned int i = 0; i < 20; i++)
    {
        if(opened[i])
        {
            Chest const& chest = chests[i];

            keys[chest.openKey]--;

            for(unsigned int l : chest.contains)
            {
                keys[l]++;
            }
        }
    }

    /*if(opened.count() == 5 && opened[0] == true && opened[1] == true && opened[2] == true && opened[3] == true && opened[4] == true)
    {
        std::cout << "Hello" << std::endl;
    }*/

    for(int i : keys)
        if(i < 0) return std::vector<unsigned int>();

    if(opened.count() == 1)
    {
        for(int i = 19; i >= 0; i--)
        {
            if(opened[i])
            {
                Chest const& chest = chests[i];

                for(unsigned int l : chest.contains)
                {
                    keys[l]--;
                }

                /*bool good = true;

                for(int i : keys)
                    if(i < 0)
                    {
                        good = false;
                        break;
                    }*/

                if(keys[chest.openKey] >= 0) return std::vector<unsigned int>({ i });
                else return std::vector<unsigned int>();
            }
        }
    }

    std::vector<unsigned int> bestResult;

    for(int i = 19; i >= 0; i--)
    {
        if(opened[i])
        {
            Chest const& chest = chests[i];

            for(unsigned int l : chest.contains)
            {
                keys[l]--;
            }

            /*bool good = true;

            for(int i : keys)
                if(i < 0)
                {
                    good = false;
                    break;
                }*/

            if(keys[chest.openKey] >= 0)
            {
                opened[i] = false;

                std::vector<unsigned int> result = solve(opened);

                if(!result.empty())
                {
                    //result.push_back(i);
                    //return result;

                    for(unsigned int j = 0; j < result.size(); j++)
                    {
                        if(bestResult.empty() || result[j] < bestResult[j])
                        {
                            bestResult = result;
                            bestResult.push_back(i);
                            break;
                        }

                        if(result[j] > bestResult[j])
                            break;
                    }
                }

                opened[i] = true;
            }

            for(unsigned int l : chest.contains)
            {
                keys[l]++;
            }
        }
    }

    cache[opened.to_ulong()] = bestResult;

    return bestResult;
}

std::string doSomething()
{
    cache.clear();
    chests.clear();
    startKeys.clear();

    startKeys.resize(maxKey + 1);

    unsigned int keyCount, chestCount;

    std::cin >> keyCount >> chestCount;

    for(unsigned int i = 0; i < keyCount; i++)
    {
        unsigned int key;
        std::cin >> key;

        startKeys[key]++;
    }

    chests.resize(chestCount);
    for(Chest& chest : chests)
    {
        std::cin >> chest.openKey;

        unsigned int containedKeyCount;
        std::cin >> containedKeyCount;
        chest.contains.resize(containedKeyCount);

        for(unsigned int& key : chest.contains)
        {
            std::cin >> key;
        }
    }

    std::bitset<20> asd((1u << chestCount) - 1);

    //std::cout << asd[0] << std::endl;

    std::vector<unsigned int> res = solve(asd);

    if(res.empty())
    {
        return " IMPOSSIBLE";
    }
    else
    {
        std::string str;

        for(unsigned int i : res)
        {
            str += " " + toStr(i + 1);
        }

        return str;
    }
}

int main()
{
    unsigned int t;

    std::cin >> t;
    for(unsigned int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ":" << doSomething() << std::endl;
    }

    return 0;
}
