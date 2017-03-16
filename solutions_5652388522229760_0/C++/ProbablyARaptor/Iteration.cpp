#include "Iteration.h"

std::vector<std::string> Split(const char *str, char c)
{
    std::vector<std::string> result;
    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(std::string(begin, str));
    } while (0 != *str++);

    return result;
}

std::vector<int> SpaceDelimitedToInt(std::string input)
{
	return MapFunc<std::string,int,std::vector<int>>(
							Split(input.c_str(), ' '),
							[](std::string s) {return stoi(s);});
}