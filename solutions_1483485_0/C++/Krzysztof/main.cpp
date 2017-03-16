#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <map>

using namespace std;

const std::string plain  = "abcdefghijklmnopqrstuvwxyz ";
const std::string cipher = "yhesocvxduiglbkrztnwjpfmaq ";

int main() {
    ifstream is("input.txt");
    ofstream os("output.txt");

    map<char, char> dict;
    for (size_t i = 0; i < plain.size(); ++i)
        dict[plain[i]] = cipher[i];

    size_t tests;
    string line;

    is >> tests;
    getline(is, line);  // swallon newline.

    for (size_t t = 1; t <= tests; ++t) {
        getline(is, line);

        os << "Case #" << t << ": ";
        for (size_t i = 0; i < line.size(); ++i)
            os << dict[line[i]];
        os << endl;
    }
}

/*
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities

de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up

y qee
a zoo
*/
