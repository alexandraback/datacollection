// Project: Google Code Jam 2014: Minesweeper
// Author:  Kévin Moisy-Mabille
// Date:    2014/04/12

#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char ** argv){
    if (argc != 2)
        cout << "usage: ./Minesweeper input.txt" << endl;

    ifstream fichier(argv[1], ios::in);
    if (fichier){
        int T;
        fichier >> T;
        for (int i=1; i<=T; i++){
            cout << "Case #" << i << ":" << endl;
            int R, C, M, safe;
            fichier >> R >> C >> M;
            safe = R*C-M;
            if (safe == 1){
                cout << "c";
                for (int k=1; k<C; k++)
                    cout << "*";
                cout << endl;
                for (int j=1; j<R; j++){
                    for (int k=0; k<C; k++)
                        cout << "*";
                    cout << endl;
                }
            } else if (R==1){
                cout << "c";
                for (int k=1; k<safe; k++)
                    cout << ".";
                for (int k=0; k<C-safe; k++)
                    cout << "*";
                cout << endl;
            } else if (C==1){
                cout << "c" << endl;
                for (int k=1; k<safe; k++)
                    cout << "." << endl;
                for (int k=0; k<R-safe; k++)
                    cout << "*" << endl;
            } else if (safe < 4){
                cout << "Impossible" << endl;
            } else if (R==2){
                if (safe % 2 == 1)
                    cout << "Impossible" << endl;
                else {
                    cout << "c";
                    for (int k=1; k<safe/2; k++)
                        cout << ".";
                    for (int k=0; k<C-safe/2; k++)
                        cout << "*";
                    cout << endl;
                    for (int k=0; k<safe/2; k++)
                        cout << ".";
                    for (int k=0; k<C-safe/2; k++)
                        cout << "*";
                    cout << endl;
                }
           } else if (C==2){
                if (safe % 2 == 1)
                    cout << "Impossible" << endl;
                else {
                    cout << "c." << endl;
                    for (int k=1; k<safe/2; k++)
                        cout << ".." << endl;
                    for (int k=0; k<R-safe/2; k++)
                        cout << "**" << endl;
                }
            } else if (safe == 7 || safe == 5){
                cout << "Impossible" << endl;
            } else {
                cout << "c";
                if ((safe <= C*2+1) && (safe % 2 == 1)){
                   for (int k=1; k<(safe-3)/2; k++)
                        cout << ".";
                    for (int k=0; k<C-(safe-3)/2; k++)
                        cout << "*";
                    cout << endl;
                    for (int k=0; k<(safe-3)/2; k++)
                        cout << ".";
                    for (int k=0; k<C-(safe-3)/2; k++)
                        cout << "*";
                    cout << endl << "..." ;
                    for (int k=0; k<C-3; k++)
                        cout << "*";
                    cout << endl;
                    for (int j=3; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else if ((safe <= C*2) && (safe % 2 == 0)){
                    for (int k=1; k<safe/2; k++)
                        cout << ".";
                    for (int k=0; k<C-safe/2; k++)
                        cout << "*";
                    cout << endl;
                    for (int k=0; k<safe/2; k++)
                        cout << ".";
                    for (int k=0; k<C-safe/2; k++)
                        cout << "*";
                    cout << endl;
                    for (int j=2; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else if ((safe % 3 == 1) && C==3){
                    cout << ".." << endl;
                    for (int j=1; j<safe/C-1; j++){
                        cout << "..." << endl;
                    }
                    cout << "..*" << endl << "..*" << endl;
                    for (int j=safe/C+1; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else if ((safe == C*3+1) && (C==4)){
                    cout << "..." << endl << "...." << endl << "...*" << endl << "..**" << endl;
                    for (int j=4; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else if (safe == C*3+1){
                    for (int k=1; k<C-1; k++)
                        cout << ".";
                    cout << "*" << endl;
                    for (int j=1; j<3; j++){
                        for (int k=0; k<C-1; k++)
                            cout << ".";
                        cout << "*" << endl;
                    }
                    cout << "...." ;
                    for (int k=4; k<C; k++)
                        cout << "*";
                    cout << endl;
                    for (int j=4; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else if (safe % C == 1){
                    for (int k=1; k<C-2; k++)
                        cout << ".";
                    cout << "**" << endl;
                    for (int j=1; j<safe/C; j++){
                        for (int k=0; k<C; k++)
                            cout << ".";
                        cout << endl;
                    }
                    cout << "..." ;
                    for (int k=0; k<C-3; k++)
                        cout << "*";
                    cout << endl;
                    for (int j=safe/C+1; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else if (safe % C == 0){
                    for (int k=1; k<C; k++)
                        cout << ".";
                    cout << endl;
                    for (int j=1; j<safe/C; j++){
                        for (int k=0; k<C; k++)
                            cout << ".";
                        cout << endl;
                    }
                    for (int j=safe/C; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                } else {
                    for (int k=1; k<C; k++)
                        cout << ".";
                    cout << endl;
                    for (int j=1; j<safe/C; j++){
                        for (int k=0; k<C; k++)
                            cout << ".";
                        cout << endl;
                    }
                    for (int k=0; k<safe%C; k++)
                        cout << ".";
                    for (int k=safe%C; k<C; k++)
                        cout << "*";
                    cout << endl;
                    for (int j=safe/C+1; j<R; j++){
                        for (int k=0; k<C; k++)
                            cout << "*";
                        cout << endl;
                    }
                }
            }
        }
        fichier.close();
    } else 
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}


