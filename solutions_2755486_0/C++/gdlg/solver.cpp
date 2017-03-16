#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Tribe
{
public:
    unsigned d;
    unsigned n;
    int w, e;
    unsigned s;
    unsigned dd;
    int dp;
    int ds;
};

istream& operator>>(istream& in, Tribe& t)
{
    std::cin >> t.d >> t.n >> t.w >> t.e >> t.s >> t.dd >> t.dp >> t.ds;
    return in;
}

bool operator<(const Tribe& t1, const Tribe& t2)
{
    return t1.d > t2.d;
}


void solve()
{
    size_t N;
    std::cin >> N;

    std::priority_queue<Tribe> tribes;

    for(size_t i=0; i < N; i++)
    {
        Tribe t;
        std::cin >> t;
        tribes.push(t);
    }

    const int wallMin = -300, wallMax = 300;
    std::vector<unsigned> wall(2*(wallMax - wallMin + 1));
    std::vector<unsigned> wallInc(2*(wallMax - wallMin + 1));

    size_t numSuccess = 0;
    size_t day = 0;

    while(!tribes.empty())
    {
        Tribe t = tribes.top();
        tribes.pop();

        if(t.d != day)
        {
            // New day, build the wall
            for(size_t i=0; i < wall.size(); i++)
            {
                wall[i] += wallInc[i];
                wallInc[i] = 0;
            }

            day = t.d;
        }

        // Attack
        bool success = false;

        for(int a = 2*t.w; a <= 2*t.e; a++)
        {
            unsigned ws = wall[a - 2*wallMin];

            if(ws < t.s)
            {
                success = true;
                wallInc[a - 2*wallMin] = std::max(wallInc[a - 2*wallMin], t.s - ws);
            }
        }

        if(success)
            numSuccess++;

        // Update
        if(--t.n == 0)
            continue;

        t.d += t.dd;
        t.w += t.dp;
        t.e += t.dp;
        t.s += t.ds;

        tribes.push(t);
    }

    std::cout << numSuccess;
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
