#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream fin("Q3.in");
    ofstream fout("Q3.out");
    
    int T;
    int R, C, M;
    int S;
    fin >> T; fin.ignore();
    for(int i = 0; i < T; i++){
        fout << "Case #" << i+1 << ":" << endl;
        fin >> R; fin.ignore();
        fin >> C; fin.ignore();
        fin >> M; fin.ignore();
        S = (R*C - M);
        
        int top, side;
        //corner cases
        if(R == 1){ //one row
            for(int j = 0; j < C; j++){
                if(j == 0) fout << "c";
                else if(j < S) fout << ".";
                else fout << "*";
            }
            fout << endl;
            continue;
        } else if(C == 1){ //one column
            for(int j = 0; j < R; j++){
                if(j == 0) fout << "c" << endl;
                else if(j < S) fout << "." << endl;
                else fout << "*" << endl;
            }
            continue;
        } else if(S == 1){ //one space
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    if(j == 0 && k == 0) fout << "c";
                    else fout << "*";
                }
                fout << endl;
            }
            continue;
        }
        else if(S < 4){
            fout << "Impossible" << endl;
            continue;
        }
        
        else if(S < 8 && S%2 == 1){
            fout << "Impossible" << endl;
            continue;
        }
        
        //two wide and odd mines
        else if((R == 2 || C == 2) && S%2 == 1){   
            fout << "Impossible" << endl;
            continue;
        }
        
        //two wide and even mines
        else if(R == 2){
            int t = S/2;
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    if(j == 0 && k == 0) fout << "c";
                    else if(k < t) fout << ".";
                    else fout << "*";
                }
                fout << endl;
            }
        }
        
        else if (C== 2){
            int t = S/2;
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    if(j == 0 && k == 0) fout << "c";
                    else if(j < t) fout << ".";
                    else fout << "*";
                }
                fout << endl;
            }
        }
        //not enough to fill two edges
        else if(S < 2*(R+C) - 4){
            int t = S;
            t = t - 8 - t%2; //only edge spaces left now
            t /= 2; //and we're filling them two at a time
            top = t+3, side = 0;
            if(t > (C-3)){
                top = C;
                side = t - C + 6;
            }
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    if(j < 2 && k < 2){
                        if(j == 0 && k == 0) fout << "c";
                        else fout << ".";
                    }
                    else if(j < 3 && k < 2){
                        if(S >= 6) fout << ".";
                        else fout << "*";
                    }
                    else if(j < 2 && k < 3){
                        if(S >= 8) fout << ".";
                        else fout << "*";
                    }
                    else if(j == 2 && k == 2){
                        if(S >= 9 && S%2 == 1) fout << ".";
                        else fout << "*";
                    }
                    //greater than 9 spaces
                    else if(S > 9){
                        if(j < 2 && k < top) fout << ".";
                        else if(j < side && k < 2) fout << ".";
                        else fout << "*";
                    }
                    else{
                        fout << "*";
                    }
                }
                fout << endl;
            }
            continue;
        }
        
        //fill both edges + add to center
        else if(S >= 2*(R+C) - 4){
            int F = 2*(R+C)-4;
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    if(j < 2 || k < 2){
                        if(j == 0 && k == 0) fout << "c";
                        else fout << ".";
                        //F++;
                    }
                    else if(F < S){
                        fout << ".";
                        F++;
                    }
                    else{
                        fout << "*";
                    }
                }
                fout << endl;
            }
            continue;
        }
    }
    return 0;
}
    
