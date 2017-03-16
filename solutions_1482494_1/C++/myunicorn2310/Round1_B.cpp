#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAXN = 10000;
int n;
int level[MAXN][3];
int completed[MAXN];
int stars;
int completedLevels;

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int ntests;
    cin >> ntests;    
    for (int test = 1; test <= ntests; test++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> level[i][1] >> level[i][2];
            completed[i] = 0;
        }
        completedLevels = n;
        int timeNeeded = 0;
        stars = 0;
        while (completedLevels > 0) {
            bool progressed = false;
            for (int i = 0; i < n; i++) {
                if (completed[i] < 2 && stars >= level[i][2]) {
                    stars += 2 - completed[i];
                    completed[i] = 2;
                    completedLevels--;
                    timeNeeded++;
                    progressed = true;
                }
            }
            if (progressed) continue;
            int maxLevel2 = -1;
            int maxLevel2Index = -1;
            for (int i = 0; i < n; i++) {
                if (completed[i] == 0 && stars >= level[i][1]) {
                    if (level[i][2] > maxLevel2) {
                        maxLevel2 = level[i][2];
                        maxLevel2Index = i;
                    }
                }
            }
            if (maxLevel2 > -1) {
                completed[maxLevel2Index] = 1;
                timeNeeded++;
                stars++;                
            } else {
                break;
            }
        }
        if (completedLevels > 0) {
            printf("Case #%d: Too Bad\n",test);
        } else {
            printf("Case #%d: %d\n",test,timeNeeded);
        }
    }
}