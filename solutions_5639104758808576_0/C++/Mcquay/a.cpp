#include <fstream>

size_t process(size_t s_max, std::string const & s)
{
    size_t res = 0;
    size_t persons = 0;

    for (char c: s)
    {
        persons += c - '0';
        if (persons)
            persons -= 1;
        else
            res += 1;
    }

    return res;
}

int main(int argc, char * argv[])
{
    std::ifstream in("in_a.txt");
    std::ofstream out("out_a.txt");

    size_t T;
    in >> T;
    for (int i = 0; i != T; ++i)
    {
        size_t Smax;
        std::string s;

        in >> Smax >> s;

        out << "Case #" << i + 1 << ": " << process(Smax, s) << std::endl;
    }
}
