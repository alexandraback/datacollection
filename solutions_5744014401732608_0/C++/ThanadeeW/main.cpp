#include "main.h"

using namespace std;

std::ofstream Core::case_input("case_input.txt");

int main(int argc, char** argv) {
    if (argc == 1) {
        if (freopen("in.txt", "r", stdin) == nullptr) {
            throw runtime_error("can't read in.txt");
        }
        if (freopen("out.txt", "w", stdout) == nullptr) {
            throw runtime_error("can't write out.txt");
        }
        if (freopen("err.txt", "w", stderr) == nullptr) {
            throw runtime_error("can't write err.txt");
        }
    }
    Core::init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cerr << "Case #" << i << ": " << endl;
        Core::case_input << "Case #" << i << ": " << endl;
        try {
            auto cmill = Core::getCurrentMillisecond();
            Core::solve();
            cerr << "Run time: " << Core::getCurrentMillisecond() - cmill << endl;
        } catch (std::exception const& e) {
            Core::case_input << e.what() << endl;
            abort();
        }
        Core::case_input << endl;
        cerr << endl;
        //cout << endl;
    }
    return 0;
}