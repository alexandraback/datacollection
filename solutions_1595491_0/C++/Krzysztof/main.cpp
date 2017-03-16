#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int maxPossible(int totalScore, bool isSurprise) {
    const int mod = totalScore % 3;

    if (isSurprise) {
        if (totalScore < 2)
            return -1;

        switch (mod) {
        case 0:
        case 1: return totalScore / 3 + 1;
        case 2: return totalScore / 3 + 2;
        }
    } else {
        switch (mod) {
        case 0: return totalScore / 3;
        case 1:
        case 2: return totalScore / 3 + 1;
        }
    }

    return -1;
}

const int MAX_N = 100;
int  scores[MAX_N];
bool surprises[MAX_N];
int N;

void printScores() {
    for (int i = 0; i < N; ++i) {
        cerr << "\t" << scores[i];
        if (surprises[i])
            cerr << "*";
    }
    cerr << endl;

    for (int i = 0; i < N; ++i) {
        cerr << "\t" << maxPossible(scores[i], surprises[i]);
    }
    cerr << endl;
}

int main() {
    //istream& is = cin;
    ifstream is("input.txt");
    //ostream& os = cout;
    ofstream os("output.txt");

    int tests;
    is >> tests;

    for (int test = 1; test <= tests; ++test) {
        int surpriseCount, p;
        is >> N >> surpriseCount >> p;

        for (int i = 0; i < N; ++i)
            is >> scores[i];

        fill(surprises, surprises + surpriseCount, true);
        fill(surprises + surpriseCount, surprises + N, false);

        int maxCount = 0;

        do {
            int count = 0;
            for (int i = 0; i < N; ++i) {
                if (maxPossible(scores[i], surprises[i]) >= p)
                    ++count;
            }

            //printScores();
            //cerr << "COUNT: " << count << endl;
            maxCount = max(maxCount, count);

        } while (prev_permutation(surprises, surprises + N));

        //cerr << "SOLUTION: " << maxCount << endl;

        os << "Case #" << test << ": " << maxCount << endl;
    }

}
