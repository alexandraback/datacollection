#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int testcases;
    FILE *fin;
    fin = fopen("B.in", "r");
    FILE *fout;
    fout = fopen("B.out", "w");
    fscanf(fin, "%d", &testcases);
    for (int tc=0; tc<testcases; ++tc) {
        cout << "==========" << endl;
        int N, S, P, tmp;
        vector<int> sums;
        sums.clear();
        fscanf(fin, "%d%d%d", &N, &S, &P);
        for (int i=0; i<N; ++i) {
            fscanf(fin, "%d", &tmp);
            sums.push_back(tmp);
        }
        sort(sums.begin(), sums.end());
        int size = sums.size();
        int ans = 0;
        int level1 = max(P * 3 - 2, 0);
        int level2 = max(P * 3 - 4, 0);
        for (int i=size-1; i>=0; --i) {
            if (sums[i] < P) continue;
            if (level1 <= sums[i]) {
                ++ans;
                cout << "found " << sums[i] << endl;
            } else if (S > 0 && level2 <= sums[i]) {
                ++ans;
                --S;
                cout << "sur " << sums[i] << endl;
            }
        }
        fprintf(fout, "Case #%d: %d\n", tc+1, ans);
    }
    
    return 0;
}