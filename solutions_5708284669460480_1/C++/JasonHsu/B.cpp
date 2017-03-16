#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int count(string a) {
    int c = a.size() - 1;
    while (a.substr(0, c) != a.substr(a.size() - c, c)) {
          c--;
          if (c == 0) {
             break;
          }
    }
    return c;
}

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
        printf ("Case #%d: ", __);
        int K, L, S;
        string keys, target;
        cin >> K >> L >> S;
        cin >> keys >> target;
        
        bool skip = false;
        
        map<char, int> keyset;
        map<char, int> tarset;
        map<char, double> pro;
        for (int i = 0; i < K; ++i) {
            keyset[keys[i]] += 1;
        }
        
        for (map<char, int>::iterator iter = keyset.begin(); iter != keyset.end(); ++iter) {
            pro[iter->first] = (double)iter->second / K;
        }
        
        for (int j = 0; j < L; ++j) {
            tarset[target[j]] += 1;
            if (keyset.find(target[j]) == keyset.end()) {
               printf("0.0\n");
               skip = true;
               break;
            }
        }
        
        if (skip) continue;
        if (keyset.size() == 1) {
           printf("0.0\n");
           continue;
        }
        
        double tarpro = 1;
        for (int j = 0; j < L; ++j) {
            tarpro *= pro[target[j]];
        }
        int cc = count(target);
        int base = 1 + (S - L) / (L - cc);
        
        double left = base - (S - L + 1) * tarpro;
        
        int leftround = round(left);
        if (abs(left - leftround) < 0.00000001) {
           printf("%d.0\n", leftround);
        } else {
           printf("%.7f\n", left);
        }
	}
	return 0; 
}
