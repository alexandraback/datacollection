#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// c   .  *
// 0 else 2

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    _of.precision(7);
    _of.setf( ios::fixed, ios::floatfield );
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        _of << "Case #" << i+1 << ":" << endl;
        int r,c,m;
        _if >> r >> c >> m;

        int curr_row = 0;
        int curr_col = 0;

        int mat[r][c];

        int not_mine = r*c - m;
        int bounding_sq = sqrt(not_mine);

        for(int j=0;j<r;j++)
            for(int k=0;k<c;k++)
                mat[j][k] = 2;

        bool isImpossible = false;

        if(r > bounding_sq && c > bounding_sq){
            if(not_mine < 8 && (not_mine == 2 || not_mine == 3 || not_mine == 5 || not_mine == 7)){
                _of << "Impossible" << endl;
                continue;
            }
            for(int j=0;j<bounding_sq;j++)
                for(int k=0;k<bounding_sq;k++)
                    mat[j][k] = 1;
            int rest = not_mine - bounding_sq*bounding_sq;
            for(int j=0;j<rest && j<bounding_sq;j++)
                mat[bounding_sq][j] = 1;
            if(rest == 1){
                mat[bounding_sq][1] = 1;
                mat[bounding_sq-1][bounding_sq-1] = 2;
            }
            else{
                rest -= (bounding_sq);
                for(int j=0;j<rest && j<bounding_sq;j++)
                    mat[j][bounding_sq] = 1;
                if(rest == 1){
                    mat[1][bounding_sq] = 1;
                    mat[bounding_sq][bounding_sq-1] = 2;
                }
            }

            mat[0][0] = 0;

            /*/// YAZDIRMA KISMISI
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    switch(mat[j][k]){
                    case 0:
                        cout << "C";
                        break;
                    case 2:
                        cout << "*";
                        break;
                    default:
                        cout << ".";
                        break;
                    }
                }
                cout << endl;
            }
            cout << endl;*/
        }
        else if(r > bounding_sq){
            int _r = not_mine / c;
            for(int j=0;j<_r;j++)
                for(int k=0;k<c;k++)
                    mat[j][k] = 1;
            int rest = not_mine - _r*c;
            for(int j=0;j<rest;j++)
                mat[_r][j] = 1;
            mat[0][0] = 0;

            if(rest == 1){
                if (c==2){
                    _of << "Impossible" << endl;
                    continue;
                }
                mat[_r][1] = 1;
                mat[_r-1][c-1] = 2;
            }

            /*/// YAZDIRMA KISMISI
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    switch(mat[j][k]){
                    case 0:
                        cout << "C";
                        break;
                    case 2:
                        cout << "*";
                        break;
                    default:
                        cout << ".";
                        break;
                    }
                }
                cout << endl;
            }
            cout << endl;*/
        }
        else if(c > bounding_sq){
            int _c = not_mine / r;
            for(int j=0;j<r;j++)
                for(int k=0;k<_c;k++)
                    mat[j][k] = 1;
            int rest = not_mine - r*_c;
            for(int j=0;j<rest;j++)
                mat[j][_c] = 1;
            mat[0][0] = 0;

            if(rest == 1){
                if (r==2){
                    _of << "Impossible" << endl;
                    continue;
                }
                mat[1][_c] = 1;
                mat[r-1][_c-1] = 2;
            }

            /*/// YAZDIRMA KISMISI
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    switch(mat[j][k]){
                    case 0:
                        cout << "C";
                        break;
                    case 2:
                        cout << "*";
                        break;
                    default:
                        cout << ".";
                        break;
                    }
                }
                cout << endl;
            }
            cout << endl;*/
        }
        else if(m == 0){
            for(int j=0;j<r;j++)
                for(int k=0;k<c;k++)
                    mat[j][k] = 1;
            mat[0][0] = 0;
        }
        else cout << "HATAAAA!!!! : " << i+1 << endl;


        /// YAZDIRMA KISMISI
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                switch(mat[j][k]){
                case 0:
                    _of << "c";
                    break;
                case 2:
                    _of << "*";
                    break;
                default:
                    _of << ".";
                    break;
                }
            }
            _of << endl;
        }
    }
}

