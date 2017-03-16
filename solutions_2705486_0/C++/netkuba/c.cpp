#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

typedef map< string, vector<string> > dict;

const int infty = 10000;
const int M = 4010;
const int N = 5;

dict miss[N];
dict full;

void dict_insert(dict & d, string key, string val) {
    dict::iterator it = d.find(key);
    if (it == d.end()) {
        d[key] = vector<string>();
    }
    d[key].push_back(val);
}

void procEntry(string entry) {
    int len = min(N, (int)entry.length());
    char * pref = new char[len+1];
    pref[len] = 0;
    for (int i=0; i<len; ++i) {
        pref[i] = entry[i];
    }
    dict_insert(full, string(pref), entry);
    for (int i=0; i<len; ++i) {
        pref[i] = '#';
        dict_insert(miss[i], string(pref), entry);
        pref[i] = entry[i];
    }
    delete[] pref;
}

void prep() {
    ifstream infile("garbled_email_dictionary.txt");
    string entry;
    while (getline(infile, entry)) {
        procEntry(entry);
    }
}

int t[M][N];

void fit(string msg, string word, int pos, int last, int miss) {
    if (pos + word.length() > msg.length()) return;
    for (int i=0; i<word.length(); ++i) {
        if (word[i] != msg[pos+i]) {
            if (i - last < N) return;
            last = i;
            ++miss;
        }
    }
    last = max(last - (int)word.length() + N, 0);
    if (miss < t[pos+word.length()][last]) {
        t[pos+word.length()][last] = miss;
//        printf("Putting %s at %d\n", word.c_str(), pos);
    }
}

int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);
    string msg;
    cin >> msg;
    
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            t[i][j] = infty;
        }
    }
    t[0][0] = 0;
    for (int i=0; i<msg.length(); ++i) {
        for (int j=0; j<N; ++j) {
            if (t[i][j] < infty) {
                for (int k=1; k<=min(N, (int)msg.length()-i); ++k) {
                    char * pref = new char[k+1];
                    pref[k] = 0;
                    for (int l = 0; l < k; ++l) {
                        pref[l] = msg[i+l];
                    }
                    
                    dict::iterator it = full.find(string(pref));
                    if (it != full.end()) {
                        for (int p=0; p<it->second.size(); ++p) {
                            fit(msg, it->second[p], i, -N+j, t[i][j]);
                        }
                    }

                    for (int l=j; l<k; ++l) {
                        pref[l] = '#';

                        it = miss[l].find(string(pref));
                        if (it != miss[l].end()) {
                            for (int p=0; p<it->second.size(); ++p) {
                                fit(msg, it->second[p], i, -N+j, t[i][j]);
                            }
                        }
                        pref[l] = msg[i+l];
                    }


                    delete[] pref;
                }
            }
        }
    }
/*
    for (int i=0; i<=msg.size(); ++i) {
        for (int j=0; j<N; ++j) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
*/
    int result = infty;
    for (int i=0; i<N; ++i) {
        result = min(result, t[msg.length()][i]);
    }
    printf("%d\n", result);
}

int main() {
    prep();
//    printf("PREP DONE!\n");
    int t; scanf("%d", &t);
    while(t--) make();
    return 0;
}
