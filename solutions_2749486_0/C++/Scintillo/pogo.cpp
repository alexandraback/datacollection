#include <iostream>
#include <unordered_map>
#include <queue>

struct Item
{
    int64_t x;
    int64_t y;
    std::string jmps;

    Item(int64_t _x, int64_t _y, std::string const& _jmps)
    {
        x = _x;
        y = _y;
        jmps = _jmps;
    }
};



std::string solve()
{
    std::unordered_map<int64_t, std::unordered_map<int64_t, bool>> a;

    int64_t x, y;
    std::cin >> x >> y;

    std::queue<Item> items;
    items.push(Item(0, 0, ""));

    while(!items.empty())
    {
        Item now = items.front();
        items.pop();

        if(now.x == x && now.y == y) return now.jmps;
        if(a[now.x][now.y]) continue;
        a[now.x][now.y] = true;

        int64_t nextJmp = now.jmps.length() + 1;

        items.push(Item(now.x + nextJmp, now.y, now.jmps + 'E'));
        items.push(Item(now.x - nextJmp, now.y, now.jmps + 'W'));
        items.push(Item(now.x, now.y + nextJmp, now.jmps + 'N'));
        items.push(Item(now.x, now.y - nextJmp, now.jmps + 'S'));
    }

    return "ERROR";
}

int main()
{
    uint64_t t;
    std::cin >> t;

    for(uint64_t i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }

    return 0;
}
