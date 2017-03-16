// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: 

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const int CENTER = 10000;

using namespace std;

#define D(x) 

double probability(vector<int>& heights, int X, int Y, int remaining);

double tryPath(vector<int>& heights, int X, int Y, int remaining, int x, int y) {
    int temp = heights[x];
    heights[x] = y;
    double prob = probability(heights, X, Y, remaining);
    heights[x] = temp;
    return prob;
}


double probability(vector<int>& heights, int X, int Y, int remaining) {
    if (remaining == 0) {
        return (heights[X] >= Y) ? 1.0 : 0.0;
    }

    int x = CENTER;
    int y = max(heights[x]+2, max(heights[x-1]+1, heights[x+1]+1));
    bool slideLeft = y > heights[x-1]+1 && y>0;
    bool slideRight = y > heights[x+1]+1 && y>0;

    double totalProb = 0.0, ways = 0.0;
    if (slideLeft) {
        int x_ = x, y_ = y;
        while (y_ > heights[x_-1]+1 && y_>0) {
            x_--;
            y_--;
        }
        totalProb += tryPath(heights, X, Y, remaining-1, x_, y_);
        ways += 1;
    }
    if (slideRight) {
        int x_ = x, y_ = y;
        while (y_ > heights[x_+1]+1 && y_>0) {
            x_++;
            y_--;
        }
        totalProb += tryPath(heights, X, Y, remaining-1, x_, y_);
        ways += 1;
    }
    if (!slideLeft && !slideRight) {
        totalProb += tryPath(heights, X, Y, remaining-1, x, y);
        ways += 1;
    }

    return totalProb / ways;
}

int main() {
    int T;
    cin >> T;
    
    vector<int> heights(2*CENTER+1, -2);

    for (int testCase = 1; testCase <= T; testCase++) {
        int N, X, Y;
        cin >> N >> X >> Y;

        double p = probability(heights, X+CENTER, Y, N);
        cout << "Case #" << testCase << ": ";
        cout << p;
        cout << endl;
    }
}
