#include <list>
#include <queue>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        cout << "Usage : "<<argv[0] <<" test.in test.out";
        return 0;
    }
    cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;

    ifstream in(argv[1]);
    if(!in.is_open()) {
        cout << "Failed to open " << argv[1] << endl;
        return 0;
    }

    ofstream out(argv[2]);
    if(!out.is_open()) {
        cout << "Failed to open " << argv[2] << endl;
        return 0;
    }

    int T;
    in >> T;
    for(int i = 0; i < T; ++i)
    {
        int B;
        in >> B;

        unsigned long long M;
        in >> M;

        cout << "Solving case : " << i<<endl;
        out << "Case #" << i+1 << ": ";
        unsigned long long Max = 1;
        Max <<= (B-2);
        if(Max < M) {out << "IMPOSSIBLE\n"; continue; }
        out << "POSSIBLE\n";

        bool** arr = new bool*[B];
        for(int k = 0; k < B; ++k)
        {
            arr[k] = new bool[B];
            for(int l = 0; l < B; ++l)
                arr[k][l] = false;
        }

        int highestBit = 1;
        unsigned long long mm = M;
        while(mm >>= 1) ++highestBit;

        unsigned long long num = 0;
        if(highestBit > 1)
            num <<= highestBit;
        else if(highestBit == 1)
            num = 1;

        cout <<"New num = "<< num << endl;
        cout <<"Highest bit = " << highestBit << endl;

        for(int k = 0; k < B; ++k)
            if( M & (1<<k))
                arr[0][B-2-k] = true;

        for(int k = B-1-highestBit; k < B-1; ++k)
        {
            for(int l = k+1; l < B; ++l)
                arr[k][l] = true;
        }

        for(int k = 0; k < B; ++k)
        {
            for(int l = 0; l < B; ++l)
                out << ( (k!=l and arr[k][l]) ? '1':'0');
            out << endl;
        }
    }
    return 0;
}





