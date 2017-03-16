#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

void syntax(char** argv) {
    printf("Syntax: %s <filename>\n", argv[0]);
}

typedef vector<double> weights;

int get_opt_result(const weights& nw, const weights& kw) {
    int score=0;
    weights kw1(kw);
    for (int i=0; i<nw.size() ; ++i) {
        bool ken_scored=false;
        for (int j=0; j<kw1.size(); ++j) {
            if (kw1[j] > nw[i]) {
                kw1.erase(kw1.begin() + j);
                ken_scored=true;
                break;
            }
        }
        if (!ken_scored) {
            ++score; 
        }
    }
    return score;
}

int get_dct_result(const weights& nw, const weights& kw) {
    weights nw1(nw);
    weights kw1(kw);
    int score = 0;
    while (!nw1.empty()) {
        int last_id=nw1.size()-1;
        if (nw1[last_id] > kw1[last_id]) {
            ++score; 
            nw1.erase(nw1.begin() + last_id);
            kw1.erase(kw1.begin() + last_id);
        } else {
            nw1.erase(nw1.begin());    
            kw1.erase(kw1.begin() + last_id);
        }
    }
    return score;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        syntax(argv);
        return 1;
    }
    ifstream in;
    in.open(argv[1], ios::in);
    if (!in) {
        cerr << "Could not open file " << argv[1] << endl;
        return 1;
    }
    int numTestCases;
    in >> numTestCases;
    for (int i=0; i<numTestCases; ++i) {
        int num_blocks;
        in >> num_blocks;
        weights nweights, kweights;
        double weight;
        for (int j=0; j<num_blocks; ++j) {
            in >> weight;
            nweights.push_back(weight);
        }
        for (int j=0; j<num_blocks; ++j) {
            in >> weight;
            kweights.push_back(weight);
        }
        sort(nweights.begin(), nweights.end());
        sort(kweights.begin(), kweights.end());
        cout << "Case #" << i+1 << ": " << get_dct_result(nweights, kweights) << " " << get_opt_result(nweights, kweights) << endl;
    }
    in.close();
    return 0;
}
