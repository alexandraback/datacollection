#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

const string INPUT_FILE = "D-large.in";
const string OUTPUT_FILE = "output_D_large.txt";

//Optimal play for Ken is to play the smallest block he has that is larger than Naomi's block, or his smallest
//block if no such block exists.
//Optimal play for Naomi in Deceitful War is to use her smallest block to trick him into playing his largest block,
//until her smallest block is larger than his smallest block AND her largest block is larger than his largest block,
//and then play every block claiming it to be larger than his.
//Optimal play for Naomi in War - play all blocks in order from smallest to largest

int findSmallestBigger(deque<double> & kenBlocks, double toldNaomi, int first, int last) {
    if (first == last)
        return first;
    int center = (first + last) / 2;
    if (kenBlocks[center] > toldNaomi)
        return findSmallestBigger(kenBlocks, toldNaomi, first, center);
    else
        return findSmallestBigger(kenBlocks, toldNaomi, center + 1, last);
}

int kenChoice(deque<double> & kenBlocks, double toldNaomi) {
    int lastBlock = kenBlocks.size() - 1;
    if (toldNaomi > kenBlocks[lastBlock])
        return 0;
    else {
        return findSmallestBigger(kenBlocks, toldNaomi, 0, lastBlock);
    }
}

int deceitfulWar(deque<double> & naomiBlocks, deque<double> & kenBlocks) {
    int N = naomiBlocks.size();
    int naomiPoints = 0;
    for (int i = 0; i < N; i++) {
        int lastBlock = naomiBlocks.size() - 1;
        int chosenNaomi = 0;
        double toldNaomi;
        if (lastBlock == 0) {
            //no choice but to say the truth
            toldNaomi = naomiBlocks[0];
        }
        else if (naomiBlocks[lastBlock] < kenBlocks[lastBlock] || naomiBlocks[0] < kenBlocks[0]) {
            toldNaomi = (kenBlocks[lastBlock] + kenBlocks[lastBlock - 1]) / 2.0; //This represents an arbitrary number
        }                                           //between those points - otherwise Ken would catch on...
        else {
            toldNaomi = 1.0; //Represents something higher than ken's highest block.
        }
        int chosenKen = kenChoice(kenBlocks, toldNaomi);
        if (naomiBlocks[chosenNaomi] > kenBlocks[chosenKen])
            naomiPoints++;
        naomiBlocks.erase(naomiBlocks.begin() + chosenNaomi);
        kenBlocks.erase(kenBlocks.begin() + chosenKen);
    }
    return naomiPoints;
}

int war(deque<double> naomiBlocks, deque<double> kenBlocks) {
    int N = naomiBlocks.size();
    int naomiPoints = 0;
    for (int i = 0; i < N; i++) {
        int chosenKen = kenChoice(kenBlocks, naomiBlocks[0]);
        if (naomiBlocks[0] > kenBlocks[chosenKen])
            naomiPoints++;
        naomiBlocks.erase(naomiBlocks.begin());
        kenBlocks.erase(kenBlocks.begin() + chosenKen);
    }
    return naomiPoints;
}

void parseBlockWeights(ifstream & input, deque<double> & naomiBlocks, deque<double> & kenBlocks) {
    int N;
    input >> N;
    for (int i = 0; i < N; i++) {
        double weight;
        input >> weight;
        naomiBlocks.push_back(weight);
    }
    for (int i = 0; i < N; i++) {
        double weight;
        input >> weight;
        kenBlocks.push_back(weight);
    }
    sort(naomiBlocks.begin(), naomiBlocks.end());
    sort(kenBlocks.begin(), kenBlocks.end());
}

void solveAllCases(ifstream & input, ofstream & output) {
    int cases;
    input >> cases;
    cout << "Testcases to run: " << cases << endl;
    for (int i = 1; i <= cases; i++) {
        deque<double> naomiBlocks, kenBlocks;
        cerr << "Case #" << i << ": " << endl;
        parseBlockWeights(input, naomiBlocks, kenBlocks);
        output << "Case #" << i << ": ";
        output << deceitfulWar(naomiBlocks, kenBlocks) << " " << war(naomiBlocks, kenBlocks);
        output << endl;
    }
}

int main()
{
    ifstream input(INPUT_FILE.c_str(), ios::in);
    ofstream output(OUTPUT_FILE.c_str(), ios::out);
    solveAllCases(input, output);
    input.close();
    output.close();
    return 0;
}
