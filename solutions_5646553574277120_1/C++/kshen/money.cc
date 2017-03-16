#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int money(int caseNo){
    int coins;
    int numdenoms;
    int value;
    vector<int> olddenoms;
    cin >> coins;
    cin >> numdenoms;
    cin >> value;
    int input;
    for (int i = 0; i < numdenoms; i++){
        cin >> input;
        olddenoms.push_back(input);
    }
    int numadded = 0;
    int coverage = 0;

    //printf("Coverage: %d\n", coverage);
    for (int i = 0; i < numdenoms;){
        if (coverage >= olddenoms[i] - 1){
            coverage += olddenoms[i] * coins;
            i++;
        } else {
            int newdenom = coverage + 1;
            //cout << "Created coins of size " << newdenom << endl;
            coverage += newdenom * coins;
            numadded++;
            // Don't increment, test again.
        }

        //printf("Coverage: %d\n", coverage);
        // Reached value, no longer needs to fill in gaps.
        if (coverage >= value){
            break;
        }
    }

    // Ran out of old denoms and still can't cover value;
    while (coverage < value){
        int newdenom = coverage + 1;
        //cout << "Created coins of size " << newdenom << endl;
        coverage += newdenom * coins;
        //printf("Coverage: %d\n", coverage);
        numadded++;
    }
    printf("Case #%d: %d\n", caseNo, numadded);
}

int main(int argc, char* argv[]){
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++){
        money(i);
    }
}
