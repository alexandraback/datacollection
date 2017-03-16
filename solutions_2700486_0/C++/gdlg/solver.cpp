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
    // Load everything
    int armin, n;
    std::cin >> armin >> n;
   
    std::vector<int> motes(n);
    for(int i=0; i < n; i++)
        std::cin >> motes[i];

    if(armin == 1)
    {
        std::cout << n;
        return;
    }

    // Operation count
    std::sort(begin(motes), end(motes));

    std::vector<int> count;
    count.push_back(motes.size());

    int numGrowth = 0;
    for(auto iter = begin(motes); iter != end(motes); iter++)
    {
        int m = *iter;

        // Not big enough, add some motes
        if(armin <= m)
        {
            while(armin <= m)
            {
                armin += armin - 1;
                numGrowth++;
            }
        }

        // Absorb this mote
        armin += m;

        // Add this game end possibility
        count.push_back(numGrowth + (end(motes) - iter) - 1);
    }

    // Find best possibility
    std::cout << *min_element(begin(count), end(count));

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
