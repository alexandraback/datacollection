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
//        cout << name << " " << nVal << endl;
        
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
        
        // for large.. we'll do <= L * endOfNsub.length..
        unsigned substrings = 0;
        unsigned inEnds = 0;
        if (endOfNsub.size() != 0) {
            for (unsigned start = 0; start <= name.length()-nVal; ++start) {
                // find how far the substring needs to go at least so that it's good
                while (endOfNsub[inEnds] < start+nVal-1) { // check!!!!
                    inEnds++;
                    if (inEnds >= endOfNsub.size()) break;
                }
                if (inEnds >= endOfNsub.size()) break;

                substrings += name.length() - endOfNsub[inEnds]; // check one off things
                
//                 cout << "start=" << start << "end=" << endOfNsub[inEnds] 
//                         << ", so ways=" << name.length() - endOfNsub[inEnds] << endl;
                
                // FOR NOW WE DON'T DEAL WITH THE CASE WHERE START IS index 1 IN 'bcd', n = 3 ?
            }
        }
        
                
        cout << "Case #" << ca << ": " << substrings << endl;
    }
    
    return 0;
}

