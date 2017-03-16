#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("D-large.in");
ofstream fout("largeD.out");

string calc(){
    int X, R, C;
    fin >> X >> R >> C;
    if(X >= 7 || R * C % X != 0){
        return "RICHARD";
    }

    int k = min(R, C);
    int l = max(R, C);

    switch(X){
    case 1:
    case 2:
        return "GABRIEL";
    case 3:
        if(k >= 2)
            return "GABRIEL";
        else
            return "RICHARD";

    case 4:
        if(k >= 3)
            return "GABRIEL";
        else
            return "RICHARD";
    case 5:
        if(k >= 4 || (k == 3 && l >= 10))
            return "GABRIEL";
        else
            return "RICHARD";
    case 6:
        if(k >= 4)
            return "GABRIEL";
        else
            return "RICHARD";
    }

}


int main()
{
    int T;
    fin >> T;
    for(int C = 1; C <= T; ++C){
        fout << "Case #" << C << ": " << calc() << endl;
    }
    return 0;
}
