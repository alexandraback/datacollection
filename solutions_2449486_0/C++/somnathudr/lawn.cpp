#include <iostream>
#include <string>
 
 
using namespace std;
 
bool checkGrid(int** lawn, int height, int width) {
    for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++) {
            bool row_valid = true;
            bool col_valid = true;
            // check column heights
            for(int r = 0; r < height; r ++) {
                if (lawn[r][j] > lawn[i][j]) {
                    col_valid = false;
                    break;
                }
            }
            if (col_valid == true) {
                continue;
            } else {
                for(int r = 0; r < width; r ++) {
                    if (lawn[i][r] > lawn[i][j]) {
                        row_valid = false;
                        break;
                    }
                }
                if (row_valid == false) {
                    return false;
                }
            }
        }
    }
    
    return true;
}
 
int main(int argc, const char * argv[])
{
    int cases = 0;
    std::cin >> cases;
    for(int run = 1; run <= cases; run ++) {
        int height = 0, width = 0;
        std::cin >> height;
        std::cin >> width;
        int **lawn = new int*[height];
        for(int i = 0; i < height; i ++) {
            lawn[i] = new int[width];
            for(int j = 0; j < width; j ++) {
                std::cin >> lawn[i][j];
            }
        }
        
        if (checkGrid(lawn, height, width)) {
            std::cout << "Case #" << run << ": YES" << std::endl;
        } else {
            std::cout << "Case #" << run << ": NO" << std::endl;
        }
        // release memory
        for(int i = 0; i < height; i ++) {
            delete(lawn[i]);
        }
        delete(lawn);
    }
    return 0;
}
