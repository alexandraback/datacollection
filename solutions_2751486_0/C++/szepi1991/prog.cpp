#include<iostream>
#include<string>
#include<vector>

using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u'};
const unsigned NVOWELS = 5;

bool isCons(char ch) {
    for (unsigned i = 0; i < NVOWELS; ++i) {
        if (ch == vowels[i]) return false;
    }
    return true;
}

int main() {
    
    unsigned cases;
    cin >> cases;
    
    for (unsigned ca = 1; ca <= cases; ++ca) {
        string name;
        unsigned nVal;
        cin >> name >> nVal;
        
        // first find for each letter the number of consecutive consonants:
        vector<unsigned> numCons;
        vector<unsigned> endOfNsub;
        unsigned con = 0, ind = 0;
        while (ind < name.length()) {
            if (isCons(name[ind]))
                con++;
            else
                con = 0;
            
            if (con >= nVal) endOfNsub.push_back(ind);

            numCons.push_back(con);
            ind++;
        }
        
//         for (vector<unsigned>::iterator it = numCons.begin(); it != numCons.end(); it++) {
//             cout << " " << (*it);
//         }
//         cout << endl;
        
        // for small case we can solve it easy in L^3
        unsigned substrings = 0;
        for (unsigned start = 0; start <= name.length()-nVal; ++start) {
            for (unsigned end = nVal; end <= name.length(); ++end) { // past last digit
//                cout << "Testing " << start << " --> " << end << endl;

                unsigned smallest = numCons[start];
                unsigned longestLenght = 0;
                for (unsigned p = start; p < end; ++p) {
                    if (numCons[p] < smallest) smallest = numCons[p];
                    
                    if (smallest == 0) longestLenght = numCons[p];
                    else longestLenght = numCons[p] - smallest + 1;
                    
                    if (longestLenght >= nVal) {
//                         cout << "Found " << start << "," << end << endl;
                        substrings++;
                        break; // from most inner loop
                    }
                }
            }
        }
        
        cout << "Case #" << ca << ": " << substrings << endl;
    }
    
    return 0;
}

