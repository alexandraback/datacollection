#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

inline int getMaxScore(int score, bool surprise) {
    if (surprise)
        if (score < 2)
            return -1;
        else
            return (score + 4) / 3;
    else
        return (score + 2) / 3;
}

int main() {
    //istream& is = cin;
    ifstream is("input.txt");
    //ostream& os = cout;
    ofstream os("output.txt");

    int scores[100];

    int tests;
    is >> tests;

    for (int test = 1; test <= tests; ++test) {
        int n, surpriseCount, p;
        is >> n >> surpriseCount >> p;

        for (int i = 0; i < n; ++i)
            is >> scores[i];

        sort(scores, scores + n, greater<int>());
        int count = 0;

        // Take as many of the largest elements as qualify (non-surprises).
        // Then "promote" the next elements as surprises and go until the don't
        // qualify

        int i = 0;
        for (; i < n && getMaxScore(scores[i], false) >= p; ++i) {
            ++count;
            //cerr << scores[i] << "->" << getMaxScore(scores[i], false) << " ";
        }

        for (; i < n && surpriseCount > 0 && getMaxScore(scores[i], true) >= p; ++i) {
            ++count;
            --surpriseCount;
            //cerr << scores[i] << "*->" << getMaxScore(scores[i], true) << " ";
        }
        //cerr << endl;
        os << "Case #" << test << ": " << count << endl;
    }

}
