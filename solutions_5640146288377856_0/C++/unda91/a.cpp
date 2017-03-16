

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;



int rowSweep(int cols, int ship) {
    return cols / ship;
}

int finalHits(int cols, int ship) {
    int result = 0;
    if ((cols % ship) == 0) {
        result = ship - 1;
    } else {
        result = ship;
    }
    return result;
}

int battleship(int rows, int columns, int ship) {
    int sum = rowSweep(columns, ship) * rows;
    sum += finalHits(columns, ship);
    return sum;
}


int main(int argc, char** argv) 
{

    //test();
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R, C, W;
        cin >> R;
        cin >> C;
        cin >> W;
        
        int result = battleship(R, C, W);


        //printf("\n\n");
        printf("Case #%d: %d\n", i+1, result);
    }
    

}
