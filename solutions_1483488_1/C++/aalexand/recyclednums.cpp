
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>

typedef std::vector<int> int_list_t;
typedef std::pair<int, int> int_pair_t;

long long fact(int x)
{
    long long ret = 1;
    for (int i = 2; i <= x; ++i) {
        long long ret2 = ret * i;
        assert(ret2 >= ret); // Control overflow
        ret = ret2;
    }
    return ret;
}

int num_uniq_pairs(int x)
{
    return (x & 1) ? ((x-1) / 2 * x) : ((x-1) / 2 * x + x / 2);
}

// '12345' -> '51234'
std::string rotate_right(std::string x)
{
    std::rotate(x.begin(), x.end() - 1, x.end());
    return x;
}

int to_int(const std::string& s)
{
    return atoi(s.c_str());
}

std::string to_str(int x)
{
    char buf[64];
    sprintf(buf, "%d", x);
    return buf;
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cerr << "usage: recyclednums INPUT_FILE" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream is(argv[1]);
    if (!is) {
        std::cerr << "error: the file `" << argv[1]
            << "' does not exist or is unreadable" << std::endl;
    }

    assert(rotate_right("123") == "312");
    assert(rotate_right("0") == "0");
    assert(rotate_right("11") == "11");
    assert(rotate_right("12345") == "51234");
    assert(num_uniq_pairs(3) == 3);
    assert(num_uniq_pairs(4) == 6);

    int testCount;
    is >> testCount;
    std::cerr << "processing " << testCount << " cases" << std::endl;

    for (int i = 0; i < testCount; ++i) {
        int A;
        is >> A;
        int B;
        is >> B;
        int num_elems = B - A + 1;

        std::vector<bool> seen(num_elems);
        long long count = 0;
        long long num_count = 0;
        for (int j = A; j <= B; ++j) {
            if (seen[j-A]) {
                // We have seen this group before
                continue;
            }

            int this_count = 0;
            int jj = j;
            std::string jjj = to_str(jj);

            do {
                ++this_count;
                seen[jj-A] = true;
                do {
                    jjj = rotate_right(jjj);
                    jj = to_int(jjj);
                } while (jj < A || jj > B);
            } while (!seen[jj-A]);

            if (this_count > 1) {
                //std::cout << j << ": " << this_count << std::endl;
                count += num_uniq_pairs(this_count);
            }
            num_count += this_count;
        }
        for (int j = A; j <= B; ++j) {
            assert(seen[j-A]);
        }
        assert(num_count == num_elems);

        std::cout << "Case #" << i+1 << ": " << count << std::endl;
    }
}

