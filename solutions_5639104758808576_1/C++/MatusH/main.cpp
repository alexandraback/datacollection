#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream in ("A-large.in");
    ofstream out ("output.out");
    string line;
    int T, stand, need, s_max, s;

    if(in.is_open()){
        in >> T;
        for (int i = 1; i <= T; i++){
            stand = 0;
            need = 0;
            in >> s_max >> line;
            for (int j = 0; j <= s_max; j++){
                s = line[j]-'0';
                if (stand < j){
                    need += j - stand;
                    stand = j + s;
                }
                else{
                    stand += s;
                }
            }
            out << "Case #" << i << ": " << need << endl;
        }
        in.close();
    }
    return 0;
}

