/* 
 * File:   main.cpp
 * Author: tamer
 *
 * Created on April 13, 2013, 2:03 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
typedef std::pair<int, int > mypair;

bool comparator(const mypair& l, const mypair& r) {
    return l.first > r.first;
}

void solve(long long A, vector<long> &v, int idx, int &ans) {

    long long accA = A, tmpA;
    long cnt = 0;
    int tmpAns = 0;
    ans = 0;

    int i = idx;
    for (; i < v.size(); i++) {
        if (accA > v[i])
            accA += v[i];
        else
            break;
    }

    if (i < v.size()) {

        if (accA - 1 <= 0) {
            ans = v.size() - i;
        } else {
            //assume addition
            tmpA = accA;
            int cnt = 0;
            for (; cnt < v.size() - i;) {
                tmpA += tmpA - 1;
                cnt++;
                if (tmpA > v[i])
                    break;
            }
            solve(tmpA, v, i, tmpAns);
            ans = cnt + tmpAns < v.size() - i ? cnt + tmpAns : v.size() - i;
        }


    }
}

int main(int argc, char** argv) {

    long A, entry;

    int ans = 0, N, T;
    char ch;

    char str [80];
    FILE * pFile;
    FILE * oFile;

    pFile = fopen("/Users/tamer/Desktop/A-small-attempt0.in", "r");
    oFile = fopen("/Users/tamer/Desktop/out.txt", "w+");
    fscanf(pFile, "%d\n", &T);

    for (int t = 1; t <= T; t++) {

        fscanf(pFile, "%ld %d\n", &A, &N);
        vector<long> v(N, 0);
        for (int n = 0; n < N; n++) {
            fscanf(pFile, "%ld", &v[n]);
        }
//        for (int i = 0; i < N; i++) {
//            cout << v[i] << " ";
//        }
//        cout << endl;

        sort(v.begin(), v.end());
        solve(A, v, 0, ans);
//        cout << "ans: " << ans << endl;
        fprintf(oFile, "Case #%d: %d", t, ans);
        if (t != T)
            fprintf(oFile, "\n");
    }

    fclose(oFile);
    fclose(pFile);
    return 0;
}
