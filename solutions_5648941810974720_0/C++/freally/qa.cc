#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<char> convertStringToVec(string json_str) {
    vector<char> charVect(json_str.begin(), json_str.end());
    return charVect;
}

void printVec(vector<char> vec) {
    for (int i = 0; i <vec.size(); i++) {
        //cout << vec[i];
    }
    //cout << endl;
}

bool searchForString(vector<char> &orig,  vector<char> num) {
    vector<char> numDupe = num;
    for (int i = 0; i < orig.size(); i++) {
        for (int j = 0; j < numDupe.size(); j++) {
            if (orig[i] == numDupe[j]) {
                numDupe.erase(numDupe.begin() + j);
                break;
            }
        }
        if (numDupe.size() == 0) break;
    }
    if (numDupe.size() == 0) {
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < orig.size(); j++) {
                if (num[i] == orig[j]) {
                    orig.erase(orig.begin() + j);
                    break;
                }
            }
        }
        return true;
    }
    return false;
}


vector<int> getNumsForString(string s) {
    vector <string> stringOrder;
    stringOrder.push_back("SIX");
    stringOrder.push_back("ZERO");
    stringOrder.push_back("SEVEN");
    stringOrder.push_back("FIVE");
    stringOrder.push_back("FOUR");
    stringOrder.push_back("EIGHT");
    stringOrder.push_back("TWO");
    stringOrder.push_back("ONE");
    stringOrder.push_back("NINE");
    stringOrder.push_back("THREE");
    
    vector <int> numOrder;
    numOrder.push_back(6);
    numOrder.push_back(0);
    numOrder.push_back(7);
    numOrder.push_back(5);
    numOrder.push_back(4);
    numOrder.push_back(8);
    numOrder.push_back(2);
    numOrder.push_back(1);
    numOrder.push_back(9);
    numOrder.push_back(3);
    int count = 0;
    
    vector<char> orig = convertStringToVec(s);
    vector<int> result;
    while (orig.size() > 0 && count < numOrder.size()) {
        vector<char> num = convertStringToVec(stringOrder[count]);
        if (searchForString(orig, num)) {
            result.push_back(numOrder[count]);
        } else {
            count++;
        }
        printVec(orig);
    }
    
    return result;
}

struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
    
    int numCases = 0;
    cin >> numCases;
    for (int i = 0; i < numCases; i++) {
        string j;
        
        cin >> j;
        vector<int> nums = getNumsForString(j);
        sort(nums.begin(), nums.end(), myobject);
        cout << "CASE #" << (i + 1) << ": ";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
        }
        cout << endl;
    }
    
}