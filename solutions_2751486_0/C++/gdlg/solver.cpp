#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

void solve()
{
    std::string name; size_t n;
    std::cin >> name >> n;

    auto isConsonant = [](char c) {
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return false;
            default:
                return true;
        }
    };

    std::vector<size_t> offsets;

    size_t a=0;
    for(size_t i=0; i < name.length(); i++)
    {
        if(isConsonant(name[i]))
            a++;
        else
            a = 0;

        if(a >= n)
            offsets.push_back(i + 1 - n);
    }

    size_t count = 0;

    for(auto iter = begin(offsets); iter != end(offsets); iter++)
    {
        size_t a = *iter;
        auto niter = next(iter);

        if(niter != end(offsets))
            count += (a+1) * (*niter - a);
        else
            count += (a+1) * (name.size() + 1 - a - n);
    }

    std::cout << count;
}

int main()
{
	size_t n;
	std::cin >> n;
	while(std::cin.get() != '\n');
	for(size_t i=1; i <= n; i++)
	{
		std::cout << "Case #" << i << ": ";
		solve();
		std::cout << std::endl;
	}
}
