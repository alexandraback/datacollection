#include<bits/stdc++.h>
using namespace std;

int t;
int x, r, c;

int main(){
    ifstream in;
    ofstream out;

    in.open("D-large.in");
    out.open("Ominous Omino.txt");

    in >> t;
    for (int tc=1; tc<=t; tc++){
        in >> x >> r >> c;
        bool bisa = true;

        if (x >= 7) bisa = false;
        else if (r * c % x) bisa = false;
        else if (x == 2 && (min(r, c) < 1 || max(r, c) < 2)) bisa = false;
        else if (x == 3 && (min(r, c) < 2 || max(r, c) < 3)) bisa = false;
        else if (x == 4 && (min(r, c) < 3 || max(r, c) < 4)) bisa = false;
        else if (x == 5 && (min(r, c) < 3 || max(r, c) < 5)) bisa = false;
        else if (x == 6 && (min(r, c) < 4 || max(r, c) < 6)) bisa = false;

        out << "Case #" << tc << ": ";
        if (!bisa) out << "RICHARD" << endl;
        else out << "GABRIEL" << endl;
    }

    in.close();
    out.close();
    return 0;
}
