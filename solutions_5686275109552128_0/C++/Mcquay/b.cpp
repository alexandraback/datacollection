#include <fstream>
#include <algorithm>
#include <vector>
#include <assert.h>

size_t cost(size_t max_height, std::vector<size_t> const & plates)
{
    size_t res = 0;
    for (size_t a: plates)
    {
        size_t c = a / max_height;
        if (c * max_height < a)
            c += 1;

        assert(c >= 1);
        res += c - 1;
    }

    return res;
}

size_t process(std::vector<size_t> plates)
{
    size_t max = *std::max_element(plates.begin(), plates.end());

    size_t res = max;
    for (size_t i = 1; i < max; ++i)
    {
        size_t ci = cost(i, plates) + i;
        if (ci < res)
            res = ci;
    }

    return res;
}

int main(int argc, char * argv[])
{
    std::ifstream in("in_b.txt");
    std::ofstream out("out_b.txt");

    size_t T;
    in >> T;
    for (int i = 0; i != T; ++i)
    {
        size_t D;
        in >> D;

        std::vector<size_t> plates(D);
        for (size_t i = 0; i != D; ++i)
            in >> plates[i];

        out << "Case #" << i + 1 << ": " << process(std::move(plates)) << std::endl;
    }
}
