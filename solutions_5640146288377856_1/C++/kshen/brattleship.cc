#include <iostream>
#include <stdio.h>
using namespace std;

int missrow(int columns, int width){
    return columns / width;
}

int hitrow(int columns, int width){
    int misses;
    int spacesleft;
    misses = (columns / width) - 1;
    // Reduce search space.
    spacesleft = columns - (width * misses);

    if (spacesleft == width){
        return misses + width;
    } else {
        return misses + width + 1;
    }

}

int brattleship(int caseNo){
    int row;
    int column;
    int width;
    int score = 0;
    cin >> row;
    cin >> column;
    cin >> width;

    score = (row - 1) * missrow(column, width);
    score += hitrow(column, width);
    printf("Case #%d: %d\n", caseNo, score);
}

int main(int argc, char* argv[]){
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++){
        brattleship(i);
    }
}
