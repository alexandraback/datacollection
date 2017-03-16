#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>
#include <math.h>

using namespace std;

vector<char> convertStringToVec(string json_str) {
    vector<char> charVect(json_str.begin(), json_str.end());
    return charVect;
}

void printVec(vector<int> vec) {
    for (int i = 0; i <vec.size(); i++) {
        cout << vec[i];
    }
}

long long convertVecToInt(vector<char> num) {
    long long count = 0;
    long long power = 1;
    for (int i = num.size() - 1; i >= 0; i--) {
        count += (num[i] - '0') * power;
        power *= 10;
    }
    //printVec(num);
    //cout << count << endl;
    return count;
}

long long convertVecToNum(vector<int> number) {
    long long num = 0;
    int multiplyBy = 1;
    while (number.size() > 0) {
        num += number.back() * multiplyBy;
        multiplyBy *= 10;
        number.pop_back();
    }
    return num;
}

vector<int> convertNumToVec(long long result) {
    vector<int> number;
    while (result > 0) {
        number.push_back(result % 10);
        result /= 10;
    }
    std::reverse(number.begin(),number.end());
    return number;
}

int numQuestionMarks(vector<char> num) {
    int count = 0;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '?') {
            count++;
        }
    }
    return count;
}

void replaceQWithNum(vector<char> &num, int q) {
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '?') {
            num[i] = q + '0';
            return;
        }
    }
}

bool isValidNum(vector<char> q, long long num) {
    vector <int> numQ = convertNumToVec(num);
    while (numQ.size() != q.size()) {
        numQ.insert(numQ.begin(), 0);
    }
    for (int i = 0; i < q.size(); i++) {
        if (q[i] != '?' && (numQ[i] + '0') != q[i]) {
            //cout << numQ[i] + '0' << " is not equal to " << q[i] << endl;
            return false;
        }
    }
    //cout << num << " is valid" << endl;
    return true;
}

void findClosestScore(int caseNum, string s1, string s2) {
    vector <char> s1Vec = convertStringToVec(s1);
    vector <char> s2Vec = convertStringToVec(s2);
    
    long long minAbsolute = LLONG_MAX;
    long long bestLeft = LLONG_MAX, bestRight = LLONG_MAX;
    int s1q = numQuestionMarks(s1Vec);
    int s2q = numQuestionMarks(s2Vec);
    
    for (long long i = 0; i < pow(10, s1Vec.size()); i++) {
        for (long long j = 0; j < pow(10, s2Vec.size()); j++) {
            if (isValidNum(s1Vec, i) && isValidNum(s2Vec, j)) {
                if (abs(i - j) <= minAbsolute) {
                    if (abs(i - j) == minAbsolute) {
                        if (i < bestLeft) {
                            minAbsolute = abs(i - j);
                            bestLeft = i;
                            bestRight = j;
                        } else if (i == bestLeft) {
                            if (j < bestRight) {
                                minAbsolute = abs(i - j);
                                bestLeft = i;
                                bestRight = j;
                            }
                        }
                    } else {
                        minAbsolute = abs(i - j);
                        bestLeft = i;
                        bestRight = j;
                    }

                }
            }
        }
    }
    
    
    vector<int> bestLeftVec = convertNumToVec(bestLeft);
    vector<int> bestRightVec = convertNumToVec(bestRight);
    while (bestRightVec.size() < s1Vec.size()) {
        bestRightVec.insert(bestRightVec.begin(), 0);
    }
    while (bestLeftVec.size() < s1Vec.size()) {
        bestLeftVec.insert(bestLeftVec.begin(), 0);
    }
    cout << "CASE #" << (caseNum + 1) << ": ";
    printVec(bestLeftVec);
    cout << " ";
    printVec(bestRightVec);
    cout << endl;
    
}

int main () {
    /*
    vector<char> x;
    x.push_back('?');
    x.push_back('0');
    if (isValidNum(x, 0)) {
        cout << "IS VALID" << endl;
    } else {
        cout << "NOT VALID" << endl;
    } */
    int numCases = 0;
    cin >> numCases;
    for (int i = 0; i < numCases; i++) {
        string s, s2;
        cin >> s;
        cin >> s2;
        findClosestScore(i, s, s2);
        
        //cout << "CASE #" << (i + 1) << ": " << fakes;
        //cout << endl;
    }
    
}