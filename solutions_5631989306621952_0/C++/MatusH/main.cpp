#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

string howMany(string S){
    string result = "";
    result += S[0];

    for (unsigned int i = 1; i < S.length(); i++) {
        if (result[0] > S[i])
            result += S[i];
        else
            result = S[i] + result;
    }

    return result;
}


int main()
{
    ifstream in ("A-mine.in");
    ofstream out ("output.out");
    string S;
    unsigned long long int T;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (unsigned int i = 1; i <= T; i++){
            in >> S;
            out << "Case #" << i << ": " << howMany(S) << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}
