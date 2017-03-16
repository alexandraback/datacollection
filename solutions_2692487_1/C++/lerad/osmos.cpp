#include <iostream>
#include <list>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Please specify input file" << endl;
        return 1;
    }
    ifstream in(argv[1]);

    int testCases;
    in >> testCases;
    for (int testCase =0; testCase < testCases; testCase++) {
        long result = 0;
        // Read test case
        long A, N; 
        in >> A >> N;
        long motes[100];
        list<long> liMotes;
        for (int i=0; i<N; i++) {
            in >> motes[i];
            liMotes.push_back(motes[i]);
        }
        liMotes.sort();
        
        // Handle problem:
        while ((!liMotes.empty()) && (A > liMotes.front())) {
            A += liMotes.front();
            liMotes.pop_front();
        }

        long max_necessary = liMotes.size(); // Remove all
        long min_necessary = max_necessary;
        for (int i=1; i<max_necessary; i++) {
            list<long> liCopy(liMotes);
            long additional = A - 1;
            long _A = A;
            for (int j=0; j<i; j++) {
                liCopy.push_front(additional);
                liCopy.sort();
                while ((!liCopy.empty()) && (_A > liCopy.front())) {
                    _A += liCopy.front();
                    liCopy.pop_front();
                }
                additional = _A - 1;
                
            }
            if ((i+liCopy.size()) < min_necessary) {
                min_necessary = i + liCopy.size();
            }
        }
        result = min_necessary;

        cout << "Case #" << (testCase+1) << ": " << result << endl;
    } 
    
    return 0;
}
