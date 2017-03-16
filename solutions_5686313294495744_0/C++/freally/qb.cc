#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> foundLefts;
vector<string> foundRights;

bool couldBeFake(string left, string right) {
    if (find(foundLefts.begin(), foundLefts.end(), left) != foundLefts.end() &&
        find(foundRights.begin(), foundRights.end(), right) != foundRights.end()) {
        return true;
    }
    foundLefts.push_back(left);
    foundRights.push_back(right);
    return false;
}

int findFakes(vector<string> left, vector<string> right) {
    int count = 0;
    for (int i = 0; i < left.size(); i++) {
        if (couldBeFake(left[i], right[i])) {
            count++;
        }
    }
    
    return count;
}

void clearWords() {
    foundLefts.clear();
    foundRights.clear();
}

void swap(string &left, string &right) {
    string temp = left;
    left = right;
    right = temp;
}

void sortLeftAndRight(vector<string> &left, vector<string> &right) {
    int n = left.size();
    while (true) {
        bool swapped = false;
        for (int i = 1; i < n-1; i++) {
            if (left[i-1] > left[i]) {
                swap(left[i-1], left[i]);
                swap(right[i-1], right[i]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

int main () {
    
    int numCases = 0;
    cin >> numCases;
    for (int i = 0; i < numCases; i++) {
        int numStrings;
        cin >> numStrings;
        clearWords();
        vector<string> left;
        vector<string> right;
        for (int j = 0; j < numStrings; j++) {
            string a, b;
            
            cin >> a;
            cin >> b;
            left.push_back(a);
            right.push_back(b);
        }
        sortLeftAndRight(left, right);
        int fakes = findFakes(left, right);

        cout << "CASE #" << (i + 1) << ": " << fakes;
        cout << endl;
    }
    
}