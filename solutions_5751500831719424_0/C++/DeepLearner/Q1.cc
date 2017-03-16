
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


// given a string, return its skeleton and frequency
string skeleton(string s, vector<int> &freq) {
    const int N = s.size();
    stringstream ss;
    int i = 0;
    while (i < N) {
        char a = s[i];
        int count = 0;
        do {
            i++;
            count++;
        } while (i < N && s[i] == a);
        ss << a;
        freq.push_back(count);
    }
    return ss.str();
}

// given a vector of int, find the minimum operations to convert all numbers to be identical
int minOpts(vector<int> &num) {
    sort(num.begin(), num.end());
    int median = 0;
    const int N = num.size();
    if (N%2 == 1) median = num[N/2];
    else median = (int)round((num[N/2-1]+num[N/2])/2.0);

    int dist = 0;
    for (int i = 0; i < N; i++) dist += abs(num[i]-median);
    
    return dist;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Need input file!" << endl;
        return 1;
    }
    ifstream input(argv[1]); // bind and open the input file
    // check whether open sucessfully
    if (!input) {
        cerr << "unable to open the input file!" << endl;
        return 1;
    }
    
    int T; // number of cases
    input >> T;
    input.ignore(256, '\n'); // ignore the rest of the line
    
    // consider each case
    for (int i = 1; i <= T; i++) {
        int N; // number of strings
        input >> N;
        input.ignore(256, '\n'); //ignore the rest of the line
        vector<vector<int> > freqs; // frequency for each line
        if (N == 0) continue;
        // get the first line
        string target;
        getline(input, target);
        vector<int> oneFreq;
        target = skeleton(target, oneFreq);
        freqs.push_back(oneFreq);
        // get the rest of lines
        for (int j = 2; j <= N; j++) {
            // get each line
            oneFreq.clear();
            string line;
            getline(input, line);
            if (target == skeleton(line, oneFreq)) freqs.push_back(oneFreq);
            else break;
        }
        if (freqs.size() != N) cout << "Case #" << i << ": Fegla Won" << endl;
        else { // need to calculate the min operations
            int totalDist = 0; // total operations
            // consider each character
            for (int j = 0; j < target.size(); j++) {
                vector<int> num(N, 0);
                for (int i = 0; i < N; i++) num[i] = freqs[i][j];
                totalDist += minOpts(num);
            }
            cout << "Case #" << i << ": " << totalDist << endl;
        }
    }
    
    input.close(); // close file before return
    
    return 0;
}