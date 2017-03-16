#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(void){
    //ifstream fin("C-large.in");
    //ifstream fin("Cex.in");
    //ofstream fout("csL.txt");

    int T;
    cin >> T;
/*
    string st;
    getline(fin,st);
    stringstream ss(st);
    ss >> T;
*/
    //cout << T << endl;
    for(int t = 0 ; t < T ; t++){
        int M,R,C;
        string Ms,Rs,Cs;
        bool sol = true;
        cin >> R >> C >> M;
/*
        fin >> Rs >> Cs >> Ms;
        //cout << Rs << " " << Cs " " << Ms << endl;
        ss.str(Ms);
        ss.clear();
        ss >> M;
        ss.str(Rs);
        ss.clear();
        ss >> R;
        ss.str(Cs);
        ss.clear();
        ss >> C;
*/
        //cout << R << " " << C << " " << M << endl;

        int space = R*C - M;
        if(space < 9){
            if(space < 4)
                sol = false;
            if(space % 2 !=0)
                sol = false;
            if(!sol){
                if(space == 1)
                    sol = true;
                if(R == 1 || C == 1)
                    sol = true;
            }
        }
        else if(R < 3 || C < 3){
            if(!(R == 1 || C == 1)){
                if(space %2 != 0)
                    sol = false;
            }
        }



        cout << "Case #" << t+1 << ":\n";
        //fout << "Case #" << t+1 << ":\n";

        //fout << R << " " << C << " " << M << endl;

        if(sol){
            char **board = new char*[R];
            for(int i = 0 ; i < R ; i++)
                board[i] = new char[C];
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C ; j++){
                    board[i][j] = '*';
                    if(M == 0)
                        board[i][j] = '.';
                }
            }
            board[0][0] = 'c';
            space -= 1;
            if(space > 0){
                if(R == 1){
                    for(int j = 1 ; j < C ; j++){
                        board[0][j] = '.';
                        space -= 1;
                        if(space == 0)
                            break;
                    }
                }
                else if(C == 1){
                    for(int i = 1 ; i < R ; i++){
                        board[i][0] = '.';
                        space -= 1;
                        if(space == 0)
                            break;
                    }
                }
                else if(C == 2){
                    for(int i = 0 ; space > 0 ; i++){
                        board[i][0]= '.';
                        board[i][1]= '.';
                        space -= 2;
                    }
                }
                else if(R == 2){
                    for(int i = 0 ; space > 0 ; i++){
                        board[0][i]= '.';
                        board[1][i]= '.';
                        space -= 2;
                    }
                }
                else if(R >= 3 && C >= 3){
                    int c=0,p=0;
                    bool x = false;
                    while(space > 0){
                        x = !x;
                        if(x){
                            c = p+1;
                            if(c == R){
                                //p = c;
                                continue;
                            }
                            p = 0;
                        }
                        else{
                            p = c;
                            c = 0;
                        }
                        while(space > 0){
                            if(c < R &&  p < C){
                                board[c][p] = '.';
                                space -= 1;
                                if(space == 0)
                                    break;
                            }
                            else if(c < R){
                                if(x){
                                    break;
                                }
                            }
                            else if(p < C){
                                if(!x){
                                    break;
                                }
                            }
                            if(!x){
                                c += 1;
                                if(c > p)
                                    break;
                            }
                            else{
                                p+=1;
                                if(c == p)
                                    break;
                            }
                        }
                    }
                    //cout << c << " " << p << endl;
                    if(c == 0){
                        board[c+1][p] = '.';
                        int L = p;
                        if(p > R-1)
                            L = R-1;
                        //cout << "modi " << R-1 << " "  << L << " " << p-1 << endl;
                        board[L][p-1] = '*';
                    }
                    else if(p == 0){
                        board[c][p+1] = '.';
                        int L = c-1;//(c-1) > (R-1) ? R-1 : c-1;
                        if(c-1 > C-1)
                            L = C-1;
                        board[c-1][L] = '*';
                    }
                }
            }
            board[0][0] = 'c';
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C ; j++){
                    cout << board[i][j];
                    //fout << board[i][j];
                }
                cout << "\n";
                //fout << "\n";
            }
            for(int i = 0 ; i < R ; i++)
                delete[] board[i];
            delete[] board;
        }
        else{
            cout << "Impossible\n";
            //fout << "Impossible\n";
        }


    }
/*
    fin.close();
    fout.close();
*/
    return 0;
}
