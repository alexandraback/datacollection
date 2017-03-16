#include <iostream>

bool map[50][50];

void outputLine(bool vertical, int free, int mines) {
    std::string sep = vertical ? "\n" : "";
    
    std::cout << 'c';
    for(int i = 0; i < free - 1; ++i) std::cout << sep << '.';
    for(int i = 0; i < mines; ++i) std::cout << sep << '*';
    std::cout << std::endl;
}

void outputOne(int rows, int cols, bool m) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(i == 0 && j == 0) std::cout << 'c';
            else std::cout << (m ? '.' : '*');
        }
        std::cout << std::endl;
    }
}

void output(int rows, int cols, int free) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            map[i][j] = false;
        }
    }

    int left = free - 4;
    map[0][0] = map[0][1] = map[1][0] = map[1][1] = true;
    if(free == 7) {
        map[2][1] = map[2][2] = map[1][2] = true;
    } else if(free == 6) {
        if(rows >= 3) map[2][0] = map[2][1] = true;
        else map[0][2] = map[1][2] = true;
    } else if(free != 4) {
        map[2][0] = map[0][2] = map[2][1] = map[1][2] = true;
        left -= 4;
        if(free % 2 == 1) {
            map[2][2] = true;
            left--;
        }
        //std::cout << "-> " << left << std::endl;
        int i = 3;
        while(left && i < cols) {
            map[0][i] = map[1][i] = true;
            left -= 2;
            i++;
        }
        //std::cout << "-> " << left << std::endl;
        i = 3;
        while(left && i < rows) {
            map[i][0] = map[i][1] = true;
            left -= 2;
            i++;
        }
        //std::cout << "-> " << left << std::endl;
        if(left) {
            for(int i = 2; i < rows; ++i) {
                for(int j = 2; j < cols; ++j) {
                    if(map[i][j]) continue;
                    map[i][j] = true;
                    left--;
                    if(!left) break;
                }
                if(!left) break;
            }
        }
    }
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(!i && !j) std::cout << 'c';
            else std::cout << (map[i][j] ? '.' : '*');
        }
        std::cout << std::endl;
    }
}

void output2(int rows, int cols, int free) {
    int line = free / 2;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(!i && !j) std::cout << 'c';
            else if(cols == 2) {
                if(i >= line) std::cout << '*';
                else std::cout << '.';
            } else {
                if(j >= line) std::cout << '*';
                else std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
}

void impossible() {
    std::cout << "Impossible" << std::endl;
}

int main() {
    int size;
    std::cin >> size;

    for(int i = 0; i < size; ++i) {
        int R, C, M;
        std::cin >> R >> C >> M;

        int free = R * C - M;

        std::cout << "Case #" << i + 1 << ":\n";

        if(free == 1 || M == 0) {
            outputOne(R, C, M == 0);
        } else if(free == 4) {
            if(R >= 2 && C >= 2) output(R, C, free);
            else if(R == 1 || C == 1) outputLine(C == 1, free, M);
            else impossible();
        } else if(free < 4 || free == 5 || free == 7) {
            if(R == 1 || C == 1) outputLine(C == 1, free, M);
            else impossible();
        } else if(free == 6) {
            if(R >= 3 || C >= 3) output(R, C, free);
            else if(R == 1 || C == 1) outputLine(C == 1, free, M);
            else if(R == 2 || C == 2) output2(R, C, free);
            else impossible();
        } else if((R == 2 || C == 2) && free % 2 == 0) {
            output2(R, C, free);
        } else if(R >= 3 && C >= 3) {
            output(R, C, free);
        } else {
            if(R == 1 || C == 1) outputLine(C == 1, free, M);
            else impossible();
        }
        
    }
}
