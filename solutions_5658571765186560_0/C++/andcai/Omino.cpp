#include <fstream>

using namespace std;

int main(){
    ifstream fin ("inputD.txt");
    ofstream fout ("outputD.txt");
    int T, X, R, C;
    fin >> T;
    for(int i = 1; i <= T; i++){
        fin >> X >> R >> C;
        if(X>=7 || (R*C)%X!=0 || (X>R&&X>C) || X>=3&&(R==1||C==1) || X>=4&&(R==2||C==2) || X==6&&(R==3||C==3)){
            fout << "Case #" << i << ": RICHARD\n";
        }else{
            fout << "Case #" << i << ": GABRIEL\n";
        }
    }
}
