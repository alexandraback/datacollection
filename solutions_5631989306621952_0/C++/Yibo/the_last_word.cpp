#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void process_case() {
    string s;
    cin >> s;
    string out = s.substr(0, 1);
    for (int i = 1; i < s.length(); ++i)
    {
        char c = s[i];
        if (c < out[0]) {
            out = out + c;
        } else {
            out = c + out;
        }
    }

    cout << out;
}

int main() {
    std::ifstream in("A-small-attempt0.in");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("A-small-attempt0.out");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!


    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << (i + 1) << ": ";
        process_case();
        cout << endl;
    }

    return 0;
}