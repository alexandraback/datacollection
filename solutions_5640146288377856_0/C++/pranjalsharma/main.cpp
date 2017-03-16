#include <iostream>
#include <fstream>

using namespace std;

//fout<<"Case #"<<i+1<<": "<< answer <<"\n";

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("output.txt");

    int t, r, c, w, n, x;
    fin >> t;

    for(int i = 0; i < t; i++){
        fin >> r >> c >> w;
        x = (int)(c/w);
        n = r*x;
        if((c%w)) n++;
        n += (w-1);
        fout<<"Case #"<<i+1<<": "<< n <<"\n";
    }

    return 0;
}
