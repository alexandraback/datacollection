#include <fstream>
#include <assert.h>

bool process(size_t x, size_t r, size_t c)
{
    if ((r * c) % x)
        return true;

    if (x >= 4)
        return true;

    if (x == 1)
        return false;

    if (x == 2)
        return (r % 2) && (c % 2);

    if (x == 3)
        return r == 1 || c == 1;

    return false;
}

int main(int argc, char * argv[])
{
    std::ifstream in("in_d.txt");
    std::ofstream out("out_d.txt");

    size_t T;
    in >> T;
    for (int i = 0; i != T; ++i)
    {
        size_t X, R, C;
        in >> X >> R >> C;

        out << "Case #" << i + 1 << ": " << (process(X, R, C) ? "RICHARD" : "GABRIEL") << std::endl;
    }
}
