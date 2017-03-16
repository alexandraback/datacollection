#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;

int t, a, b, k;

int main() {
    ifstream fin("B.in");
    ofstream fout("B.out");
    fin >> t;
    for (int z = 0; z < t; z++) {
        fin >> a >> b >> k;
        long long cnt = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) cnt++;
            }
        }
        fout << "Case #" << z + 1 << ": " << cnt << endl;
    }
}
