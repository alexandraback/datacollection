#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct testcase {
    long double c;
    long double f;
    long double x;
};

vector<testcase*> cases;

bool readFile() {
    std::string line;
    std::ifstream cfile("ccinput.txt");

    if(cfile.is_open()) {
        getline(cfile, line);
        int num = std::stoi(line);
        for(int i = 0; i < num; i++) {
            getline(cfile, line);
            testcase *loaded = new testcase();
            std::string::size_type sz = 0;
            loaded->c = std::stold(line, &sz);
            line = line.substr(sz);
            loaded->f = std::stold(line, &sz);
            line = line.substr(sz);
            loaded->x = std::stold(line, &sz);

            cases.push_back(loaded);
        }
        cfile.close();
    }
    else return false;

    return true;
}

void writeFile(vector<string*> towrite) {
    ofstream out;
    out.open("ccout.txt");
    for(unsigned int i = 0; i < towrite.size(); i++) {
        out << *towrite[i] << endl;
    }
    out.close();
}

int main(int argc, char **argv) {
    readFile();

    vector<string*> towrite;

    for(int i = 0; i < cases.size(); i++) {
        testcase *tc = cases[i];

        long double seconds = 0.0L;
        long double cprod = 2.0L;
        while( (tc->x / cprod) > ((tc->c / cprod) + (tc->x / (cprod+tc->f))) ) {
            seconds += tc->c / cprod;
            cprod += tc->f;
        }

        seconds += tc->x / cprod;

        stringstream stream;

        stream << "Case #" << i+1 << ": " << setprecision(18) << seconds;

        string *result = new string( stream.str() );
        towrite.push_back(result);
    }

    writeFile(towrite);

    return 0;
}
