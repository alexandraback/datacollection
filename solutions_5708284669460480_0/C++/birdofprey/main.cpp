enum Contest { CodeChef, CodeJam };
enum IOBinding { File, StandartStream };

Contest contest = CodeJam;

IOBinding inputBinding = File;
//IOBinding inputBinding = StandartStream;

IOBinding outputBinding = File;
//IOBinding outputBinding = StandartStream;

#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>

std::istream *input;
std::ostream *output;

class Problem {
public:
    Problem();
    void solve();

    //bool isPrefix(const std::string &str, const std::string &prefix);

    int countWords(const std::string &str);
    void print(std::string str, double prob);

    int K, L, S;
    std::string keys, word;

    double max;
    double expected;
    int count [30];
};

Problem::Problem() {
    memset(count, 0, 30 * sizeof(int));

    *input >> K >> L >> S >> keys >> word;

    for(int i = 0; i < keys.size(); ++i) {
        ++count[keys[i] - 'A'];
    }

    for(int i = 0; i < word.size(); ++i) {
        if (!count[word[i] - 'A']) {
            *output << 0.0 << '\n';
            return;
        }
    }

    int step = word.size();
    for(int i = 1; i < step; ++i) {
        bool prefix = true;
        for(int j = i; j < step; ++j) {
            if (word[j] != word[j - i]) {
                prefix = false;
                break;
            }
        }
        if (prefix) {
            step = i; break;
        }
    }
    max = 1 + (S - word.size()) / step;
    expected = 0;

    //*output << (S-word.size()) << ' ' << step << ' ' << max << '\n';
    //exit(1);

    print("", 1.0);

    output->precision(8);
    *output << max - expected << '\n';

    // *output << "MAX: " << max << '\n';

}

int Problem::countWords(const std::string &str) {
    int i = -1, res = 0;
    for(;;) {
        i = str.find(word, i + 1);
        if (i != std::string::npos) ++res;
        else return res;
    }
}

void Problem::print(std::string str, double prob) {
    if (str.size() == S) {
        expected += prob * countWords(str);
        return;
    }
    for(int i = 0; i < K; ++i) {
        str.push_back(keys[i]);
        print(str, prob / K);
        str.pop_back();
    }
}

void solveCase() {
    Problem p;


    // Solve the problem case here.
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);

    if (inputBinding == File)
        input = new std::ifstream("input.txt");
    else input = &std::cin;

    if (outputBinding == File)
        output = new std::ofstream("output.txt");
    else output = &std::cout;

    int T; *input >> T;
    for(int t = 1; t <= T; ++t) {
        if (contest == CodeJam)
            *output << "Case #" << t << ": ";
        solveCase();
    }

    if (inputBinding == File) delete input;
    if (outputBinding == File) delete output;

    return 0;
}
