#!/usr/bin/env cppsh
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

typedef long long ll;
ll solve(ll N)
{
    ll count = 1;
    ll current = 1;
    while (current != N)
    {
        std::stringstream ss;
        ss << current;
        std::string s(ss.str());
        std::reverse(s.begin(), s.end());
        ss.clear();
        ss.str(s);
        ll reverse;
        ss >> reverse;
        //std::cout << "  debug: reverse = " << reverse << std::endl;
        if (reverse <= current || reverse > N)
            current++;
        else
            current = reverse;
        //std::cout << "  debug: " << current << std::endl;
        ++count;
    }
    return count;
}

int main(int argc, char* argv[])
{
    std::string str;
    std::getline(std::cin, str);
    const int T = atoi(str.c_str());
    for (int it = 0; it < T; ++it)
    {
        ll N;
        std::cin >> N;
        std::cout << "Case #" << (it+1) << ": " << solve(N) << std::endl;
    }
    return 0;
}
