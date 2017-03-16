
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

std::string in =
    "yeqz"
    "ejp mysljylc kd kxveddknmc re jsicpdrysi"
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
    ;

std::string out =
    "aozq"
    "our language is impossible to understand"
    "there are twenty six factorial possibilities"
    "so it is okay if you want to just give up"
    ;

char table[26] = { 0 };
bool init[26] = { 0 };

void init_table()
{
    // Build the table
    assert(in.size() == out.size());

    int count = 0;
    for (int i = 0; i != in.size(); ++i) {
        if (in[i] == ' ' || out[i] == ' ') {
            continue;
        }
        int in_idx = in[i] - 'a';
        assert(in_idx >= 0 && in_idx < 26);
        int out_idx = out[i] - 'a';
        assert(out_idx >= 0 && out_idx < 26);

        if (!init[in_idx]) {
            ++count;
            table[in_idx] = out_idx;
            init[in_idx] = true;
        } else {
            assert(table[in_idx] == out_idx);
        }
    }
    assert(count == 26);
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cerr << "usage: speakingtongues INPUT_FILE" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream is(argv[1]);
    if (!is) {
        std::cerr << "error: the file `" << argv[1]
            << "' does not exist or is unreadable" << std::endl;
    }

    init_table();

    std::string count_s;
    std::getline(is, count_s);
    int testCount;
    std::stringstream ss;
    ss << count_s;
    ss >> testCount;
    std::cerr << "processing " << testCount << " tests" << std::endl;

    for (int i = 0; i < testCount; ++i) {
        std::string in_s;
        std::getline(is, in_s);

        std::string out_s;
        for (int j = 0; j < in_s.size(); ++j) {
            char c = in_s[j];
            if (c == ' ') {
                out_s += ' ';
                continue;
            }
            std::cerr << c << std::endl;
            assert(c >= 'a' && c <= 'z');
            out_s += table[c - 'a'] + 'a';
        }

        std::cout << "Case #" << i+1 << ": " << out_s << std::endl;
    }
}


