#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main(){
    int tests;
    cin >> tests;
    for(int i1 = 0; i1 < tests; i1++){
        int m, r, c;
        cin >> r >> c >> m;
        cerr << r << " " << c << " " << m << endl;
        cout << "Case #" << i1 + 1 << ":" << endl;
        vector<vector<char> > field;
        field.resize(r);
        for(auto &row : field)
            row.resize(c);
        for(auto &it1 : field)
        for(auto &it2 : it1)
            it2 = '*';
        int nonMines = r * c - m;
        switch(r){
            case 1:
                for(int i2 = 0; i2 < nonMines; i2++){
                    field[0][i2] = '.';
                }
                break;
            case 2:
                if(nonMines == 1){
                }else if(nonMines == 2){
                    if(m == 0){
                        field[0][0] = '.'; field[1][0] = '.';
                    }else{
                        cout << "Impossible" << endl;
                        continue;
                    }
                }else if(nonMines % 2){
                    cout << "Impossible" << endl;
                    continue;
                }else{
                    for(int i2 = 0; i2 < nonMines/2; i2++){
                        field[0][i2] = '.';
                        field[1][i2] = '.';
                    }
                }
                break;
            default:
                switch(c){
                    case 1:
                        for(int i2 = 0; i2 < nonMines; i2++){
                            field[i2][0] = '.';
                        }
                        break;
                    case 2:
                        if(nonMines == 1){
                        }else if(nonMines == 2){
                            if(m == 0){
                                field[0][0] = '.';
                                field[0][1] = '.';
                            }else{
                                cout << "Impossible" << endl;
                                continue;
                            }
                        }else if(nonMines % 2){
                            cout << "Impossible" << endl;
                            continue;
                        }else{
                            for(int i2 = 0; i2 < nonMines/2; i2++){
                                field[i2][0] = '.';
                                field[i2][1] = '.';
                            }
                        }
                        break;
                    default:
                        if(nonMines == 1){
                        }else if(nonMines < 4){
                            cout << "Impossible" << endl;
                            continue;
                        }else if(nonMines == 4){
                            field[0][0] = '.'; field[0][1] = '.';
                            field[1][0] = '.'; field[1][1] = '.';
                        }else if(nonMines == 5){
                            cout << "Impossible" << endl;
                            continue;
                        }else if(nonMines == 6){
                            field[0][0] = '.'; field[0][1] = '.'; field[0][2] = '.'; 
                            field[1][0] = '.'; field[1][1] = '.'; field[1][2] = '.'; 
                        }else if(nonMines == 7){
                            cout << "Impossible" << endl;
                            continue;
                        }else if(nonMines == 8){
                            field[0][0] = '.'; field[0][1] = '.'; field[0][2] = '.'; 
                            field[1][0] = '.'; field[1][1] = '.'; field[1][2] = '.'; 
                            field[2][0] = '.'; field[2][1] = '.';
                        }else{
                            if(nonMines < 3 * c){
                                int lastCol = nonMines / 3;
                                for(int i2 = 0; i2 < lastCol; i2++){
                                    field[0][i2] = '.';
                                    field[1][i2] = '.';
                                    field[2][i2] = '.';
                                }
                                int nonMinesLeft = nonMines - (lastCol)*3;
                                if(nonMinesLeft == 1){
                                    field[0][lastCol] = '.';
                                    field[1][lastCol] = '.';
                                    field[2][lastCol-1] = '*';
                                }else if(nonMinesLeft == 2){
                                    field[0][lastCol] = '.';
                                    field[1][lastCol] = '.';
                                }else{
                                    assert(nonMinesLeft == 0);
                                }
                            }else{
                                int lastRow = nonMines / c;
                                for(int i2 = 0; i2 < lastRow; i2++){
                                    for(int i3 = 0; i3 < c; i3++){
                                        field[i2][i3] = '.';
                                    }
                                }
                                int nonMinesLeft = nonMines - (lastRow)*c;
                                if(nonMinesLeft == 1){
                                    field[lastRow - 1][c-1] = '*';
                                    field[lastRow][0] = '.'; field[lastRow][1] = '.';
                                }else{
                                    for(int i2 = 0; i2 < nonMinesLeft; i2++){
                                        field[lastRow][i2] = '.';
                                    }
                                }
                            }
                        }
                        break;
                }
                break;
        }
        field[0][0] = 'c';
        if(true){
            for(auto &it1 : field){
                for(auto &it2 : it1)
                    cout << it2;
                cout << endl;
            }
        }
    }
}
