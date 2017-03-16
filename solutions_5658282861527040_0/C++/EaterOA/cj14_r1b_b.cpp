#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <cstring>

#define MIN(a,b) (a < b ? (a) : (b))
#define MAX(a,b) (a > b ? (a) : (b))

using namespace std;

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int T;
    fin >> T;
    for (int t = 1; t <= T; t++) {
        fout << "Case #" << t << ": ";
        int A, B, K;
        fin >> A >> B >> K;
        int y = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i&j) < K) y++;
            }
        }
        fout << y << "\n";
    }
}