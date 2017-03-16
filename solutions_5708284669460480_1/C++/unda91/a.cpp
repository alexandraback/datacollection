




#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>


using namespace std;

// Knuth Morris Pratt taken from algs4 Princeton Algorithms class

const int R = 256;
double prob[256];
//int** dfa;
int dfa[256][101];
/*
class State {
public:
    int state;
    double prob;

    State(int s, int p) {
        state = s;
        prob = t;
    }

    State() {
        state = 0;
        prob = 1;
    }
    
};
*/

void buildProbabilities(string keyboard, int K) {
    for (int i = 0; i < R; i++)
        prob[i] = 0;

    for (int i = 0; i < K; i++)
        prob[keyboard[i]] += 1;

    for(int i = 0; i < R; i++)
        prob[i] /= K;
}

double probabilityOne(string target, int L) {
    double result = 1.0;
    
    for (int i = 0; i < L; i++) {
        result *= prob[target[i]];
    }
    return result;
}

bool possible(string target, int L) {
    for (int i=0; i < L ; i++) {
        if ( prob[target[i]] < 0.00000000001) {
            return false;
        }
    }
    return true;
}

// This function was copied from
// http://algs4.cs.princeton.edu/53substring/KMP.java.html
int buildKMP(string target, int L) {
    //dfa = new int[R][L];
    
    for (int i = 0; i < R; i++)
        dfa[i][0] = 0;

    dfa[target[0]][0] = 1;
    
    int X, j;
    for (X = 0, j = 1; j < L; j++) {
        for (int c = 0; c < R; c++) 
            dfa[c][j] = dfa[c][X];     // Copy mismatch cases. 
        dfa[target[j]][j] = j+1;   // Set match case. 
        X = dfa[target[j]][X];     // Update restart state. 
    } 
    return X;
}

void cleanKMP() {
    //delete [] dfa;
}

double monkeys(int K, int L, int S, string keyboard, string target) {    
    buildProbabilities(keyboard, K);

    double result = 0;
    int reuse = buildKMP(target, L);

    double pOne = probabilityOne(target, L);

    double maxOcur = 0;
    if (possible(target, L)) {
        maxOcur = (S - reuse) / (L - reuse);
    
        int slots = max(0, S - (L-1));
        result = maxOcur - (slots * pOne);

        //printf("reuse: %d maxO: %f, pOne: %f, slots: %d\n", reuse, maxOcur, pOne, slots);
    }
    
    return result;
}


int main(int argc, char** argv) 
{

    //test();
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int K, L, S;
        string target, keyboard;

        cin >> K;
        cin >> L;
        cin >> S;
        cin >> keyboard;
        cin >> target;

        

        double result = monkeys(K, L, S, keyboard, target);


        //printf("\n\n");
        printf("Case #%d: %.7f\n", i+1, result);
    }
    

}
