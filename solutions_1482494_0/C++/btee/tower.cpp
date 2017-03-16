#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <functional>
#include <vector>

#include <iostream>

using namespace std;

int solve(const vector<int>& aS1,const vector<int>& aS2) {
    int moves = 0;

    vector<short> starsGot(aS1.size(), 0);
    int stars = 0;
    
    bool moveFound = true;
    while(moveFound) {
        while(moveFound) {
            moveFound = false;
            for(int i=0; i<aS2.size(); ++i) {
                if( starsGot[i] < 2 && aS2[i] <= stars) {
                    stars += 2-starsGot[i];
                    starsGot[i] = 2;
                    clog << "move2 " << i << endl;
                    ++moves;
                    moveFound = true;
                }
            }
        }
        moveFound = false;
        for(int i=0; i<aS1.size(); ++i) {
            if( starsGot[i] < 1 && aS1[i] <= stars) {
                starsGot[i] = 1;
                stars += 1;
                clog << "move1 " << i << endl;
                ++moves;
                moveFound = true;
                break;
            }
        }
    }
    clog << "#found: " << stars << endl;
    return stars == 2*aS1.size() ? moves : -1;
}

int main(){

    int cases;
    cin >> cases;

    for(int i=0; i<cases; ++i) {
        int a;
        cin >> a;
        vector<int> star1(a);
        vector<int> star2(a);
        
        for(int j=0;j<a;++j){
            cin >> star1[j] >> star2[j];
        }
        int ret = solve(star1, star2);
        
        if(ret>=0) {
            cout << "Case #"<< (i+1) <<": "<< ret << endl;
        } else {
            cout << "Case #"<< (i+1) <<": Too Bad"<< endl;
        }
    }
    return 0;
}
