#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("b-large.out");

    int T;
    fin >> T;
    //cin >> T;

    for (int i=1; i<=T; i++) {
        string pancake;
        fin >> pancake;
        //cin >> pancake;
        int flips = 0;

        for (int idx=0; idx<pancake.size()-1; idx++) {
            if (pancake[idx] != pancake[idx+1]) flips++;
        }
        if (pancake[pancake.size()-1] == '-') flips++;

        fout << "Case #" << i << ": " << flips << "\n";
        //cout << "Case #" << i << ": " << flips << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
