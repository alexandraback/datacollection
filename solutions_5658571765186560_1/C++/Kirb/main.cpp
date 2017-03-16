#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main(int p_Argc, char  **p_Argv)
{
    int T, X, R, C;
    string s;
	fstream input("large.txt");
	ofstream output("titi.txt");
	input >> T;

    for (int l=0;l<T;l++){
            input >> X >> R >> C;
            output << "Case #" << l+1 << ": " ;

            switch (X){
                case 1: output << "GABRIEL" << endl; break;
                case 2: output << ( (R*C)%2 == 0 ? "GABRIEL" : "RICHARD" ) << endl; break;
                case 3: output << ( ((R*C)%3 == 0 && (R>=2)  && (C>= 2)  ) ? "GABRIEL" : "RICHARD" ) << endl; break;
                case 4: output << ( ((R*C)%4 == 0 && (R > 2) && (C > 2)  ) ? "GABRIEL" : "RICHARD" ) << endl; break;
                case 5: output << ( ((R*C)%5 == 0 && ( (R >= 4 && C >= 4) || (R==3 && C==5) || ( C==5 && R ==3))  ) ? "GABRIEL" : "RICHARD" ) << endl; break;
                case 6: output << ( ((R*C)%6 == 0 && (R >= 4) && (C >= 4)  ) ? "GABRIEL" : "RICHARD" ) << endl; break;
                default: output << "RICHARD" << endl; break;
            }
    }
    return 0;

}





