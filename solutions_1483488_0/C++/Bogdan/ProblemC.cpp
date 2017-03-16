#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;

int test(const vector<int> digits, const unsigned int permIndex,
         const unsigned int A, const unsigned int B, const unsigned int current) {
    assert(permIndex < digits.size()); //permIndex == 0 means original number, permIndex == 1 means original number with first digit shifted and so on
    unsigned int value = 0;

    for (unsigned int i=permIndex;i<digits.size();++i) value = value*10 + digits[i];
    for (unsigned int i=0;i<permIndex;++i) value = value*10 + digits[i];

    if (value >= A) {
        if (value < current) return 1;
        else if (value == current) return 3;
        else if (value <= B) return 2;
        else return 0;
    } else return 0;
}

unsigned int vecToValue(const vector<int> digits, const unsigned int permIndex) {
    assert(permIndex < digits.size()); //permIndex == 0 means original number, permIndex == 1 means original number with first digit shifted and so on
    unsigned int value = 0;

    for (unsigned int i=permIndex;i<digits.size();++i) value = value*10 + digits[i];
    for (unsigned int i=0;i<permIndex;++i) value = value*10 + digits[i];
    return value;
}

vector<int> numberToVec(const unsigned int number) {
    vector<int> result;
    unsigned int n = number;
    while (n>0) {
        result.push_back(n%10);
        n /= 10;
    }
    reverse(result.begin(),result.end());

    return result;
}

void mainC() {
    unsigned int T,A,B;
    unsigned int currentValue,maxFirstDigit,minFirstDigit;
    vector<int> currentVec;
    unsigned int nPairs;

    cin >> T;
    for (unsigned int i=0;i<T;++i) {
        cin >> A >> B;
        currentVec = numberToVec(A);
        currentValue = A;
        maxFirstDigit = numberToVec(B)[0];
        minFirstDigit = currentVec[0];

        nPairs = 0;
        if (A < B) {
            for (;currentVec[0]<=(int)maxFirstDigit;++currentVec[0]) {
                if (currentVec.size() > 1) {
                    unsigned int k = 1;
                    currentVec[k] = -1;
                    while (k>0) {
                        if (currentVec[k] < (int)minFirstDigit) ++currentVec[k];
                        else if (currentVec[k] >= currentVec[0] && currentVec[k] < 9) ++currentVec[k];
                        else if (currentVec[k] == (int)minFirstDigit) currentVec[k] = currentVec[0];
                        else {
                            --k;
                            continue;
                        }
                        if (k == currentVec.size()-1) {
                            currentValue = vecToValue(currentVec,0);
                            if (currentValue <= B && currentValue >=A) {
                                unsigned int nValidPermutations = 1;
                                for (unsigned int i=1;i<currentVec.size();++i) {
                                    unsigned int aux = test(currentVec,i,A,B,currentValue);
                                    if (aux == 1) {
                                        nValidPermutations = 1;
                                        break;
                                    } else if (aux == 2) {
                                        ++nValidPermutations;
                                    } else if (aux == 3) {
                                        break;
                                    }
                                }
                                nPairs += nValidPermutations*(nValidPermutations-1)/2;
                            }
                        } else {
                            ++k;
                            currentVec[k] = -1;
                        }
                    }
                }
            }
        }

        cout << "Case #" << (i+1) << ": " << nPairs << endl;
    }
}
