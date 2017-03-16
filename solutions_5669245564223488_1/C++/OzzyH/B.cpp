#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long M = 1000000007LL;

int simp1 (vector <string> & V) {
    for (int i=0; i<V.size(); i++)
        for (int j=0; j<V.size(); j++)
            if (i!=j && V[j].size() == 1)
                if (V[i][0] == V[j][0]) {
                    V.erase(V.begin() + j);
                    return 1;
                }
    return 0;
}

int simp (vector <string> & V) {
    for (int i=0; i<V.size(); i++)
        for (int j=0; j<V.size(); j++)
            if (i!=j)
                if (V[i][0] == V[j][V[j].size() - 1]) {
                    V[i] = V[j].substr(0, V[j].size()-1) + V[i];
                    if (V[i][0] == V[i][V[i].size()-1]) return -1;
                    V.erase(V.begin() + j);
                    return 1;
                }
    return 0;
}

long long fact (int c) {
    if (c==1) return 1LL;
    return ((long long)c * fact(c-1)) % M;
}

long long run_once(ifstream &fin) {
    int N; fin >> N;
    vector <string> V;
    for (int i=0; i<N; i++) {
        string s; fin >> s; V.push_back(s);
    }
    for (int i=0; i<V.size(); i++) {
        string s = V[i];
        string s2 = "";
        char l = '-';
        for (int j=0; j<V[i].length(); j++) {
            if (V[i][j] == l) continue;
            l = V[i][j];
            s2+=l;
        }
        for (int j=0; j<s2.length(); j++)
            for (int k=0; k<s2.length(); k++)
                if (j != k && s2[j] == s2[k]) return 0;
        V[i] = s2;
    }
    for (int i=0; i<V.size(); i++)
        for (int j=0; j<V.size(); j++)
            if (i != j) {
                for (int ii=1; ii<V[i].length() - 1; ii++)
                    for (int jj=0; jj<V[j].length(); jj++)
                        if (V[i][ii] == V[j][jj]) return 0;
            }
    long long ans = 1;
    sort (V.begin(), V.end());
    vector <string> V2;
    string st = "";
    int cnt = 1;
    for (int i=0; i<V.size(); i++) {
        if (V[i] == st) {
            if (V[i].length() != 1) return 0;
            cnt++;
        } else {
            ans = (ans * fact(cnt)) % M;
            st = V[i];
            V2.push_back(V[i]);
            cnt = 1;
        }
    }
    ans = (ans * fact(cnt)) % M;
    while (true) {
        int t = simp1(V2);
        if (t == 0) break;
    }

    while (true) {
        int t = simp(V2);
        if (t == -1) return 0;
        if (t == 0) break;
    }
    for (int i=0; i<V2.size(); i++)
        for (int j=0; j<V2.size(); j++)
            if (i != j) {
                for (int ii=0; ii<V2[i].length(); ii++)
                    for (int jj=0; jj<V2[j].length(); jj++)
                        if (V2[i][ii] == V2[j][jj]) return 0;
            }

    return (ans * fact(V2.size())) % M;
}

int main() {
    ifstream fin("B-large.in");
    ofstream fout("B-large.out");
    int N;
    fin >> N;
    for (int i=0; i<N; i++) {
        fout << "Case #" << i+1 << ": " << run_once(fin);
        fout << endl;
    }
    return 0;
}
