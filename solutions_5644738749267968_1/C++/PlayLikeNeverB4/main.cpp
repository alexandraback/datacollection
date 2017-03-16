#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 1024

int T, N;
double A[MAXN], B[MAXN];
bool used[MAXN];

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	cin >> T;
	for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> A[i];
        for(int i = 0; i < N; i++)
            cin >> B[i];
        
        sort(A, A + N);
        sort(B, B + N);
        fill(used, used + N, false);
        
        int stB = 0;
        int drB = N - 1;
        int scoreGood = 0;
        int scoreBad = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] > B[stB]) {
                scoreGood++;
                stB++;
            }
            else {
                drB--;
            }
            
            bool ok = false;
            int pmin = -1;
            for(int j = 0; j < N && !ok; j++)
                if(!used[j]) {
                    if(pmin == -1)
                        pmin = j;
                    if(B[j] > A[i]) {
                        used[j] = true;
                        ok = true;
                    }
                }
            
            if(!ok)
                scoreBad++;
            else
                used[pmin] = true;
        }
        
        cout << "Case #" << t << ": " << scoreGood << " " << scoreBad << '\n';
	}
	
	return 0;
}
