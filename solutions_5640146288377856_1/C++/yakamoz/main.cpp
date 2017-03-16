#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    ifstream cin2;
    ofstream cout2;
    string filename = "input.txt";
    cin2.open( filename.c_str() );
    filename = "output.txt";
    cout2.open( filename.c_str() );
    /////////////////////
    int t;
    int R,C,W;
    cin2>>t;
    int cases = 1;
    int res;
    while(t--){
        cout2<<"Case #"<<cases<<": ";
        cin2>>R>>C>>W;
        res = 0;
        if(W==C){
            res = C;
            res+=(R-1);
            cout2<<res;
        }else if(W==1){
            cout2<<R*C;
        }else{
            if(C<W*2){
                res = R-1;
                res +=W;
                res++;
            }else{
                res = R*(C/W);
                res = res+W-1;
                if(C%W!=0)
                    res++;
            }
            cout2<<res;
        }
        cout2<<endl;
        cases++;
    }





    ////////////////////////////
    cin2.close();
    cout2.close();
    return 0;
}
