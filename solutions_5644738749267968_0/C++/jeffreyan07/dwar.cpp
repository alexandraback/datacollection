#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const double EPSILON = 0.0000001;

struct testcase {
    int n;
    vector<double> naomi;
    vector<double> ken;
};

vector<testcase*> cases;

bool readFile();
void writeFile(vector<string*> towrite);
void sort(vector<double> &v, int left, int right, bool ascend);
int partition(vector<double> &v, int lefti, int righti, int pivoti, bool ascend);
void swap(vector<double> &v, int firstindex, int secondindex);

bool strictGE(vector<double> &n, vector<double> &k) {
    for(int i = 0; i < n.size(); i++) {
        if(n[i] < k[i])
            return false;
    }
    return true;
}

// simulates a game of deceitful war and returns number of rounds naomi won
int dwar(testcase *tc) {
    int trials = tc->n;
    vector<double> nblocks = vector<double> (tc->naomi);
    vector<double> kblocks = vector<double> (tc->ken);

    sort(nblocks, 0, trials-1, true);
    sort(kblocks, 0, trials-1, true);

    while(!strictGE(nblocks, kblocks)) {
        nblocks.erase(nblocks.begin());
        kblocks.erase(kblocks.end()-1);
    }

    return nblocks.size();
}

// simulates a game of war and returns number of rounds naomi won
int war(testcase *tc) {
    int trials = tc->n;
    vector<double> nblocks = tc->naomi;
    vector<double> kblocks = tc->ken;
    int wins = 0;

    sort(nblocks, 0, trials-1, true);
    sort(kblocks, 0, trials-1, true);

    for(int i = 0; i < trials; i++) {
        double nplay = nblocks[i];
        int j;
        bool found = false;
        for(j = 0; j < kblocks.size(); j++) {
            if(kblocks[j] > nplay) {
                found = true;
                break;
            }
        }
        if(found)
            kblocks.erase(kblocks.begin() + j);
        else {
            kblocks.erase(kblocks.begin());
            wins++;
        }
    }

    return wins;
}

int main(int argc, char **argv) {
    readFile();

    vector<string*> towrite;

    for(int i = 0; i < cases.size(); i++) {
        testcase *tc = cases[i];

        int deceit = dwar(tc);
        int fair = war(tc);

        stringstream stream;

        stream << "Case #" << i+1 << ": " << deceit << " " << fair;

        string *result = new string( stream.str() );
        towrite.push_back(result);
    }

    writeFile(towrite);

    return 0;
}


//-------------------------------Helper Functions-------------------------------


void sort(vector<double> &v, int left, int right, bool ascend) {
    if(left < right) {
        int pivotindex = left;

        int newpivotindex = partition(v, left, right, pivotindex, ascend);

        sort(v, left, newpivotindex - 1, ascend);
        sort(v, newpivotindex + 1, right, ascend);
    }
}

int partition(vector<double> &v, int lefti, int righti, int pivoti, bool ascend) {
    double pivot = v[pivoti];
    swap(v, pivoti, righti);

    int tempindex = lefti;

    for(int i = lefti; i < righti; i++) {
        if(ascend ? (v[i] < pivot) : (v[i] > pivot)) {
            swap(v, i, tempindex);
            tempindex++;
        }
    }

    swap(v, tempindex, righti);
    return tempindex;
}

void swap(vector<double> &v, int firstindex, int secondindex) {
    double temp = v[firstindex];
    v[firstindex] = v[secondindex];
    v[secondindex] = temp;
}

bool readFile() {
    std::string line;
    std::ifstream cfile("dwar.in");

    if(cfile.is_open()) {
        getline(cfile, line);
        int num = std::stoi(line);
        for(int i = 0; i < num; i++) {
            getline(cfile, line);
            testcase *loaded = new testcase();
            std::string::size_type sz = 0;
            loaded->n = std::stoi(line);

            getline(cfile, line);
            for(int j = 0; j < loaded->n; j++) {
                loaded->naomi.push_back(std::stod(line, &sz));
                line = line.substr(sz);
            }

            getline(cfile, line);
            for(int j = 0; j < loaded->n; j++) {
                loaded->ken.push_back(std::stod(line, &sz));
                line = line.substr(sz);
            }

            cases.push_back(loaded);
        }
        cfile.close();
    }
    else return false;

    return true;
}

void writeFile(vector<string*> towrite) {
    ofstream out;
    out.open("dwar.out");
    for(unsigned int i = 0; i < towrite.size(); i++) {
        out << *towrite[i] << endl;
    }
    out.close();
}
