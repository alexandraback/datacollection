
#include<iostream>
#include<map>
#include<fstream>
using namespace std;

static const int Rank = 4;

string checkStatus(char game[][Rank])
{
    bool hasDot = false;
    // check row
    for (int i=0; i<Rank; i++) {
        bool x = false;
        bool o = false;
        for (int j=0; j<Rank; j++) {
            if (game[i][j]=='X')
                x = true;
            else if (game[i][j]=='O')
                o = true;
            else if (game[i][j]=='.') {
                x = o = false;
                hasDot = true;
                break;
            }
        }
        if (x!=o)
            return x==true ? "X won" : "O won";
    }

    // check column
    for (int i=0; i<Rank; i++) {
        bool x = false;
        bool o = false;
        for (int j=0; j<Rank; j++) {
            if (game[j][i]=='X')
                x = true;
            else if (game[j][i]=='O')
                o = true;
            else if (game[j][i]=='.') {
                x = o = false;
                hasDot = true;
                break;
            }
        }
        if (x!=o)
            return x==true ? "X won" : "O won";
    }

    // check diag
    {
        bool x = false;
        bool o = false;
        for (int j=0; j<Rank; j++) {
            if (game[j][j]=='X')
                x = true;
            else if (game[j][j]=='O')
                o = true;
            else if (game[j][j]=='.') {
                x = o = false;
                hasDot = true;
                break;
            }
        }
        if (x!=o)
            return x==true ? "X won" : "O won";
    }
    {
        bool x = false;
        bool o = false;
        for (int j=0; j<Rank; j++) {
            if (game[j][Rank-1-j]=='X')
                x = true;
            else if (game[j][Rank-1-j]=='O')
                o = true;
            else if (game[j][Rank-1-j]=='.') {
                x = o = false;
                hasDot = true;
                break;
            }
        }
        if (x!=o)
            return x==true ? "X won" : "O won";
    }

    return hasDot? "Game has not completed" : "Draw";
}
 

int main(){

    ifstream infile("file.in");
    ofstream outfile("file.out");

    int t;
    infile>>t;

    for(int i=0;i<t;i++){
        char game[Rank][Rank];
        
        for (int j=0; j<Rank; j++) {
            for (int k=0; k<Rank; k++)
                infile >> game[j][k];
        }

        string ret = checkStatus(game);

        outfile<<"Case #"<<i+1<<": "<<ret<<endl;
    }

}
    
