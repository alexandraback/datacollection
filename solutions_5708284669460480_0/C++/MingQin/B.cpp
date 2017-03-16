/*
 * File:   main.cpp
 * Author: Ming Qin
 *
 * Created on February 27, 2015, 8:37 PM
 */

 //#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void assert(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}
unordered_map<char, double> getKeyboard(string strk) {
    unordered_map<char, double> keys;
    for (auto c : strk) {
        if (keys.count(c) == 0) {
            keys[c] = 1.0;
        } else {
            keys[c] ++;
        }
    }
    for (auto &pair : keys) {
        pair.second /= double(strk.size());
    }
    return keys;
}

int countOcc(string str, string tar) {
    int count = 0;
    int szTar = tar.size();
    for (int i = 0; i <= str.size() - szTar; ++i) {
        if (str.substr(i, szTar) == tar) {
            ++count;
        }
    }
    return count;
}

string target;
vector<int> bana;
vector<double> probs;
unordered_map<char, double> keys;

void search(string &str, double prob, int s) {
    if (str.size() == s) {
        bana.push_back(countOcc(str, target));
        probs.push_back(prob);
        return;
    }
    for (auto &pair : keys) {
        str.push_back(pair.first);
        search(str, prob*pair.second, s);
        str.pop_back();
    }
}

double solve(string strk, string strl, int s) {
    target = strl;
    keys.clear();
    bana.clear();
    probs.clear();
    keys = getKeyboard(strk);
    string strsearch;
    search(strsearch, 1, s);

    int maxBana = 0;
    double expect = 0;
    for (int i = 0; i < bana.size(); ++i) {
        if (bana[i] > maxBana) {
            maxBana = bana[i];
        }
        expect += probs[i] * bana[i];
    }
    cout << maxBana << expect<<endl;
    return maxBana - expect;
}

int main() {
    long long nCase;
    fstream fin("1.in");
    ofstream fout("out.txt");
    fout.precision(7);

    int k, l, s;
    string strk,strl;

    fin >> nCase;
    for (long long  caseID = 1; caseID <= nCase; ++caseID) {
        fin >> k >> l >> s >> strk >> strl;
        assert(strk.size() == k);
        assert(strl.size() == l);
        fout << "Case #" << caseID << ": " << solve(strk,strl,s) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
