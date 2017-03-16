#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

// // imin and imax show guesses for how many jumps are needed
// string bin_search(unsigned imin, unsigned imax) {
//     // continue searching while [imin,imax] is not empty
//     string seq;
//     string bestSeq(imax, "N"); // fake.. just needs to be long
//     while (imax >= imin) {
//         unsigned imid = unsigned((imax + imin)/2); // ok?
//         works = getSeq(imid, seq);
//     
//         if (works) {
//             imax = imid-1;
//             if (imid < bestSeq.length()) bestSeq = seq;
//         } else
//         // determine which subarray to search
//         if (A[imid] < key)
//             // change min index to search upper subarray
//             imin = imid + 1;
//         else if (A[imid] > key)
//             // change max index to search lower subarray
//             imax = imid - 1;
//         else
//             // key found at index imid
//             return imid;
//     }
//     // key not found
//     return KEY_NOT_FOUND;
// }

// return true iff we can get to (0,0) from (X,Y) with exactly guess jumps
// seq is used to store jumps
bool getSeq(unsigned guess, int X, int Y, string& seq) {
//    cout << guess << ": " << X << "," << Y << endl;
    if (guess == 0) {
        return (X == 0 && Y == 0);
    }
    // now we jump in largest difference direction.
    if (abs(X) > abs(Y)) {
        // decide if jump in pos or negative direction
        if (X <= 0) { // E
            seq += "E";
            return getSeq(guess-1, X+guess, Y, seq);
        } else {
            seq += "W";
            return getSeq(guess-1, X-guess, Y, seq);
        }
    } else {
        // decide if jump in pos or negative direction
        if (Y <= 0) {
            seq += "N";
            return getSeq(guess-1, X, Y+guess, seq);
        } else {
            seq += "S";
            return getSeq(guess-1, X, Y-guess, seq);
        }
    }
}

int main() {
    
    unsigned cases;
    cin >> cases;
    
    int X, Y;
    for (unsigned ca = 1; ca <= cases; ++ca) {
        // guess how long it's going to take.. then always just reduce largest distance.
        cin >> X >> Y;
        
        unsigned guess = 1;
        string seq;
        while (true) { // will always terminate because 2 * (abs(X) + abs(Y) must work
//            cout << "start" << endl;
            seq = "";
            if (getSeq(guess, X, Y, seq)) break;
//            cout << "done" << endl;
            guess++;
        }
        
        cout << "Case #" << ca << ": " << seq << endl;      
    }
    
    return 0;
}

